//lc 1475

class Solution {
public:
vector<int> nextSmallerOrEqual(vector<int>& prices)
{   int n=prices.size();
    stack<int> st;
    vector<int> ans(n);
    st.push(-1); //-1 for no next smaller or equal
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = prices[i];
        while (st.top()!=-1&&st.top() > curr)
        {
            st.pop();
        }
        ans[i]=st.top()==-1?prices[i]:prices[i]-st.top();
        st.push(curr);
    }
    return ans;
}     // tc o(n)

    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans=nextSmallerOrEqual(prices);
        return ans;
    }
};