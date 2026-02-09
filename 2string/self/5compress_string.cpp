//lc 3163

// class Solution {
// public:
//     string compressedString(string word) {
//         string ans="";
//         int cnt=1;
//         char ch=word[0];
//         for(int i=1;i<word.size();i++){
//             if(word[i]==ch &&cnt<9) {
//                 cnt++;
                
//             }
//             else{
//               ans.push_back(cnt+'0');
//                 ans.push_back(ch); 
//                 cnt=1;
//                 ch=word[i];
//             }
//         }
//          ans.push_back(cnt+'0');
//         ans.push_back(ch); 
//         return ans;
//     }
// };