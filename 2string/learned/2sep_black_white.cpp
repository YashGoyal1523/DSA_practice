// lc 2938

// starting se traverse kro and 0 mile toh usko uski correct position tak pahucha do


// class Solution {
// public:
//     long long minimumSteps(string s) {
//       long long count=0;
//       int i=0; // to traverse
//       int pos=0;  // available pos where 0 will be placed
//       while(i<s.size()){   
//         if(s[i]=='0'){
//             count+=(i-pos);
//             pos++;
//         }
//         i++;
//       }
//       return count;
//     }
// };