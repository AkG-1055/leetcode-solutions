/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        if (head == nullptr){
            return nullptr;
        }

        while (ptr2 != nullptr && ptr2 -> next != nullptr){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;

            if (ptr2 == ptr1){
                break;
            }
        }
        if (ptr2 == nullptr || ptr2 -> next == nullptr){
            return nullptr;
        }

        ListNode* temp = head;

        while (temp != ptr1){
            temp = temp -> next;
            ptr1 = ptr1 -> next;
        }

        return temp;
    }
};