//lc 3202

// https://youtu.be/g38YHwee1Yo?si=x8wyvUGGfL8uYtpG

// rec dp

//longest increasing subsequence ka variant hai yeh ques

//note: %k can give 0,1,2,3,...,k-1

//har remainder value ke liye lis nikalo ...sabme se max lelo

//rec
class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev,int mod,int k) {
       //base case
       if(curr == nums.size() ) {
           return 0;
       } 

//include
    // if curr ki val + prev ki val %k == mod then include curr 
       int include = 0;
       if(prev == -1 || (nums[curr]+nums[prev])%k==mod ) {   // prev  wali condition likhi for 0 index wale ko include k liye as voh wala compare wale m nhi aa payega as -1 wala not exist
           include = 1 + solveUsingRecursion(nums, curr+1, curr,mod,k); // prev ko curr pe, curr ek aage
       }
 //exclude      
       int exclude  = 0 + solveUsingRecursion(nums, curr+1, prev,mod,k); // prev vhi, curr ek aage

       int ans = max(include, exclude);

       return ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        int ans=0;
        for(int mod=0;mod<=k-1;mod++){
            int curr=0;
            int prev=-1;
            
            int length=solveUsingRecursion(nums,curr,prev,mod,k);

            ans=max(length,ans);
        }
    return ans;
    }
};

//mem

class Solution {
public:
    int solveUsingMem(vector<int>& nums, int curr, int prev,int mod,int k,vector<vector<int>>&dp) {
       //base case
       if(curr == nums.size() ) {
           return 0;
       } 

    if(dp[curr][prev+1]!=-1) return dp[curr][prev+1] ;//index shifting done
 //include
  
       int include = 0;
       if(prev == -1 || (nums[curr]+nums[prev])%k==mod ) {   
           include = 1 + solveUsingMem(nums, curr+1, curr,mod,k,dp); 
       }
 //exclude      
       int exclude  = 0 + solveUsingMem(nums, curr+1, prev,mod,k,dp); 

       int ans = max(include, exclude);

       return dp[curr][prev+1]=ans;//index shifting done
    }
    int maximumLength(vector<int>& nums,int k) {
        int n=nums.size();
        int ans=0;
        for(int mod=0;mod<=k-1;mod++){
            int curr=0;
            int prev=-1;
            vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
            int length=solveUsingMem(nums,curr,prev,mod,k,dp);

            ans=max(length,ans);
             
        }

        return ans;

    }
};

//tabu 1

class Solution {
public:
    int solveUsingTabulation(vector<int>& num,int mod,int k ) {
        int n = num.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));  // initial initialistiaton handled

        for(int curr_index=n-1; curr_index>=0; curr_index--) { // bade se chota flow// n handle krlia isiliye n-1
            for(int prev_index=curr_index-1; prev_index >= -1; prev_index--) { // bade se chota flow // starting wali value ke liye : prev curr ke  piche hi hoga..worst case ek piche..vhi lege

                int include = 0;
                if(prev_index == -1 || (num[curr_index] + num[prev_index])%k==mod ) { // idhar wale mein +1 ki need nhi as || ke baad h and prev -1 ka mtlb  phle wali true nikl gyi... toh yeh check hogi hi nhi seedha andar ghusegi
                    include = 1 + dp[curr_index+1][curr_index+1]; //+1 krlia ....(jaha jaha dp aara har ke col mein +1 krna pdega)
                }
                int exclude  = 0 + dp[curr_index+1][prev_index+1];  // index shifting needed...+1
                dp[curr_index][prev_index+1] = max(include, exclude);    // index shifting needed...+1

            }
        }
        return dp[0][0];   // index shifting needed ...+1 // dp[0][-1+1=0]; 
    }
    int maximumLength(vector<int>& nums,int k) {
        int n=nums.size();
        int ans=0;
        for(int mod=0;mod<=k-1;mod++){
            int curr = 0; // index
        int prev = -1; // index
        int length = solveUsingTabulation(nums,mod,k);
        
            ans=max(length,ans);
             
        }

        return ans;

    }
};

//tabu 2




class Solution {
public:
    int solve(vector<int> &arr,int mod,int k)
{
    int n = arr.size();
    vector<int> dp(n, 1);  // dp[i] signifies the length of longest  subsequence from starting that ends at element present at i // initially sabpe 1 rkhge (uske longest subsequence m voh included h filhaal)
    int maxi = -1; // for ans
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if ((arr[prev]+arr[i])%k==mod)
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
    int maximumLength(vector<int>& nums,int k) {
        int n=nums.size();
        int ans=0;
        for(int mod=0;mod<=k-1;mod++){
            
        int length = solve(nums,mod,k);
        
            ans=max(length,ans);
             
        }

        return ans;

    }
};

//sab tle degaaa abhi tak



// optimised tabu 2


class Solution {
public:
   
    int maximumLength(vector<int>& nums,int k) {
        int n=nums.size();
 
    vector<vector<int>> dp(k,vector<int>(n, 1));  //0th row  for mod 0 //1st row for mod 1.....
    
    int ans = 0; 
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {   
            int mod=(nums[prev]+nums[i])%k;
            
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][prev]);
                ans=max(ans,dp[mod][i]);
            
        }
        
    }

        return ans;

    }
};