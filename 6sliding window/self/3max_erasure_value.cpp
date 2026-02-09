//lc 1695

// max sum subarray containing unique elements

//sliding window

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    long long ans=0;
    long long sum=0;
    unordered_map<int,int>vis;
    int i=0;
    int j=0;
    while(j<nums.size()){
        sum+=nums[j];
        while(i<=j&&vis[nums[j]]==1){
            vis[nums[i]]=0;
            sum-=nums[i];
            i++;
        }
    vis[nums[j]]=1;
    ans=max(ans,sum);
    j++;
    }

    return sum;
    }
};