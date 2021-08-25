#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int x, y; // 좌표
	int data; // 노드 번호
	Node* left = NULL; // 왼쪽 자식
	Node* right = NULL; // 오른쪽 자식
};

bool cmp(Node a, Node b) { // 루트 트리부터 좌측에서 우측으로 내려오기 위함
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

void makeTree(Node* parent, Node* child) {
	if (parent->x < child->x) {
		if (parent->right == NULL)
			parent->right = child;
		else
			makeTree(parent->right, child);
	} else {
		if (parent->left == NULL)
			parent->left = child;
		else
			makeTree(parent->left, child);
	}
}

vector<int> ans_pre;
void preorder(Node* node) { // 전위 순회
	if (node == NULL) return;
	ans_pre.push_back(node->data);
	preorder(node->left);
	preorder(node->right);
}

vector<int> ans_post;
void postorder(Node* node) { // 후위 순회
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	ans_post.push_back(node->data);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	vector<Node> nodes;
	for (int i = 0; i < nodeinfo.size(); i++) {
		Node tmp;
		tmp.x = nodeinfo[i][0];
		tmp.y = nodeinfo[i][1];
		tmp.data = i + 1;
		nodes.push_back(tmp);
	}
	sort(nodes.begin(), nodes.end(), cmp);

	for (int i = 1; i < nodes.size(); i++)
		makeTree(&nodes[0], &nodes[i]);

	preorder(&nodes[0]);
	postorder(&nodes[0]);
	answer.push_back(ans_pre);
	answer.push_back(ans_post);

	return answer;
}

int main()
{
	cout << "nodeinfo \t\t\t\t\t\t\tresult" << endl;
	vector<vector<int>> ans = solution({ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
	cout << "[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]] \t[[" << ans[0][0];
	for (int i = 1; i < ans[0].size(); i++)
		cout << "," << ans[0][i];
	cout << "],[" << ans[1][0];
	for (int i = 1; i < ans[1].size(); i++)
		cout << "," << ans[1][i];
	cout << "]]" << endl;

	return 0;
}