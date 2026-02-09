// //lc 402

// //https://youtu.be/TzsbIDtTlsQ?si=OpxWyxiq_rHu17Jd

// class Solution {
// public:

// int solve(vector<vector<int>>& heightMap){
//     int m=heightMap.size();
//     int n=heightMap[0].size();

//     vector<vector<int>>vis(m,vector<int>(n,0));
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

// //push boundary elements
// // cols
//     for(int i=0;i<m;i++){
//         for(int j : {0,n-1}){
//             pq.push({heightMap[i][j],{i,j}});
//             vis[i][j]=true;
//         }
//     }
// //rows
//     for(int j=1;j<n-1;j++){
//         for(int i : {0,m-1}){
//             pq.push({heightMap[i][j],{i,j}});
//             vis[i][j]=true;
//         }
//     }

//     int ans=0;
// //bfs implementation
//     while(!pq.empty()){
//         auto currnode=pq.top();
//         int currheight=currnode.first;
//         int x=currnode.second.first;
//         int y=currnode.second.second;
//         pq.pop();

//         int dx[]={-1,0,1,0};
//         int dy[]={0,1,0,-1};

//         for(int i=0;i<4;i++){
//             int newx=x+dx[i];
//             int newy=y+dy[i];

//             if(newx>=0&&newx<m&&newy>=0&&newy<n&&!vis[newx][newy]){
//                 ans+=max(currheight-heightMap[newx][newy],0);
//                 pq.push({max(currheight,heightMap[newx][newy]),{newx,newy}});
//                 vis[newx][newy]=true;
//             }
//         }
//     }

//     return ans;

// }


//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int ans=solve(heightMap);

//         return ans;
//     }
// };