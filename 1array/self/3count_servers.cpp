// lc 1267

// Store number of computer in each row and column.
// Count all servers that are not isolated.

// class Solution {
// public:
//     int countServers(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<int>row(m,0);
//         vector<int>col(n,0);
       
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]) row[i]++;
//             }
//         }
//         for(int j=0;j<n;j++){
//             for(int i=0;i<m;i++){
//                 if(grid[i][j]) col[j]++;
//             }
//         }
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]&&(row[i]>1||col[j]>1))  ans++;
//             }
//         }
//         return ans;
//     }
// };