//lc 1765

// similar to lc 542 - 0_1 matrix

class Solution {
public:

bool safe(int x,int y,vector<vector<int>>&vis){
    int m=vis.size();
    int n=vis[0].size();

    if(x>=0&&x<m&&y>=0&&y<n&&vis[x][y]==0) return true;

    return false;

}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
               int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;  // ((i,j),dist)

        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            int row=node.first.first;
            int col=node.first.second;
            int dist=node.second;
            q.pop();

            ans[row][col]=dist;

              int dx[] = {-1, 0, 1, 0};
              int dy[] = {0, 1, 0, -1};

              for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if(safe(nrow,ncol,vis)){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }
              }

        }
        return ans;
    } 
    
};