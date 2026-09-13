class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            int count = nums[i].length();

            if (pq.size() < k) {
                pq.push({count, nums[i]});
            }
            else{
                if (count > pq.top().first) {
                    pq.pop();
                    pq.push({count, nums[i]});
                    continue;
                }
                if (count == pq.top().first) {
                    string top = pq.top().second;
                    for (int j = 0; j < count; j++) {
                        if ((nums[i][j] - '0') > (top[j] - '0')) {
                            pq.pop();
                            pq.push({count, nums[i]});
                            break;
                        }
                        else if ((nums[i][j] - '0') < (top[j] - '0')){
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                }
            }
        }
        return pq.top().second;
    }
};