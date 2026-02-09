
// lc 50
// https://youtu.be/l0YC3876qxg?si=l54j-wzWrTDKUKX3

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // int hi rkhoge  toh overflow hojayegi next step mein in case of -2^31  (-1*-2^31 =2^31 -> out of range of int)
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            }
            else {
                x = x * x;
                nn = nn / 2;
            }
        }
        //or
        //  while (nn) {
        //     if (nn % 2) {
        //         ans = ans * x;
        //     }
        //         x = x * x;
        //         nn = nn / 2;
            
        // }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
