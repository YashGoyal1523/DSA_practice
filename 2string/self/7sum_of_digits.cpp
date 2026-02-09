//lc 1945

class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=to_string(s[i]-96);
        }
        while(k--){
        int sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=(temp[i]-'0');
        }
        if(sum<10) return sum;
        temp=to_string(sum);
        }
        int ans=stoi(temp);
        return ans;
    }
};