// lc 2290

// Model the grid as a graph where cells are nodes and edges are between adjacent cells. Edge towards cells with obstacles have a cost of 1 and edge towards empty cells have a cost of 0.
// need to find shortest path dist from src to destinaton
// using dijkstra

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
    
        vector<vector<int>>dist(m,vector<int>(n,1e9)); // dist array ...iske har cell pe src se uss cell ka min distance will be stored
        dist[0][0]=0; // src dist=0 

        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> >pq;
        pq.push({0,{0,0}}); // src push

        while(!pq.empty()){
            auto currnode=pq.top();
            pq.pop();
            int nodedist=currnode.first;
            int x=currnode.second.first;
            int y=currnode.second.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];

                if(newx>=0&&newx<m&&newy>=0&&newy<n){ //if safe

                    int wt=(grid[newx][newy]==1) ? 1:0;

                    if(nodedist+wt<dist[newx][newy]){
                        dist[newx][newy]=nodedist+wt;
                        pq.push({dist[newx][newy],{newx,newy}});
                    }
                }
            }
        }

return dist[m-1][n-1];

    }
};