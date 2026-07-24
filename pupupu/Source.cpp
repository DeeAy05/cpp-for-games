#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
int countList(ListNode* l, int count = 0) {
    while (l->next != nullptr) {
        return ++count + countList(l->next);
    }
    return ++count;

}

const char* readList(ListNode* l, const char* c = nullptr) {

    while (l->next != nullptr) {
        c = (const char*)l->val;
        return readList(l->next);
    }
    return c;
}

int main() {
    ListNode* l1_4 = new ListNode(1);
    ListNode* l1_3 = new ListNode(1, l1_4);
    ListNode* l1_2 = new ListNode(3, l1_3);
    ListNode* l1_1 = new ListNode(2, l1_2);

    std::cout << readList(l1_4);

	return 0;
}