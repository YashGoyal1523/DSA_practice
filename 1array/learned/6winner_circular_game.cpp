// lc 1823

// tip : jab bhi ques esa ho ki circular manner mein kuch system chlra ho  toh soch skte ki khi (%) modulus (gives remainder)ka use toh nhi isme kuch ,ya double ended queue ka , ya doubly linked list ka , ya circular linked list ka

// m1 : array banake , % use krke effective index nikalte rhege  
// explanation k liye arrays mein 14.right shift _2 ka bottom dekhlo

// Initialize a vector 'circle' with integers from 1 to n (representing player nos)
// Set the initial index 'cur_ind' to 0 (1st player)
// Begin a while loop that continues until the length of circle is 1 (we've found a winner):
// Calculate the index 'next_to_remove' of the next person to be removed. ( next_to_remove = (cur_ind + k - 1) % circle.size() )     (note: yeh % wala unn cases m jisme array se aage nhi jaare usme koi dikkat nhi kregi...unme iska result vhi rhega jo phle h so no tension uski and aage jaane walo ko thik krdegi so sab shi h saare cases satisfied )   ( minus 1 kara as current bhi count krna hai next kth mein)
// Remove the element at 'next_to_remove' from circle.
// Update cur_ind to next_to_remove. //removed ke next par jaana ab and shift hoke removed ke next wala vhi aajayega
// Return the last remaining element in circle (winner original index). (will be present at 0 index)

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> circle;
//         for (int i = 1; i <= n; ++i) {
//             circle.push_back(i);
//         }
//         int cur_ind = 0;

//         while (circle.size() > 1) {
//             int next_to_remove = (cur_ind + k - 1) % circle.size();
//             circle.erase(circle.begin() + next_to_remove);
//             cur_ind = next_to_remove;
//         }

//         return circle[0];
//     }
// };

// m2 recursion
// we observe : ans for n players =  (ans for n-1 players) +  k  (current not counting)  (rotating)
// so recursion use krke solve krlege
// note:   ( ans for n-1 players)  +  k     mein (aage na chale jaaye ie) to handle rotations  we will do ( (ans for n-1 players) + k )%n  and find effective ans_pos
// note: % ke liye 0 indexing m solve krna pdega  , given 1 indexing (friends 1 se numbered h)

// class Solution {
// public:
// int solve(int n, int k ) {
// if(n == 1) {
// return 0;     // ek hi element m vhi winner h // 0 indexing : 0 hoga iska number
// }
// return (solve(n-1,k) + k) % n;
// }
// int findTheWinner(int n, int k) {
// int ans = solve(n,k) + 1;  // 0 based indexing liya h // +1 krdia taaki vaapis 1 indexing hojaaye
// return ans;
// }
// };