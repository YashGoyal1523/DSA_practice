//lc 2559

class Solution {
public:

    bool isvowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        return false;
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n=words.size();
    
       vector<int>pre(n);
       int cnt=0;
       for(int i=0;i<n;i++){
        int m=words[i].size();
        if(isvowel(words[i][0])&&isvowel(words[i][m-1])) cnt++;
        pre[i]=cnt;
       }
       vector<int>ans;
       for(int i=0;i<queries.size();i++){
        int right=pre[queries[i][1]];
        int left;
        if(queries[i][0]!=0) left=pre[queries[i][0]-1];
        else left=0;
        ans.push_back(right-left);
       }
        return ans;
    }
};