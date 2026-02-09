//lc 2134


// the number of 1’s to be grouped together is the number of 1's the whole array has.
// Call this number total. We should then check for every subarray of size total, how many swaps are required to have the subarray be all 1’s. and take min out of all subarrays
// The number of swaps required is the number of 0’s in the subarray.
// To eliminate the circular property of the array, we can append the original array to itself Ya fir can use modulus % operator .

// // sliding window

// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         // finding window size 
//         //find total 1s present
//         int k=count(nums.begin(),nums.end(),1);  
//         int ans=INT_MAX;

//         if(k==0) return 0; // ek bhi 1 nhi toh kya hi swap
//         if(k==nums.size()) return 0; // sab hi 1 h toh kya h swap  // nhi daaloge toh bhi chal jaayega bas isse optimised hogya

//         // process first window
//         // find no of zeroes 
//         int cnt0=0;
//         for(int i=0;i<k;i++){
//             if(nums[i]==0) cnt0++;
//         }

//         ans=min(ans,cnt0);

//         // process remaining windows   // % use krege to handle circluar
//         int n=nums.size();
//         for(int i=k;i<=(n-1)+k-1;i++){ // __ +k-1 kiya to handle circle nature...... last element ki window tak chahie hume
//         // new ke liye add if req
//         if(nums[i%n]==0) cnt0++;
//         // out of window ke liye remove if req
//         if(nums[(i-k)]==0) cnt0--;

//         ans=min(ans,cnt0);
//         }

//         return ans;

//     }
// };


