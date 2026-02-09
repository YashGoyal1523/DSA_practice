// //lc 2466

// // rec

// class Solution {
// public:

//     int solve(int low, int high, int zero, int one,int len){
//         if(len>high) return 0;


//         int ans=0;
//         if(len>=low&&len<=high) ans++;
//        //0
//        ans = (ans + solve(low, high, zero, one, len + zero)) % 1000000007;
//        //1
//         ans = (ans + solve(low, high, zero, one, len + one)) % 1000000007;

//         return ans;
//     }





//     int countGoodStrings(int low, int high, int zero, int one) {
//         int len=0;
//         int ans=solve(low,high,zero,one,len);
//         return ans;

//     }
// };



// // dp

// class Solution {
// public:

//     int solve(int low, int high, int zero, int one,int len,vector<int>&dp){
//         if(len>high) return 0;

//        if(dp[len]!=-1) return dp[len];

//         int ans=0;
//         if(len>=low&&len<=high) ans++;
//         //0
//        ans = (ans + solve(low, high, zero, one, len + zero, dp)) % 1000000007;
//        //1
//         ans = (ans + solve(low, high, zero, one, len + one, dp)) % 1000000007;

//         return dp[len]=ans;
//     }


//     int countGoodStrings(int low, int high, int zero, int one) {
//         int len=0;
//         vector<int>dp(high+1,-1);
//         int ans=solve(low,high,zero,one,len,dp);
//         return ans;

//     }
// };