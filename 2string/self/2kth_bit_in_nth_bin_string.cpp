//lc 1545

// class Solution {
// public:


//     char findKthBit(int n, int k) {
//         string s="0";
//         for(int i=1;i<n;i++){  // s1 hai apne paas
//             string invert=s;
//             for(int j=0;j<invert.size();j++){
//                 if(invert[j]=='0') invert[j]='1';
//                 else invert[j]='0';
//             }

//             string rev=invert;
//             reverse(rev.begin(),rev.end());

//             s+=('1'+rev);
        
//         }

//         return s[k-1];   
//     }
// };