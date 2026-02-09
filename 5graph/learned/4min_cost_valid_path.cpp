//lc 1368

//https://youtu.be/NS3C4W_jJJM?si=DUNxZpRdEReTrj9p

// bruteforce
//rec backtracking

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int rec(int x, int y, vector<vector<int>>& grid,  vector<vector<bool>>& visited, int currcost) {
        if (x == m - 1 && y == n - 1) { // reached destination
            return currcost;
        }
        visited[x][y] = true;
        // explore
        int minCost = INT_MAX; // will store currnode se dest node jaane ka min cost
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && !visited[newx][newy]) { // safe hai
                int nextfare=((grid[x][y] == i + 1)? 0: 1); // i =0 ->right ,1->left ,2->low ,3->top
                int nextCost = currcost + nextfare; // next ka reaching cost
                int ans= rec(newx, newy, grid, visited, nextCost); // aage chlke ans nikalo
                minCost =min(minCost,ans);
            }
        }
        visited[x][y] = false;
        return minCost;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int x = 0;
        int y = 0;
        int currcost = 0; // store cost of reaching current node
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans=rec(x, y, grid, visited, currcost); // explore all paths by backtracking

        return ans;
    }
};



 // graph

// grid cells are nodes ...connected in 4 directionality
// edge weight towards adjacent cells is 0 if the sign is pointing to the adjacent cell and 1 if not.
// need to find shortest path dist from src to destinaton
// using dijkstra

class Solution {
public:

int dijkstra(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dist(m,vector<int>(n,1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0]=0; // src node ka nodedist 0 dalega
     pq.push({0,{0,0}});

     while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int currx=node.second.first;
        int curry=node.second.second;
        int currdist=node.first;

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        for(int i=0;i<4;i++){ 
            int newx=currx+dx[i];
            int newy=curry+dy[i];
            
            if(newx>=0&&newx<m&&newy>=0&&newy<n){
                int griddir=i+1; // i =0->right ,=1->left ,=2->down ,=3->up
                int wt=grid[currx][curry]-griddir==0?0:1;

                if(currdist+wt<dist[newx][newy]){
                    dist[newx][newy]=currdist+wt;
                    pq.push({dist[newx][newy],{newx,newy}});
                }
            }

        }
     }
     
     return dist[m-1][n-1];
}
    int minCost(vector<vector<int>>& grid) {

        int ans=dijkstra(grid);
         
        return ans;

    }
};