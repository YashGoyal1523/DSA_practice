// //lc 3418

// //3d dp

// //explore all ways


// // rec

// class Solution {
// public:
//     int solve(int x,int y,vector<vector<int>>& coins,int k){
//         int m=coins.size();
//         int n=coins[0].size();
//         if(x==m-1&&y==n-1) {
//             if(coins[x][y]>=0) return coins[x][y];
//             else{
//                 if(k<2) return 0;
//                 else return -(abs(coins[x][y]));
//             }
//         }
//         if(x==m||y==n) return -1e9;

//         int down;
//         int right;
//         //down
//         if(coins[x][y]>=0){
//             down=coins[x][y]+solve(x+1,y,coins,k);
//         }
//         else{
//             // steal
//             int option1=-(abs(coins[x][y]))+solve(x+1,y,coins,k);
//             int option2=-1e9;
//             //no steal
//             if(k<2) option2 =solve(x+1,y,coins,k+1);
//             down=max(option1,option2);
//         }
//         //right
//         if(coins[x][y]>=0){
//          right=coins[x][y]+solve(x,y+1,coins,k);
//         }
//         else{
//             //  steal
//             int option1=-(abs(coins[x][y]))+solve(x,y+1,coins,k);
//             // no steal
//             int option2=-1e9;
//             if(k<2) option2=solve(x,y+1,coins,k+1);
//             right=max(option1,option2);
//         }

//         return max(down,right);
//     }
//     int maximumAmount(vector<vector<int>>& coins) {
//         int x=0;
//         int y=0;
//         int k=0;
//         int ans =solve(x,y,coins,k);
//         return ans;
//     }
// };

// // mem
// // dp initialise int_min se krlena -1 ki jagah as score negative bhi ja skta

// class Solution {
// public:
//     int solve(int x,int y,vector<vector<int>>& coins,int k,vector<vector<vector<int>>>&dp){
//         int m=coins.size();
//         int n=coins[0].size();
//         if(x==m-1&&y==n-1) {
//             if(coins[x][y]>=0) return coins[x][y];
//             else{
//                 if(k<2) return 0;
//                 else return -(abs(coins[x][y]));
//             }
//         }
//         if(x==m||y==n) return -1e9;

//            if(dp[x][y][k]!=INT_MIN) return dp[x][y][k];
//         int down;
//         int right;
//         //down
//         if(coins[x][y]>=0){
//             down=coins[x][y]+solve(x+1,y,coins,k,dp);
//         }
//         else{
//             // steal
//             int option1=-(abs(coins[x][y]))+solve(x+1,y,coins,k,dp);
//             int option2=-1e9;
//             //no steal
//             if(k<2) option2 =solve(x+1,y,coins,k+1,dp);
//             down=max(option1,option2);
//         }
//         //right
//         if(coins[x][y]>=0){
//          right=coins[x][y]+solve(x,y+1,coins,k,dp);
//         }
//         else{
//             //  steal
//             int option1=-(abs(coins[x][y]))+solve(x,y+1,coins,k,dp);
//             // no steal
//             int option2=-1e9;
//             if(k<2) option2=solve(x,y+1,coins,k+1,dp);
//             right=max(option1,option2);
//         }

//         return dp[x][y][k]=max(down,right);
//     }
//     int maximumAmount(vector<vector<int>>& coins) {
//           int m=coins.size();
//         int n=coins[0].size();
//         int x=0;
//         int y=0;
//         int k=0;
//         vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(3,INT_MIN)));
//         int ans =solve(x,y,coins,k,dp);
//         return ans;
//     }
// };