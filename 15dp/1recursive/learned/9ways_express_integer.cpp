//lc 2787

//explore all ways

//inc/exc


//rec

//tarika 1

// n ko long long lege in solve parameter to handle integer overflow

class Solution {
public:
    int mod=1000000007;
    
    int solve(long long n,int x,int i){
        if(n<0) return 0;
        if(n==0) return 1;
        if(i>n) return 0;
        
        int include=solve(n-pow(i,x),x,i+1);
        int exclude=solve(n,x,i+1);

        return (include+exclude)%mod;
    }



    int numberOfWays(int n, int x) {
        int i=1;
        int ans=solve(n,x,i);
        return ans;
    }
};


//tarika 2 
//n ko int hi rkhna and early return krlena

class Solution {
public:
    int mod=1000000007;


    int solve(int n,int x,int i){
        if(n<0) return 0;
        if(n==0) return 1;

        int curr_pow=pow(i,x);
        if(curr_pow>n) return 0; //early return krliya to handle integer overflow.....
        
        int include=solve(n-curr_pow,x,i+1);
        int exclude=solve(n,x,i+1);

        return (include+exclude)%mod;
    }



    int numberOfWays(int n, int x) {
        int i=1;
        int ans=solve(n,x,i);
        return ans;
    }
};


// mem


class Solution {
public:
    int mod=1000000007;


    int solve(int n,int x,int i,vector<vector<int>>&dp){
        if(n<0) return 0;
        if(n==0) return 1;

        int curr_pow=pow(i,x);
        if(curr_pow>n) return 0;

        if(dp[n][i]!=-1) return dp[n][i];
        
        int include=solve(n-curr_pow,x,i+1,dp);
        int exclude=solve(n,x,i+1,dp);

        return dp[n][i]=(include+exclude)%mod;
    }



    int numberOfWays(int n, int x) {
        int i=1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(n,x,i,dp);
        return ans;
    }
};