// lc 2845
//https://youtu.be/MTQWe8qHcz0?si=dY2_s7PnqXVLJGTu
// prerequisite ques : lc 974 : count subarray sum div by k ie sum % k == 0

// given array elements ko convert krdo : if element % modulo == k then 1 rkhdo vaha else 0 rkhdo 
// fir count no subarray whose sum % modulo ==k  (sum of subarray  will give count of elements in subarray whose % modulo ==k)


class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
            int n = nums.size();
    
            unordered_map<int, long long> mp; //remainder -> count
            long long sum = 0; //sum will be equal to cnt of those elements % m == k
    
            long long result = 0;
    
            mp[0] = 1;
            for(int i = 0; i < n; i++) {
                if(nums[i] % m == k)
                    sum += 1;
    
                int r1 = sum%m;
    
                int r2 = (r1 - k + m) % m;
    
                result += mp[r2];
                mp[r1]++;
            }
    
            return result;
    
        }
    };