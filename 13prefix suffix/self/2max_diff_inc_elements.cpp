//lc 2016

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        vector<int>prev(n);
        prev[0]=1e9;
        for(int i=1;i<n;i++){
            prev[i]=min(prev[i-1],nums[i-1]);
            if(nums[i]>prev[i]){int diff=nums[i]-prev[i];
            ans=max(ans,diff);
            } 
        }

        return ans;
    }
};