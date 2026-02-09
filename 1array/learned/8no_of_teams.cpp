// lc 1395 

//  check all possibility
// har element ko team ka middle member leke uske aage piche ke members dhudndege

// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int size = rating.size();
//         int teamCnt = 0;
//         for(int currIndx = 0; currIndx < size; currIndx++){  //ek ek krke sabko middle of team lege // optimise kr skte ..... 1 se size-2 tak dekho ...as curr element ko teeno element ka middle wala lere hum....... toh 0 index wale ke left m toh hai hi nhi and size-1 index ke right m toh kuch h hi nhi toh inme teen elements nhi bana paayege
//             int leftSmallerCnt = 0, rightLargerCnt = 0;
//             int leftLargerCnt = 0, rightSmallerCnt = 0;
//             for(int prevIndx = currIndx - 1; prevIndx >=0; prevIndx--){
//                 if(rating[currIndx] > rating[prevIndx])leftSmallerCnt++;
//                 if(rating[currIndx] < rating[prevIndx])leftLargerCnt++;
//             }
//             for(int nextIndx = currIndx + 1;  nextIndx < size; nextIndx++){
//                 if(rating[currIndx] > rating[nextIndx])rightSmallerCnt++;
//                 if(rating[currIndx] < rating[nextIndx])rightLargerCnt++;
//             }
//             teamCnt += (leftSmallerCnt * rightLargerCnt) + (leftLargerCnt * rightSmallerCnt);
//             
//         }
//         return teamCnt;
//     }
// };