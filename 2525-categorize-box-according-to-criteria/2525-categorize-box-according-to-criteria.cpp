class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        vector<string> categories;
        long long vol = 1LL * length * width * height;
        if (length >= 1e4 || width >= 1e4 || height >= 1e4 || vol >= 1e9) {
            categories.push_back("Bulky");
        }

        if (mass >= 100) {
            categories.push_back("Heavy");
        }

        int n = categories.size();
        if (n == 2) {
            return "Both";
        }
        else if (n == 1 && categories[0] == "Bulky") {
            return "Bulky";
        }
        else if (n == 1 && categories[0] == "Heavy") {
            return "Heavy";
        }
        else{
            return "Neither";
        }
    }
};