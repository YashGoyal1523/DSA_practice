//lc 2017

//https://youtu.be/Y8VC_OnkazE?si=CX2J_isHEt3qhncQ
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long>suffix(n); //EXCL curr // 1st row
        suffix[n-1]=0;
        for(int j=n-2;j>=0;j--){
            suffix[j]=suffix[j+1]+grid[0][j+1];
        }
        vector<long long>prefix(n); //INC curr //2nd row
        prefix[0]=0;
        for(int j=1;j<n;j++){
            prefix[j]=prefix[j-1]+grid[1][j-1];
        }

       

        long long robot2score= -LLONG_MAX;
        long long ans= LLONG_MAX;
        for(int j=0;j<n;j++){  // robot1 ne yaha se turn liya
            robot2score=max(prefix[j],suffix[j]);
            ans=min(ans,robot2score);
        }
       return ans;

    }
};