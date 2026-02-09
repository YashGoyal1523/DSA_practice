// //lc 2657

// //tarika 1
// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         unordered_map<int,bool>ma;
//         unordered_map<int,bool>mb;
//         int n=A.size();
//         vector<int>ans(n);
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             ma[A[i]]=true;
//             mb[B[i]]=true;
//             if(A[i]==B[i]) cnt++;
//             else {
//                 if(ma[B[i]]==true) cnt++;
//                 if(mb[A[i]]==true) cnt++;

//             }
//             ans[i]=cnt;

//         }
//         return ans;
//     }
// };

// //m2 tarika 2
// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         unordered_map<int,int>m;
//         int n=A.size();
//         int cnt=0;
//         vector<int>ans(n);
//         for(int i=0;i<n;i++){
//             m[A[i]]++;
//             if(m[A[i]]==2) cnt++;
//             m[B[i]]++;
//             if(m[B[i]]==2) cnt++;
//             ans[i]=cnt;

//         }
        
        
//         return ans;
//     }
// };