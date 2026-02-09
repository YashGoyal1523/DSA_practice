//lc 2419

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // a&b<=min(a,b)
        // ->max possible & value is max element value
        // ->longest length subarray with max & value -> max consecutive maximum valued elements 
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=maxi){
                ans=max(ans,cnt);
                cnt=0;
            }
            else cnt++;
        }
      
        ans=max(ans,cnt);

        return ans;
    }
};