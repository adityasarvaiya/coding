/*
class Node {
    public:
	int val;
    Node* next;
    Node* random;


	Node() {}

	Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
#include <bits/stdc++.h>
#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/ds/Node/Node.hpp"

using namespace std;

class CopyLinkedListWithRandomPointer {
public:
	Node* copyLinkedListWithRandomPointer(Node* head) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

		map<Node*, Node*> org_to_copy;
		Node* it_node = head;
		while (it_node) {
			org_to_copy[it_node] = new Node(it_node->val, NULL, NULL);
			it_node = it_node->next;

		}

		it_node = head;
		while (it_node) {
			Node* new_node = org_to_copy[it_node];
			new_node->next = it_node->next ? org_to_copy[it_node->next] : NULL;
			new_node->random = it_node->random ? org_to_copy[it_node->random] : NULL;
			it_node = it_node->next;
		}
		return org_to_copy[head];
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
};

int main() {
	FastIO();
	int x = 0, n, p;
	cin >> n;
	vector<int> list;
	while (x < n) {
		int p;
		cin >> p;
		list.push_back(p);
		x++;
	}

	vector<int> random ;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "null") p = 0;
		else p = stoi(s);
		random.push_back(p);
	}
	Node * head = Node().MakeList(list, random);
	Node * result = CopyLinkedListWithRandomPointer().copyLinkedListWithRandomPointer(head);
	if ( result != NULL) {
		Node().print(result);
	}

	return 0;
}
