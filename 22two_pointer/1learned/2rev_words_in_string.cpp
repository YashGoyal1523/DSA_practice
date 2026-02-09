//lc 151


// m1 stack (khud)

class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!="") st.push(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        if(temp!="") st.push(temp);

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()) ans+=" ";
        }
        return ans;
    }
};

//mik
// https://youtu.be/mdej8UiRCkI?si=9Oa5sGqwiie7NsB1

// m2 stringstream

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";

        string result = "";
  
        while(ss >> token) {
            result = token + " " + result;
        }

        return result.substr(0, result.length()-1);
    }
};


//m3 two pointer

class Solution {
public:
    string reverseWords(string s) {
        //story
        //1. reverse whole string
        
        reverse(s.begin(), s.end());
        
        int i = 0;
        //hero honge hamare l and r jo revrese karenge words ko
        int l = 0, r = 0;
        
        int n = s.length();
        
        while(i < n) {
            while(i < n && s[i] != ' ') { //i ko agar char dikha to r ko dega and i++ and r++
                s[r++] = s[i++];
            }
            
            if(l < r) { //l     r
                reverse(s.begin()+l, s.begin()+r);
                
                s[r] = ' ';
                r++;
                
                l = r;
            }
            
            i++; //ye to badhta rahega
        }
        
        s = s.substr(0 , r-1);
        
        return s;
        
    }
};