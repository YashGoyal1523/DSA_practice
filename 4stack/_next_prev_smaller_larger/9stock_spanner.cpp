//lc 901

// https://youtu.be/eay-zoSRkVc?si=MkLHPyflNNLmGTdQ

//m1 bruteforce
//ek array lelege
//usme daalte jayege current element
//for finding count current element se piche traverse krke check krlege

//m2 stack
//we will use previous greater element concept
class StockSpanner {
public:
    int idx;
    stack<pair<int,int>>st; // element,index
    StockSpanner() {
       idx=-1;
    }
    int next(int price) {
        idx++;
        while(!st.empty()&&st.top().first<=price){
            st.pop();
        }
       int cnt=idx-(st.empty()?-1:st.top().second);
        st.push({price,idx});
        return cnt;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */