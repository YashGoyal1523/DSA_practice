//lc 3330

class Solution {
public:
    int possibleStringCount(string word) {
        vector<int>freq(26,0);
        int ans=1;// original string ko gin liya ie no mistyping
        for(int i=1;i<word.size();i++){
          if(word[i]==word[i-1]) ans++;
        }
    
        return ans; 
    }
};