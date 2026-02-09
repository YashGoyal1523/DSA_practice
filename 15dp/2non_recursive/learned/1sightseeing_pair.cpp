//lc 1014

// score= values[i]+values[j]-(j-i) = values[i]+values[j]+i-j = (values[i]+i)+(values[j]-j)

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int prev_max=values[0]+0;  // store prev max value of (values[i]+i)
        int ans=0;
        for(int j=1;j<n;j++){
            int score=prev_max+values[j]-j;
            ans=max(ans,score);
            prev_max=max(prev_max,values[j]+j);
        }
        return ans;
    }
};