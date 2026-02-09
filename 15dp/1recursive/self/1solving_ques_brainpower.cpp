//lc 2140

// rec

class Solution {
    public:
        long long rec(vector<vector<int>>& questions,int index){
            if(index>=questions.size()) return 0;
    
            long long take=questions[index][0]+rec(questions,index+questions[index][1]+1);
            long long nottake=rec(questions,index+1);
    
            return max(take,nottake);
    
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int index=0;
            long long ans=rec(questions,index);
            return ans;
    
        }
    };


// dp

class Solution {
    public:
        long long rec(vector<vector<int>>& questions,int index,vector<long long>&dp){
            if(index>=questions.size()) return 0;
            if(dp[index]!=-1) return dp[index];
            long long take=questions[index][0]+rec(questions,index+questions[index][1]+1,dp);
            long long nottake=rec(questions,index+1,dp);
    
            return dp[index]=max(take,nottake);
    
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int index=0;
            int n=questions.size();
            vector<long long>dp(n+1,-1);
            long long ans=rec(questions,index,dp);
            return ans;
    
        }
    };