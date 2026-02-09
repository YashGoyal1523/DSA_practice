//lc 2302

//sliding window

// likhne ka tarika 1

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans=0;
            long long val=0;
            int i=0;
            int j=0;
            while(j<nums.size()){
                if(nums[j]>=k) {
                    i=j+1;
                     j++;
                     val=0;
                    continue;
                }
                val+=nums[j];
                while(val*(j-i+1)>=k){
                    val-=nums[i];
                    i++;
                }
                ans+=(j-i+1);
                j++;
            }
    
            return ans;
        }
    };

    // likhne ka tarika 2
    class Solution {
        public:
            long long countSubarrays(vector<int>& nums, long long k) {
                long long ans=0;
                long long val=0;
                int i=0;
                int j=0;
                while(j<nums.size()){
                    
                    val+=nums[j];
                    while(val*(j-i+1)>=k){
                        val-=nums[i];
                        i++;
                    }
                    ans+=(j-i+1);
                    j++;
                }
        
                return ans;
            }
        };