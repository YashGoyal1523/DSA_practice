//lc 1800

// similar to lc 3105 
// ie pichla ques 

//way1
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) {
                sum+=nums[i];
                ans=max(ans,sum);
            }
            else {
                sum=nums[i];
            }
        }
        return ans;
    }
};

//way2
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) {
                sum+=nums[i];
            }
            else {
                ans=max(ans,sum);
                sum=nums[i];
            }
        }
        ans=max(ans,sum);
        return ans;
    }
};