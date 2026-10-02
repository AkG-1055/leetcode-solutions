class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(), people.rend());
        int n = people.size();
        int boats = 0;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            }
            else{
                left++;
            }
            boats++;
        }
        return boats;
    }
};