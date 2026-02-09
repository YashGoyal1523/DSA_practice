// lc 1408


// m1-bruteforce
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j) continue;
                if(words[j].find(words[i])!=string::npos) {
                    ans.push_back(words[i]);
                    break; // taaki repeated na dale
                }
            }
        }

        return ans;
    }
};

// m2- kmp algo
//https://youtu.be/BsR6ZVwxrvE?si=KtVntqrsjya0wcJ5



// m3 trie

// /string/ learned mein h
// /trie/learned mein h
