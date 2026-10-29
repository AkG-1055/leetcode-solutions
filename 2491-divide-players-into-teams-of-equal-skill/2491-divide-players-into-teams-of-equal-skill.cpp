class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        vector<vector<int>> teams;

        int sum = skill[0] + skill[n - 1];

        for (int i = 0; i < n / 2; i++) {
            int total = skill[i] + skill[n - i - 1];
            vector<int> team;
            if (total == sum) {
                team.push_back(skill[i]);
                team.push_back(skill[n - i - 1]);

                teams.push_back(team);
            }
            else {
                return -1;
            }
        }

        long long chemistry = 0;

        for (auto& team : teams) {
            chemistry += (team[0] * team[1]);
        }

        return chemistry;
    }
};