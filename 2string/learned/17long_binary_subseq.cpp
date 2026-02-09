//lc 2311

// https://youtu.be/ca04hcfuGlY?si=EOYcjWEhjAJb_sZY

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long powerValue = 1; //2^0
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } 
            else {// =='1'

                if(powerValue <= k) {
                length++;
                k -= powerValue;
                }
            }

            if (powerValue <= k)
                powerValue <<= 1; //powerValue *= 2;
        }
        
        return length;
    }
};