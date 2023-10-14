#include<iostream>

using namespace std;
//Definition for singly - linked list.
 struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

int main() {
	ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
	int x = 3;
	/*ListNode* h2 = new ListNode(0, head);
	ListNode* n = head, * q = h2, * l = n;
	while (n != nullptr) {
		if (n->val < x ) {
			if (n == q->next)
			{
				q = n;
				n = n->next;
				l = n;
				continue;
			}
			l->next = n->next;
			n->next = q->next;
			q->next = n;
			n = l->next;
			q = q->next;
			continue;
		}
		l = n;
		n = n->next;
	}*/
	ListNode* before_head = new ListNode(0);
	ListNode* after_head = new ListNode(0);
	ListNode* n = head, * before = before_head, * after = after_head;
	while (n != nullptr) {
		if (n->val < x) {
			before->next = n;
			before = before->next;
		}
		else {
			
			after->next = n;

			after = after->next;
		}
		n = n->next;

	}
	before->next = after_head->next;
	after->next = nullptr;
	cout << "";
	return 0;
}