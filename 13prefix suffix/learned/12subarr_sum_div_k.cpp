//lc 974

// subarray sum div by k

//https://youtu.be/7Xeorb721LQ?si=JYGcBZxEeR1ccn-5


// bruteforce
// saare subarrays generate krke dekho


//better 
//prefix sum

// -------rem x-------
// .......................
// --rem x--|--rem 0--
//           (divisible)

 
class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            int n = nums.size();
            
            unordered_map<int, int> mp;
            int sum = 0;
            
            mp[0] = 1;
            
            int result = 0;
            
            for(int i = 0; i<n; i++) {
                sum += nums[i];
                
                int rem = sum%k;
                
                if(rem < 0) {
                    rem += k;
                }
                
                if(mp.find(rem) != mp.end()) {
                    result += mp[rem];
                }
                
                mp[rem]++;
                
            }
            
            return result;
            
        }
    };