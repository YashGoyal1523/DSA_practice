//lc 402

//https://youtu.be/lWcZB7l-O7M?si=M5Ctstl1gIQSGCo1


// likhne ka tarika 1

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st; 
        int i=0;
        while(i<num.size()) {
            char digit=num[i];
            // Remove digit from the stack if it is greater than the current digit and we still need to remove more digits (k > 0)
            if (!st.empty()){
            if( st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            else {
                st.push(digit);
                i++;
            }
            }
            else{
             st.push(digit);
             i++;
            }
        }

        // If k > 0, remove additional digits from the top of the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result string from the stack
        string temp;
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        // Remove leading zeros
        int x = 0;
        while (x < temp.size() && temp[x] == '0') x++;
        string ans(temp.begin() + x, temp.end());

        // If the result is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};


// likhne ka tarika 2

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st; 
        int i=0;
        while(i<num.size()) {
            char digit=num[i];
            // Remove digits from the stack if they are greater than the current digit and we still need to remove more digits (k > 0)
            if (!st.empty()){
            if( st.top() > digit && k > 0) {
                st.pop();
                k--;
            }
            else {
                st.push(digit);
                i++;
            }
            }
            else{
             st.push(digit);
             i++;
            }
        }

        // If k > 0, remove additional digits from the top of the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result string from the stack
        string temp;
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        // Remove leading zeros
        int x = 0;
        while (x < temp.size() && temp[x] == '0') x++;
        string ans(temp.begin() + x, temp.end());

        // If the result is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};