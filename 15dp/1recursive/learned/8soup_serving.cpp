//lc 808

// https://youtu.be/BiA4x5Gj7io?si=cQgc-BL-uUqQQeCW

// rec

class Solution {
public:


    double solve(int a,int b){
        if(a<=0&&b<=0) return 0.5;
        if (a<=0) return 1.0;
        if(b<=0) return 0.0;

        //first operation
        double first=0.25*solve(a-100,b);
        //second op
        double second =0.25*solve(a-75,b-25);
        //third op
        double third=0.25*solve(a-50,b-50);
        //fourth op
        double fourth=0.25*solve(a-25,b-75);

        return first+second+third+fourth;

    }


    double soupServings(int n) {
        double ans=solve(n,n);
        return ans;
    }
};


// mem

class Solution {
public:


    double solve(int a,int b,vector<vector<double>>&dp){
        if(a<=0&&b<=0) return 0.5;
        if (a<=0) return 1.0;
        if(b<=0) return 0.0;

        if(dp[a][b]!=-1) return dp[a][b];
        //first operation
        double first=0.25*solve(a-100,b,dp);
        //second op
        double second =0.25*solve(a-75,b-25,dp);
        //third op
        double third=0.25*solve(a-50,b-50,dp);
        //fourth op
        double fourth=0.25*solve(a-25,b-75,dp);

        return dp[a][b]=first+second+third+fourth;

    }


    double soupServings(int n) {
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        double ans=solve(n,n,dp);
        return ans;
    }
};


// trick

//  if(n >= 5000)
//             return 1.0;
        

class Solution {
public:


    double solve(int a,int b,vector<vector<double>>&dp){
        if(a<=0&&b<=0) return 0.5;
        if (a<=0) return 1.0;
        if(b<=0) return 0.0;

        if(dp[a][b]!=-1) return dp[a][b];
        //first operation
        double first=0.25*solve(a-100,b,dp);
        //second op
        double second =0.25*solve(a-75,b-25,dp);
        //third op
        double third=0.25*solve(a-50,b-50,dp);
        //fourth op
        double fourth=0.25*solve(a-25,b-75,dp);

        return dp[a][b]=first+second+third+fourth;

    }


    double soupServings(int n) {
         if(n >= 5000)
            return 1.0;
        
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        double ans=solve(n,n,dp);
        return ans;
    }
};