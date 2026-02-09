//lc 2929

// rec/dp ke constaints nhi haii ..... tle dega

//dp
class Solution {
public:

    long long solve(int n,int limit,int child,vector<vector<long long>>&dp){
        if(n==0) return 1;
        if(child>3) return 0;
        if(dp[n][child]!=-1) return dp[n][child];
        long long ans=0;
        for(int assign=0;assign<=min(n,limit);assign++){
            ans+=solve(n-assign,limit,child+1,dp);
        }
        return dp[n][child]=ans;
    }


    long long distributeCandies(int n, int limit) {
        int child=1;
        vector<vector<long long>>dp(n+1,vector<long long>(4,-1));
        long long ans=solve(n,limit,child,dp);
        return ans;
    }
};

// https://youtu.be/eL_3cDp0zjE?si=f7ZNKfuuzaV_-5NB

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int min_child1=max(0,n-2*limit);
        int max_child1=min(n,limit);
        for(int child1=min_child1;child1<=max_child1;child1++){
            int rem_n=n-child1;

            int min_child2=max(0,rem_n-limit);
            int max_child2=min(limit,rem_n);

            ans+=max_child2-min_child2+1;
        }
        return ans;
    }
};