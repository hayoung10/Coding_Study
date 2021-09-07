#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Trie {
    bool finish = false;
    int count = 0; // 자식 수
    Trie* node[26];

    Trie() {
        for (int i = 0; i < 26; i++) node[i] = NULL;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (node[i] != NULL) node[i] = NULL;
    }

    void insert(const char* key) {
        this->count++;
        if (*key == NULL) {
            this->finish = true;
            return;
        }

        int cur = *key - 'a';
        if (node[cur] == NULL)
            node[cur] = new Trie();
        node[cur]->insert(key + 1);
    }

    int find(const char* key, int cnt) {
        if (this->count == 1 || *key == NULL) return cnt;

        int cur = *key - 'a';
        return node[cur]->find(key + 1, cnt + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    sort(words.begin(), words.end()); // 사전식 정렬

    Trie* root = new Trie();
    for (auto word : words)
        root->insert(word.c_str());

    for (auto word : words)
        answer += root->find(word.c_str(), 0);

    return answer;
}

int main()
{
    cout << "words \t\t\t\t\tresult" << endl;
    cout << "[\"go\",\"gone\",\"guild\"] \t\t\t" << solution({ "go","gone","guild" }) << endl;
    cout << "[\"abc\",\"def\",\"ghi\",\"jklm\"] \t\t" << solution({ "abc","def","ghi","jklm" }) << endl;
    cout << "[\"word\",\"war\",\"warrior\",\"world\"] \t" << solution({ "word","war","warrior","world" }) << endl;

    return 0;
}