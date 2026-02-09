
// lc 739

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
    stack<int>st;
    st.push(-1); //-1 for no ngi found
    for(int i=n-1;i>=0;i--){
        int curr=temperatures[i];
        while(st.top()!=-1&&temperatures[st.top()]<=curr){
            st.pop();
        }
        if(st.top()==-1) ans[i]=0;
       else ans[i]=st.top()-i;
        st.push(i);
    }
    return ans;
    }
};