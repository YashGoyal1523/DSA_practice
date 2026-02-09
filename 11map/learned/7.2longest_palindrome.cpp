//lc 409

// sab characters pair mein dalege
// koi ek character single dalega

//likhne ka tarika 1
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int ans=0;

        for(int i=0;i<s.size();i++){ // pair dekhre
            if(mp[s[i]]>0){
                ans+=2;
                mp[s[i]]--;
            }
            else mp[s[i]]++;
        }
        // koi bhi ek single character
        for(auto i:mp){
            if(i.second>0) {
                ans+=1;
                break;
            }
        }
        return ans;
    }
};

//likhne ka tarika 2

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
         for(int i=0;i<s.size();i++) mp[s[i]]++;
        int ans=0;
        int single=0;
        for(auto i:mp){
            if(i.second==1) {
                single=1;
            }
            else if(i.second%2==0){
                ans+=i.second;
            }
            else{
                ans+=i.second-1;
                single=1;
            }
        }
        if(single) ans++;
        return ans;
    }
};