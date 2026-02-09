// lc 3169

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
            int cnt=0;
            int prevend=0;
            for(int i=0;i<meetings.size();i++){
                int start=meetings[i][0];
                int end=meetings[i][1];
                if(start<=days&&start>prevend){
                        cnt+=start-prevend-1;
    
                }
                  prevend=max(prevend,end);
              
            }
            if(days>prevend) cnt+=days-prevend;
            return cnt;
        }
    };