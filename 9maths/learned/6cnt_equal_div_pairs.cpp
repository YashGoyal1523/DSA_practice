
// lc 2176

//m1 bruteforce

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int result = 0;
    
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
    
                    if ((i * j) % k == 0 && nums[i] == nums[j]) {
                        result++;
                    }
                }
            }
            return result;
        }
    };

    //m2  optimal

    // if i*j is divisible by k then i will be divisible by k/gcd(k,j) and j will be divisible by k/gcd(k,i) 

    //https://youtu.be/6iODXcqICGQ?si=8L-CVxWWmQYCTiJQ