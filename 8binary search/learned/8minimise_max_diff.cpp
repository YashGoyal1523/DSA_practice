//lc 2616

// minimise the maximum
//bs on answer


class Solution {
public:

    // func to count no of pairs with diff <=mid
    int cnt(int mid,vector<int>& nums){
        int count=0;
        int index=0;
        while(index<nums.size()-1){
             // If a valid pair is found, skip both numbers.
            if (nums[index + 1] - nums[index] <= mid) {
                count++;
                index+=2;
            }
           else index++;
        }
    return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums[n-1]-nums[0];

        int ans=-1;
        while(l<=h){
        int mid=l+(h-l)/2;

        if(cnt(mid,nums)>=p){
            ans=mid;
            h=mid-1;
        }
         else{
            l=mid+1;
         }

        }

    return ans;

    }
};