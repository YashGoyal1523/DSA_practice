//lc 2185

// // bruteforce
// class Solution {
// public:
//     int prefixCount(vector<string>& words, string pref) {
//         int cnt=0;
//         for(int i=0;i<words.size();i++){
//             string word=words[i];
//             if(word.find(pref)==0) cnt++;
//         }
//         return cnt;
//     }
// };


// m2 trie