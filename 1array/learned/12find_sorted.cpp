//lc 3011

//m1 bubble sort

// class Solution {
// public:
//     int bits(int n) {
//         int cnt = 0;
//         while (n > 0) {
//             n = n & (n - 1);
//             cnt++;
//         }
//         return cnt;
//     }

//     bool canSortArray(vector<int>& nums) {
//         int n = nums.size();
        
//         for (int i = 0; i < n - 1; ++i) {
//             for (int j = 0; j < n - i - 1; ++j) {
//                 // Compare adjacent elements
//                 if (nums[j] > nums[j + 1]) {
//                     // Check if bit counts are the same
//                     if (bits(nums[j]) != bits(nums[j + 1])) {
//                         return false;
//                     }
//                     // Swap elements if bit counts are the same
//                     swap(nums[j], nums[j + 1]);
//                 }
//             }
//         }
        
//         return true;
//     }
// };


// Approach 2: Sortable Segments
// Intuition
// Upon closer examination of the allowed operation (or perhaps after reading the hint! :)), we find that we can divide the array into segments of consecutive elements with the same number of set bits. Since these elements can be swapped with one another, we could sort each segment individually. However, we are not permitted to change the order of the segments themselves, nor can we swap elements that belong to different segments, as they have different numbers of set bits.

// Therefore, we must verify that the segments are arranged correctly. Specifically, the maximum value of each segment (the one that would be the rightmost in its sorted order) must be less than or equal to the minimum value of the subsequent segment (the leftmost in its sorted order).

// Algorithm
// Initialize maxOfSegment and minOfSegment with the value of the first element of the array.
// Set numOfSetBits to the number of set bits of the first element of the array.
// Initialize maxOfPrevSegment to INT_MIN.
// Loop with i from 1 to n-1. In each iteration, consider the following cases:
// If the number of set bits of nums[i] matches that of the elements in the current segment, update (if needed) maxOfSegment and minOfSegment with the value of nums[i].
// Otherwise, nums[i] belongs to a new segment.
// If minOfSegment < maxOfPrevSegment return false.
// Update maxOfPrevSegment to maxOfSegment.
// Set maxOfSegment and minOfSegment to the value of nums[i]
// Update numOfSetBits with the number of set bits for nums[i].
// If the loop ends without returning false, segments are arranged correctly, so return true.
// Important: We can safely use the first element of the array to initialize our variables because the constraints guarantee that the array will not be empty (n≥1). However, in other situations, we should always account for this edge case.


// class Solution {
// public:
//     bool canSortArray(vector<int>& nums) {
//         // Number of set bits of the elements in the current segment
//         int numOfSetBits = __builtin_popcount(nums[0]);
//         int maxOfSegment = nums[0];
//         int minOfSegment = nums[0];

//         // Initialize max of the previous segment to the smallest possible
//         // integer
//         int maxOfPrevSegment = INT_MIN;

//         for (int i = 1; i < nums.size(); i++) {
//             if (__builtin_popcount(nums[i]) == numOfSetBits) {
//                 // Element belongs to the same segment
//                 // Update min and max values of the segment
//                 maxOfSegment = max(maxOfSegment, nums[i]);
//                 minOfSegment = min(minOfSegment, nums[i]);
//             } else {  // Element belongs to a new segment
//                 // Check if the segments are arranged properly
//                 if (minOfSegment < maxOfPrevSegment) {
//                     return false;
//                 }

//                 // Update the previous segment's max
//                 maxOfPrevSegment = maxOfSegment;

//                 // Start a new segment with the current element
//                 maxOfSegment = nums[i];
//                 minOfSegment = nums[i];
//                 numOfSetBits = __builtin_popcount(nums[i]);
//             }
//         }
//         // Final check for proper segment arrangement
//         if (minOfSegment < maxOfPrevSegment) {
//             return false;
//         }
//         return true;
//     }
// };


// Approach 3: Forward and Backward Pass
// Intuition
// To simplify the previous approach, we can utilize a two-pass method to determine whether the array can be sorted under the given constraints. In the first pass, we iterate through the array from left to right, aiming to move the maximum value of each segment as far to the right as possible by swapping adjacent elements when allowed.

// Then, in the second pass, we switch directions and iterate from right to left. This time, we focus on moving the minimum value of each segment as far to the left as possible.

// While we’re making these passes, if we come across a pair of elements that should be swapped but can't be—because they have different numbers of set bits—we immediately return false. This means that sorting the array under the given constraints isn't possible.

// Algorithm
// Get the length of the array, denoted as n.
// Make a copy values of the array, to avoid modifying the input.
// Iterate for i = 0 to i = n - 1. In each iteration, check the following conditions:
// If values[i] <= values[i+1], continue.
// Otherwise, the elements must be swapped, so that the greater (values[i]) moves to the right.
// If they have the same number of set bits, swap them.
// Else, return false.
// Iterate for i = n - 1 to i = 1. In each iteration, check the following conditions:
// If values[i] >= values[i-1], continue.
// Otherwise, the elements must be swapped, so that the smaller (values[i]) moves to the left.
// If they have the same number of set bits, swap them.
// Else, return false.
// If both loops end without returning false, return true.

// class Solution {
// public:
//     bool canSortArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> values = nums;  // Create a copy of the original array

//         // First Pass: Iterate from left to right
//         // Goal: Move the maximum value of each segment as far right as possible
//         for (int i = 0; i < n - 1; i++) {
//             // If the current element is less than or equal to the next,
//             // continue
//             if (values[i] <= values[i + 1]) {
//                 continue;
//             } else {
//                 // Check if the current and next element have the same number of
//                 // set bits
//                 if (__builtin_popcount(values[i]) ==
//                     __builtin_popcount(values[i + 1])) {
//                     swap(values[i], values[i + 1]);  // Swap them if they do
//                 } else {
//                     return false;  // Return false if they cannot be swapped
//                 }
//             }
//         }

//         // Second Pass: Iterate from right to left
//         // Goal: Move the minimum value of each segment as far left as possible
//         for (int i = n - 1; i >= 1; i--) {
//             // If the current element is greater than or equal to the previous,
//             // continue
//             if (values[i] >= values[i - 1]) {
//                 continue;
//             } else {
//                 // Check if the current and previous element have the same
//                 // number of set bits
//                 if (__builtin_popcount(values[i]) ==
//                     __builtin_popcount(values[i - 1])) {
//                     swap(values[i], values[i - 1]);  // Swap them if they do
//                 } else {
//                     return false;  // Return false if they cannot be swapped
//                 }
//             }
//         }

//         // If both passes complete without returning false, the array can be
//         // sorted
//         return true;
//     }
// };