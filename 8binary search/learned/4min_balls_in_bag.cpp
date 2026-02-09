//lc 1760

//minimise the maximum 
// binary search on answer
// search space :[1,max of array]
// isvalid function logic :
// Given integer maxBallsInBag, will check if it’s possible to distribute the balls so that no bag contains more than maxBallsInBag balls, performing at most maxOperations .
// to check : total operations nikalege ki kitne operations lagege ki saare bag divide hojaye and and max in bag is maxBallsInBag no of balls if its <= allowed then true else false
// for this...har ek bag ke liye no of operations required taaki usse banne wale bags mein max balls condition satsify kregi ...nikalege ....and sabke operations add krdege
// for this...Let's say that we need xi operations for the i-th bag. That means that xi+1 bags of the final array are dedicated to the balls originally contained in the i-th bag (one for each operation applied to it + the initial bag). To satisfy the constraint, each of these bags contains no more than maxBallsInBag balls. Therefore:
// nums[i] ≤ (xi+1)⋅maxBallsInBag
//ie
// maxBallsInBag/nums[i] -1 ≤ xi
//Since the number of operations is limited, we want to minimize the number of operations needed for each bag. So, we conclude that:
// xi=ceil( maxBallsInBag/nums[i])−1
// sabka nikalke add krke check krlege


// class Solution {
// public:

//     bool valid(int mid,vector<int>& nums, int maxOperations){
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             count+=ceil(nums[i]/(double)mid)-1;
//         }
//         return count<=maxOperations;
//     }


//     int minimumSize(vector<int>& nums, int maxOperations) {
//        int l=1;
//        int h=*max_element(nums.begin(),nums.end());
//     int ans=-1;
//        while(l<=h){
//         int mid=(l+h)/2;
//         if(valid(mid,nums,maxOperations)){
//             ans=mid;
//             h=mid-1;
//         }
//         else{
//             l=mid+1;
//         }
//        }
//        return ans;
//     }
// };