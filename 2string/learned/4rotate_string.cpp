//lc 796

// bruteforce:
// ek ek rotation krke dekhoo
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.length() != goal.length()) return false;
//         int length = s.length();

//         // Try all possible rotations of the string
//         for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
            
//             if (s == goal) return true;
//             // Perform one rotation
//             rotate(s.begin(), s.begin() + 1, s.end());
            
//         }
//         return false;
//     }
// };

// better: // Check if goal is a substring of s + s

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         // Check if s and goal have the same length
//         if (s.length() != goal.length()) return false;

//         // Check if goal is a substring of s + s
//         string concatenated = s + s;
//         return concatenated.find(goal) != string::npos;
//     }
// };
