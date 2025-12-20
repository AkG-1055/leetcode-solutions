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
    bool isPalindrome(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        if (ptr2 == nullptr){
            return true;
        }

        while (ptr2 != nullptr && ptr2 -> next != nullptr){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
        }
        
        ListNode* prev = nullptr;
        ListNode* secondHalf = ptr1;

        while (secondHalf != nullptr){
            ListNode* nextNode = secondHalf -> next;
            secondHalf -> next = prev;
            prev = secondHalf;
            secondHalf = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr){
            if (first -> val == second -> val){
                first = first -> next;
                second = second -> next;
            }
            else{
                return false;
                break;
            }
        }
        return true;
    }
};