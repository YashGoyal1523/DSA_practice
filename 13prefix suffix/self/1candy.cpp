//lc 135

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<int>pre(n); // at an index...stores no of elements in dec order starting from that index behind it
        vector<int>next(n); // at an index...stores no of elements in dec order starting from that index ahead it
        pre[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                pre[i]=pre[i-1]+1;
            }
            else pre[i]=1;
        }
        next[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                next[i]=next[i+1]+1;
            }
            else next[i]=1;
        }
        int cnt=0;
        
        for(int i=0;i<n;i++){
            cnt+=(max(pre[i],next[i]));
        }
        
     return cnt;
            }
};