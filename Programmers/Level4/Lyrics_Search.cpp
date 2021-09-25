#include <iostream>
#include <algorithm> // reverse
#include <cstring> // memset
#include <string>
#include <vector>
using namespace std;

struct Trie {
    bool finish;
    Trie* next[26];
    int count;
    Trie() : finish(false), count(0) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (next[i])
                delete next[i];
        }
    }
    void insert(const char* key) {
        count++;
        if (*key == '\0')
            finish = true;
        else {
            int cur = *key - 'a';
            if (next[cur] == NULL)
                next[cur] = new Trie();
            next[cur]->insert(key + 1);

        }
    }
    int find(const char* key) {
        int cur = *key - 'a';
        if (*key == '?') return count;
        if (next[cur] == NULL) return 0; // 매치되는 단어가 없음
        return next[cur]->find(key + 1);
    }
};

Trie* root[10001]; // 접미사
Trie* rev_root[10001]; // 접두사 -> 뒤집어서 검색

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);

    for (auto& w : words) {
        int size = w.size();

        if (root[size] == NULL)
            root[size] = new Trie();
        root[size]->insert(w.c_str());
        
        reverse(w.begin(), w.end());
        if (rev_root[size] == NULL)
            rev_root[size] = new Trie();
        rev_root[size]->insert(w.c_str());

    }

    int index = 0;
    for (auto& q : queries) { // Trie 생성
        int size = q.size();

        if (q[size - 1] == '?') {
            if (root[size] == NULL) { index++; continue; }
            else answer[index] = root[size]->find(q.c_str());

        } else {
            reverse(q.begin(), q.end());
            if (rev_root[size] == NULL) { index++; continue; }
            else answer[index] = rev_root[size]->find(q.c_str());
        }
        index++;
    }

    return answer;
}

int main()
{
    cout << "words \t\t\t\t\t\t\t\tqueries \t\t\t\t\tresult" << endl;
    cout << "[\"frodo\", \"front\", \"frost\", \"frozen\", \"frame\", \"kakao\"] \t";
    cout << "[\"fro??\", \"????o\", \"fr???\", \"fro???\", \"pro?\"] \t[";
    vector<int> sol = solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "fro??", "????o", "fr???", "fro???", "pro?" });
    for (int i = 0; i < sol.size() - 1; i++)
        cout << sol[i] << ", ";
    cout << sol[sol.size() - 1] << "]" << endl;

    return 0;
}