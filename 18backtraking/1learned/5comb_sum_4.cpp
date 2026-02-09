//not backtracking ques...saath rkhne k liye daaldiya yaha 

//lc 377


// https://youtu.be/YyuwTwXzSxY?si=hsBQh-vw3PWou5mW


//take/nottake
// ->take kroge toh index zero chala jayega vapis


// (Note: the take/nottake method can be implemented int 2 ways   :   1.without for loop  2.with for loop )



//tarika 1: take/nottake (implementation without for loop)

// rec

class Solution {
public:

    int solve(vector<int>& nums,int index,int target){
        if(target==0) return 1;
        if(target<0||index==nums.size()) return 0;

        //  take
        int take=solve(nums,0,target-nums[index]);   //index vapis 0 hojayega take mein
        //  not take
        int nottake=solve(nums,index+1,target);

        return take+nottake;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
    
    int index=0;
       int ans=solve(nums,index,target);
       
       return ans; 
    }
};

//mem

class Solution {
public:

    int solve(vector<int>& nums,int index,int target,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0||index==nums.size()) return 0;
if(dp[index][target]!=-1) return dp[index][target];
        //  take
        int take=solve(nums,0,target-nums[index],dp);   //index vapis 0 hojayega jab take krre
        //  not take
        int nottake=solve(nums,index+1,target,dp);

        return dp[index][target]=take+nottake;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
    
    int index=0;
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
       int ans=solve(nums,index,target,dp);
       
       return ans; 
    }
};


// tarika 2 : take/nottake (implementation with for loop)

// rec

class Solution {
public:

    int solve(vector<int>& nums,int index,int target){
        if(target==0) return 1;
        if(target<0||index==nums.size()) return 0;

        int ans=0;
        for(int i=index;i<nums.size();i++){
            //take
            int take=solve(nums,0,target-nums[i]); //index vapis 0 hojayega take mein
            ans+=take;
            //nottake
        }
        
        return ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
    
    int index=0;
       int ans=solve(nums,index,target);
       
       return ans; 
    }
};

// mem

class Solution {
public:

    int solve(vector<int>& nums,int index,int target,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0||index==nums.size()) return 0;
if(dp[index][target]!=-1) return dp[index][target];
        int ans=0;
        for(int i=index;i<nums.size();i++){
            //take
            int take=solve(nums,0,target-nums[i],dp);   // index vapis zero hojayega take mein
            ans+=take;
            //nottake
        }
        
        return dp[index][target]=ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
    
    int index=0;
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
       int ans=solve(nums,index,target,dp);
       
       return ans; 
    }
};




//note: in this ques take/nottake (with for loop) wala method can be done without using index variable also as baar baar 0 se hi start krna

// rec

class Solution {
public:
    int solve(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(target < 0) return 0;

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            //take
            int take = solve(nums, target - nums[i]);
            ans+=take;
            //nottake
        }
        return ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};

// mem

class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            //take
           int take = solve(nums, target - nums[i], dp);
           ans+=take;
           //nottake
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};
