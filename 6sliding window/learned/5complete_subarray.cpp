//lc 2799
//https://youtu.be/t8kDspIQyFQ?si=hYzpq4f6p5oYL-dk
// kisi subarray mein no of distinct equal to no of distinct in array hojaye fir usme aage kuch bhi element daal lo voh yeh condition(distinct no=distinct no) satisfy krra hoga
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int,int>mp;
            int n=nums.size();
            for(int i=0;i<n;i++){
               mp[nums[i]]++;
            }
            int distinct=mp.size();
    
            mp.clear();
            int i=0;
            int j=0;
            int cnt1=0;
            int ans=0;
            while(j<n){
                
                mp[nums[j]]++;
                
                int cnt=mp.size();
               while(cnt==distinct){
                ans+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
               }
                j++;
            }
            
    
    
    return ans;
    
    
    
        }
    };