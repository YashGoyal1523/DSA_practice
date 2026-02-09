//lc 2401

//If two numbers have bitwise AND equal to zero, they do not have any common set bit.
//sliding window

class Solution {
    public:
        bool check(vector<int>&bits) {
            return *max_element(bits.begin(),bits.end()) == 1 ;
        }
    
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size();
            vector<int> bits(32, 0);
            int i = 0;
            int maxLen = 0;
            int j=0;
            while(j<nums.size()) {
                for (int b = 0; b < 32; b++) {
                    if ((1 << b) & nums[j]) { 
                        bits[b]++;
                    }
                }
    
                while (!check(bits)) {
                    for (int b = 0; b < 32; b++) {
                        if ((1 << b) & nums[i]) {
                            bits[b]--;
                        }
                    }
    
                    i++ ;
                }
    
                maxLen = max(maxLen,j-i+1) ;
                j++;
            }
    
            return maxLen ;
        }
    };