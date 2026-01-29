// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int B = 1;
        int E = n;
        int M;

        while (B <= E){
            M = B + (E - B) / 2;

            if (isBadVersion(M) == false){
                B = M + 1;
            }
            else{
                E = M - 1;
            }
        }
        return B;
    }
};