//lc 383

//m1 map

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(int i=0;i<magazine.size();i++){
            mp[magazine[i]]++;
        }
        int flag=0;
        for(int i=0;i<ransomNote.size();i++){
            if(mp[ransomNote[i]]>0) mp[ransomNote[i]]--;
            else {
                flag=1;
                break;
            }
        }
        if(flag) return false;
        return true;
    }
};

//m2 sc o(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int i=0;
        int j=0;
        while(i<ransomNote.size()&&j<magazine.size()){
            if(ransomNote[i]==magazine[j]){
                i++;
                j++;
            }
            else j++;
        }

        return i==ransomNote.size();
    }
};