//lc 394

// https://youtu.be/6yOWLXlWOJc?si=T7YxFO9VfDxoBG7q


class Solution {
public:
    string decodeString(string s) {
        stack<int>nst;
        stack<string>sst;
        int currno=0;
        string currstr="";
        
        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(ch>='0'&&ch<='9'){
                currno=currno*10+(ch-'0');
            }
            else if(ch=='['){
                nst.push(currno);
                currno=0;
                sst.push(currstr);
                currstr="";
            }
            else if(ch==']'){
                int prevno=nst.top();
                nst.pop();
                string prevstr =sst.top();
                sst.pop();
                string temp="";
                for(int x=1;x<=prevno;x++)  temp+=currstr;
                currstr=prevstr+temp;
                }
                
                else currstr.push_back(ch);
        }

        return currstr;
    }
};