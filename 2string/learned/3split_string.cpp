// lc 1593

// https://youtu.be/sTzh1L7BkQA?si=mQL9mCOnKNyHdFB5

// class Solution
// {
// public:
//     void solve(string &s, int i, unordered_set<string> &st, int currCount, int &maxCount)
//     {
// //   if(currCount + (s.length() i) <= maxCount) {  // optimisation
// //    return;
// //    }
//         if (i == s.length())
//         {
//             maxCount = max(maxCount, currCount);
//             return;
//         }
//         for (int j = i; j < s.length(); j++)
//         {
//             string sub = s.substr(i, j - i + 1); // 0(n)
//             if (st.find(sub) == st.end())
//             {
//                 st.insert(sub);                               // DO
//                 solve(s, j + 1, st, currCount + 1, maxCount); // EXPLORE
//                 st.erase(sub);                                // UNDO
//             }
//         }
//         return;
//     }
//     int maxUniqueSplit(string s)
//     {
//         unordered_set<string> st;
//         int maxCount = 0;
//         int currCount = 0;
//         int i = 0;
//         solve(s, i, st, currCount, maxCount);
//         return maxCount;
//     }
// };

// same logic mein likhne ka tarika alag
// fn se return krwana ans

// class Solution
// {
// public:
//     int solve(string &s, int i, unordered_set<string> &st)
//     {
//         if (i == s.length())
//         {
//             return 0;
//         }
//         int maxcnt = 0;
//         for (int j = i; j < s.length(); j++)
//         {
//             string sub = s.substr(i, j - i + 1);
//             if (st.find(sub) == st.end())
//             {
//                 st.insert(sub);
//                 int cnt = 1 + solve(s, j + 1, st);
//                 maxcnt = max(maxcnt, cnt);
//                 st.erase(sub);
//             }
//         }
//         return maxcnt;
//     }
//     int maxUniqueSplit(string s)
//     {
//         unordered_set<string> st;
//         int i = 0;
//         int ans = solve(s, i, st);
//         return ans;
//     }
// };


