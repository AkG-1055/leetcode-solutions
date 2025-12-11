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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        if(ptr2->next == nullptr){
            delete head;
            return nullptr;
        }

        else{
            for(int i = 0; i < n; i++){
                ptr2 = ptr2->next;
            }

            if (ptr2 == nullptr){
                ListNode* newHead = head->next;
                delete head;
                return newHead;
            }

            while(ptr2->next != nullptr){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            ListNode* DeleteNode = ptr1->next;

            if(DeleteNode->next == nullptr){
                ptr1->next = nullptr;
                delete DeleteNode;
            }
            else{
                ptr1->next = DeleteNode->next;
                DeleteNode->next = nullptr;
                delete DeleteNode;
            }

            return head;
        }
    }
};