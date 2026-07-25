class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(nums[0]);

        for (int i = 1; i < n; i++) {
            if (pq.top() < nums[i]) {
                int curr = pq.top();
                pq.pop();
                pq.push(nums[i]);
                pq.push(curr);
            }
            else{
                pq.push(nums[i]);
            }
        }
          
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};