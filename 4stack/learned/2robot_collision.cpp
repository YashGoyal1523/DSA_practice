// lc 2751 robot collisions


//// agar phle position wala R and usse agla wala L hoga toh collide krege

// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         unordered_map<int, pair<int, char>> m;
//         for (int i = 0; i < positions.size(); i++) {
//             m[positions[i]] = {healths[i], directions[i]};
//         }
//         vector<int> sortPos = positions;
//         sort(sortPos.begin(), sortPos.end());

//         stack<int> st;

//         for (int i = 0; i < sortPos.size(); i++) {   // agar phle wala R and baad wala L aayega toh collide krege
//             while (!st.empty() && m[sortPos[i]].first > 0&&m[st.top()].second == 'R' && m[sortPos[i]].second == 'L') {
//                 if (m[st.top()].first > m[sortPos[i]].first) {
//                     m[sortPos[i]].first = 0;
//                     m[st.top()].first--;
//                 } else if (m[st.top()].first == m[sortPos[i]].first) {
//                     m[sortPos[i]].first = 0;
//                     m[st.top()].first = 0;
//                     st.pop();
//                 } else { // m[st.top()].first == m[sortPos[i]].first
//                     m[st.top()].first = 0;
//                     st.pop();
//                     m[sortPos[i]].first--;
                    
//                 }
                
//             }
//             if(m[sortPos[i]].first > 0) {    
//                 st.push(sortPos[i]);
//             }
//         }

//         vector<int> ans;
//         for (int i = 0; i < positions.size(); i++) {
//             if (m[positions[i]].first != 0) {
//                 ans.push_back(m[positions[i]].first);
//             }
//         }
//         return ans;
//     }
// };
