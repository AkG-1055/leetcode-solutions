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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> freq(100001, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]] = 1;
        }

        ListNode* curr = head;
        ListNode* prev = head;

        while (curr != NULL) {
            int value = curr -> val;
            if (freq[value] == 1) {
                if (curr == head) {
                    curr = head -> next;
                    prev = head -> next;
                    head -> next = nullptr;
                    head = curr;
                }
                else{
                    prev -> next = curr -> next;
                    curr -> next = nullptr;
                    curr = prev -> next;
                }
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }

        return head;
    }
};