// lc 2275

// for & of nos to be >0 there should be atleast 1 bit position which is set in all nos
// har bit position ke liye numbers ginlege kitno ki voh bit set hai....sab position ke ans mein se max lelege

// class Solution {
// public:

//     int ithBit(int n,int i){
//         int mask=1<<i;
//         return n&mask;
//     }


//     int largestCombination(vector<int>& candidates) {
//         int ans=-1e9;
//         for(int i=0;i<32;i++){
//             int cnt=0;
//             for(auto j:candidates){
//                 if(ithBit(j,i)) cnt++;
//             }
//             ans=max(cnt,ans);
//         }
//         return ans;
//     }
// };