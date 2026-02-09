// lc 1415

//https://youtu.be/sQ1gHiDtcXg?si=v6V4iXq30GgPr_vK


class Solution {
    public:
        void solve(int n, string& curr, vector<string>& result) { 
    if (curr.length() == n) { 
    result.push_back(curr); 
    return; 
    } 
    for(char ch = 'a'; ch <= 'c'; ch++) { 
    if(!curr.empty() && curr.back() == ch) 
    continue; 
    //Do 
    curr.push_back(ch); 
    //Explore 
    solve(n, curr, result); 
    //Undo 
    curr.pop_back(); 
    } 
    } 
    string getHappyString(int n, int k) { 
    string curr = ""; 
    vector<string> result; 
    solve(n, curr, result);
    if(result.size()<k) return "";
    return result[k-1];
        }
    };


    //slight optimisation in space

    class Solution {
        public:
            void solve(int n, string& curr, int &cnt,int &k,string &result) { 
        if (curr.length() == n) { 
        cnt++; 
        if(cnt==k) {
            result=curr;
        }
        return;
        } 
        for(char ch = 'a'; ch <= 'c'; ch++) { 
        if(!curr.empty() && curr.back() == ch) 
        continue; 
        //Do 
        curr.push_back(ch); 
        //Explore 
        solve(n, curr, cnt,k,result); 
        //Undo 
        curr.pop_back(); 
        } 
        } 
        string getHappyString(int n, int k) { 
        string curr = ""; 
        int cnt=0;
        string result="";
        solve(n, curr, cnt,k,result);
        if(cnt<k) return "";
        return result;
            }
        };