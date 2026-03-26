//lc 3877

//rec
// class Solution {
// public:

//     int solve(int idx,int xorr,vector<int>& nums, int target){
//         if(idx>=nums.size()){
//             if(xorr==target) return 0;
//             return 1e9;
//         }

//         int take=solve(idx+1,xorr^nums[idx],nums,target);
//         int nottake=1+solve(idx+1,xorr,nums,target); // 1 for removal

//         return min(take,nottake);

//     }

//     int minRemovals(vector<int>& nums, int target) {
       
//         int idx=0;
//         int xorr=0;
//         int cnt=0;      
//         int ans=solve(idx,xorr,nums,target);
//         if(ans==1e9) return -1;
//         return ans;
//     }
// };
