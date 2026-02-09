//lc 735

//stack lo
//left to right traverse kro array m
// right moving mile toh push krdo
// left moving mile toh stack m top element dekhna shuru kro..if stack is empty or if top is left moving toh push krdo current and aage travere kro...else if right moving mile toh compare magnitude and if stack wala chota then st se pop and firse top ko dekho  , if current chota then chodho isse and agle pe traverse kro if dono equal then st se pop kro current ko chodho and next pe traverse kro
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){  
            int flag=1; 
           if(asteroids[i]<0){ // left mvoing asteroid
            while(!st.empty()&&st.top()>0){ // right moving asteroid
                if(st.top()<abs(asteroids[i])) st.pop();
                 else if(st.top()==abs(asteroids[i])){
                    st.pop();
                    flag=0;
                    break;
                }
                else{
                    flag=0;
                    break;
                }
            }    
           }
           if(flag) st.push(asteroids[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};