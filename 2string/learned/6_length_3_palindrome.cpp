// //lc 1930

// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         vector<int>first_occ(26,-1);
//         vector<int>last_occ(26,-1);
//         for(int i=0;i<s.size();i++){
//             if(first_occ[s[i]-'a']==-1) first_occ[s[i]-'a']=i;
//             last_occ[s[i]-'a']=i;
//         }
//         int ans=0;
//         for(int i=0;i<26;i++){
//             if(first_occ[i]!=-1 && last_occ[i]!=-1){ 
//                 unordered_set<int> st;
//                 for(int j=first_occ[i]+1;j<last_occ[i];j++) st.insert(s[j]);
//                 ans+= st.size();
//             }
//         }
//         return ans;
//     }
// };