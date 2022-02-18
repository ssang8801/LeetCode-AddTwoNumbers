#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode* next) :val(x), next(next) {};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result;
        ListNode* resultPointer = &result;
        int carry = 0;
        std::cout << "Result: " << &result << "\n";
        std::cout << "ResultPotiner: " << resultPointer << "\n\n\n";
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;

            resultPointer->next = new ListNode;
            resultPointer = resultPointer->next;
            resultPointer->val = (sum % 10);
            std::cout << "Result: " << &result << "\n";
            std::cout << "ResultPotiner: " << resultPointer << "\n";
        }

        if (carry) {
            resultPointer->next = new ListNode(carry);
        }

        return result.next;
    }

};

int main() {
    ListNode l1;
    l1.val = 2;
    l1.next = new ListNode(4);
    l1.next->next = new ListNode(3);

    ListNode l2;
    l2.val = 5;
    l2.next = new ListNode(6);
    l2.next->next = new ListNode(4);
    Solution obj;
    ListNode *l3 = obj.addTwoNumbers(&l1, &l2);

    std::cout << l3->val << l3->next->val << l3->next->next->val;



}