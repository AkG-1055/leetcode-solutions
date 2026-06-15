/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;

        while (curr != nullptr){
            if (curr -> val == val){
                temp -> next = curr -> next;
                curr -> next = nullptr;
                curr = temp -> next;
            }
            else{
                temp = curr;
                curr = curr -> next;
            }
        }

        return dummy -> next;
    }
};