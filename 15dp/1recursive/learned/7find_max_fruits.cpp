//lc 3363

// to reach n-1,n-1 in n-1 steps :
//0,0 wala can only move in diagonal
//0,n-1 and n-1,0 wala cannot cross diagonal 

//diagonal wale saare 0,0 wala lelega
//0,n-1 wale ke liye diagonal ke uper se dekhlo explore all path se
//n-1,0 wale ke liye diagonal ke niche se dehlo explore all path se


//rec
class Solution {
public:

    int solve2(int x,int y,vector<vector<int>>& fruits){
        int n=fruits.size();
        if(x==n-1&&y==n-1) return 0;
        if(y<=x||y>=n) return -1e9;
       

        //bottom
        int bottom=fruits[x][y]+solve2(x+1,y,fruits);
        //botright
        int botr=fruits[x][y]+solve2(x+1,y+1,fruits);
        //botleft
        int botl=fruits[x][y]+solve2(x+1,y-1,fruits);

        return max(bottom,max(botr,botl));
        
    }

  int solve1(int x,int y,vector<vector<int>>& fruits){
    int n=fruits.size();
        if(x==n-1&&y==n-1) return 0;
        if(x<=y||x>=n) return -1e9;

        //right
        int right=fruits[x][y]+solve1(x,y+1,fruits);
        //righttop
        int rtop=fruits[x][y]+solve1(x-1,y+1,fruits);
        //rightbot
        int rbot=fruits[x][y]+solve1(x+1,y+1,fruits);

        return max(right,max(rtop,rbot));
        
    }




    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int sum=0;
        //0,0 wala
        int i=0;
        int j=0;
        while(i<n){
            sum+=fruits[i][j];
            i++;
            j++;
        }
        //0,n-1 wala
       sum+=solve1(n-1,0,fruits);
       //n-1,0 wala
       sum+=solve2(0,n-1,fruits);

    

       return sum;
    }
};


// mem


class Solution {
public:

    int solve2(int x,int y,vector<vector<int>>& fruits,vector<vector<int>>&dp){
        int n=fruits.size();
        if(x==n-1&&y==n-1) return 0;
        if(y<=x||y>=n) return -1e9;
       
        if(dp[x][y]!=-1) return dp[x][y];

        //bottom
        int bottom=fruits[x][y]+solve2(x+1,y,fruits,dp);
        //botright
        int botr=fruits[x][y]+solve2(x+1,y+1,fruits,dp);
        //botleft
        int botl=fruits[x][y]+solve2(x+1,y-1,fruits,dp);

        return dp[x][y]=max(bottom,max(botr,botl));
        
    }

  int solve1(int x,int y,vector<vector<int>>& fruits, vector<vector<int>>&dp){
    int n=fruits.size();
        if(x==n-1&&y==n-1) return 0;
        if(x<=y||x>=n) return -1e9;

        if(dp[x][y]!=-1) return dp[x][y];

        //right
        int right=fruits[x][y]+solve1(x,y+1,fruits,dp);
        //righttop
        int rtop=fruits[x][y]+solve1(x-1,y+1,fruits,dp);
        //rightbot
        int rbot=fruits[x][y]+solve1(x+1,y+1,fruits,dp);

        return dp[x][y]=max(right,max(rtop,rbot));
        
    }




    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int sum=0;
        //0,0 wala
        int i=0;
        int j=0;
        while(i<n){
            sum+=fruits[i][j];
            i++;
            j++;
        }
        //0,n-1 wala
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
       sum+=solve1(n-1,0,fruits,dp1);
       //n-1,0 wala
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
       sum+=solve2(0,n-1,fruits,dp2);

    

       return sum;
    }
};