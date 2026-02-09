
// // 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

// // You are given an integer array nums.

// // In one move, you can choose one element of nums and change it to any value.

// // Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

 

// // Example 1:

// // Input: nums = [5,3,2,4]
// // Output: 0
// // Explanation: We can make at most 3 moves.
// // In the first move, change 2 to 3. nums becomes [5,3,3,4].
// // In the second move, change 4 to 3. nums becomes [5,3,3,3].
// // In the third move, change 5 to 3. nums becomes [3,3,3,3].
// // After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
// // Example 2:

// // Input: nums = [1,5,0,10,14]
// // Output: 1
// // Explanation: We can make at most 3 moves.
// // In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
// // In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
// // In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
// // After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
// // It can be shown that there is no way to make the difference 0 in 3 moves.
// // Example 3:

// // Input: nums = [3,100,20]
// // Output: 0
// // Explanation: We can make at most 3 moves.
// // In the first move, change 100 to 7. nums becomes [3,7,20].
// // In the second move, change 20 to 7. nums becomes [3,7,7].
// // In the third move, change 3 to 7. nums becomes [7,7,7].
// // After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.






// // Sort the array nums.
// // If the size of the array n is less than or equal to 4, return 0 since we can change  elements to get same elements in  array which results in a difference of 0.
// // for more
// // Calculate the minimum difference by changing elements in these combinations:
// // change the last 3 elements to kisi bhi element other than these three ki value m  ( kisi bhi  case m min and max will be 1st and 4th last element.... diff will be calculated bw 1st and 4th last element)
// // change the first 3 elements to kisi bhi element other than these three ki value m  (  diff will be calculated bw 4th and  last element)
// // change the first 1 and last 2 elements to kisi bhi element other than these three ki value m (  diff will be calculated bw 2ndt and 3rd last element)
// // change the first 2 and last 1 elements to kisi bhi element other than these three ki value m  (  diff will be calculated bw 3rd and 2nd last element)
// // The result will be the minimum of differences in these cases

// class Solution {
// public:
//     int minDifference(vector<int>& nums) {

//         sort(nums.begin(),nums.end());

//         int minVal = INT_MAX;

//         int n = nums.size();

//         if(n <= 4) return 0;

//         minVal = min(minVal, nums[n-4] - nums[0]);
//         minVal = min(minVal, nums[n-1] - nums[3]);
//         minVal = min(minVal, nums[n-2] - nums[2]);
//         minVal = min(minVal, nums[n-3] - nums[1]);

//         return minVal;
        
//     }
// };

