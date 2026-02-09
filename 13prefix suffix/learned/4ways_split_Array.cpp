//lc 2270

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        // long long total_sum=accumulate(nums.begin(),nums.end(),0ll);
        long long total_sum=prefix[n-1];
        int cnt=0;
        for(int i=0;i<n-1;i++){
            long long left_sum=prefix[i];
            long long right_sum=total_sum-left_sum;
            if(left_sum>=right_sum) cnt++;
        }
        return cnt;
    }
};