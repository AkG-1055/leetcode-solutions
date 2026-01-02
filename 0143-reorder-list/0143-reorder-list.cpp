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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if (head == nullptr){
            return;
        }
        while (fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow -> next;
        slow -> next = nullptr;

        while (curr != nullptr){
            ListNode* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = prev;

        while (ptr2 != nullptr){
            ListNode* temp1 = ptr1 -> next;
            ListNode* temp2 = ptr2 -> next;
            ptr1 -> next = ptr2;
            ptr2 -> next = temp1;
            ptr1 = temp1;
            ptr2 = temp2;
        }
    }
};