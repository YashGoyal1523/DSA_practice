//lc 921

// stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(') st.push(ch);  // ( daalo
            else{
                if(st.empty()) {   // akela ) mila iske liye krna pdega 
                    cnt++;
                }
                else{   // ) ke liye ( kaato
                    st.pop();
                }
            }
        }
        while(!st.empty()) {  // akele ( milre iske liye krne pdege
            cnt++;
            st.pop();
        }

        return cnt;

    }
};