// lc 2537

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            unordered_map<int,long long>freq;
            long long cnt=0;
            long long ans=0;
            int i=0;
            int j=0;
            while(j<nums.size()){
                cnt+=freq[nums[j]];
                freq[nums[j]]++;
                while(cnt>=k){
                    ans+=(nums.size()-j);
                    freq[nums[i]]--;
                    cnt-=(freq[nums[i]]);
                    i++;
                }
                j++;
            }
    
            return ans;
        }
    };