class KthLargest {
    int k;
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else {
                if (nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }

    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }

        return pq.top();
    }
};
