//lc 1910. Remove All Occurrences of a Substring

// bruteforce
// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//          while(s.find(part)!=string::npos){
//         s.erase(s.find(part),part.length());
//     }
//     return s;
//     }
// };

// // stack se bhi kr skte h


// // find,erase ki implementation dekhlena thoda ..tc vgarah dekhlena



// better
// stack


class Solution {
    public:
    
        bool check(stack<char>st,string part){
            int j=part.size()-1;
            while(j>=0){
                if(st.top()==part[j]){
                    st.pop();
                    j--;
                }
                else return false;
            }
    
            return true;
        }
    
    
        string removeOccurrences(string s, string part) {
             stack<char>st;
             for(int i=0;i<s.size();i++){
                st.push(s[i]);
                if(st.size()>=part.size()){
                    if(check(st,part)){ // check if part string dala hai
                        int m=part.size();
                        while(m--){
                            st.pop();
                        }
                    }
                }
             }
             string ans="";
             while(!st.empty()){
                ans+=st.top();
                st.pop();
             }
    
             reverse(ans.begin(),ans.end());
             return ans;
        }
    };



    //optimal
    //kmp algo


     // /string mein h
    // learning/algos/kmp m h
    // learning/stack/learned m h 
    // learning/string/learned m h 
   
    