//lc 22

// https://youtu.be/7xkPbffc6w8?si=4AJCeDvmVvFV0jl_


// m1
// saare generate fir valid wale uthao



//m2 seedha valid generate
// valid -  at each index : no of ) <= no of )


class Solution {
public:
    void solve(int n,vector<string>&ans,string temp,int cnt1,int cnt2){
        if(cnt1==n&&cnt2==n){
            ans.push_back(temp);
            return;
        }
        // (
        if(cnt1!=n){
            temp.push_back('(');
            solve(n,ans,temp,cnt1+1,cnt2);
            temp.pop_back();
        }  
        // )
        if(cnt2<cnt1){
            temp.push_back(')');
            solve(n,ans,temp,cnt1,cnt2+1);
            temp.pop_back();
        }  

    return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        int cnt1=0;
        int cnt2=0;
        solve(n,ans,temp,cnt1,cnt2);

        return ans;
    }
};