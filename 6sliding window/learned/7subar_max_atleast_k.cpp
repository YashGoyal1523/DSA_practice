//lc 2962
// https://youtu.be/06VaWkj8e-0?si=G9sRhp8iBL4yEWcA
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n  = nums.size() ;
            long long ans = 0 ;
            int maxi = *max_element(nums.begin(),nums.end()) ;
            int freq = 0 ;
            int i = 0 ;
            int j=0;
            while(j<nums.size()) {
                if(nums[j] == maxi)
                freq++ ;
    
                while(freq == k) {
                    ans += n-j ;
    
                    if(nums[i] == maxi) {
                        freq-- ;
                    }
    
                    i++ ;
                }
                j++;
            }
    
            return ans ;
        }
    };