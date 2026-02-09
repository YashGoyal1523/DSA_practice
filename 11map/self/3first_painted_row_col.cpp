// //lc 2661

//Pre-process the positions of the values in the matrix.
//Traverse the array and increment the corresponding row and column frequency using the pre-processed positions.
//If the row frequency becomes equal to the number of columns, or vice-versa return the current index

// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         unordered_map<int,pair<int,int>>mp;  // wll store row and col index of elements
//         int m=mat.size();
//         int n=mat[0].size();
//         vector<int>row(m,0); // iska index i store count of elements painted in row i
//         vector<int>col(n,0); // iska index i store count of elements painted in col i

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 mp[mat[i][j]]={i,j};
//             }
//         }
//         int ans=-1;
//         for(int i=0;i<arr.size();i++){
//             int r=mp[arr[i]].first;
//             int c=mp[arr[i]].second;
//             row[r]++;
//             col[c]++;
//             if(row[r]==n||col[c]==m) { // row bhargyi ya col bhargyi
//                 ans=i;
//                 break;
//             }
//         }

//         return ans;
//     }
// };