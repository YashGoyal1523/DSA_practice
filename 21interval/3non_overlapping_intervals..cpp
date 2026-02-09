//lc 435

//mik
// https://youtu.be/0TYKyTwGOAs?si=zOLAtEHzL8HWsFQ7


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int previdx=0; //prev interval idx
        int cnt=0;
        for(int i=1;i<intervals.size();i++){//curr interval idx
            int prevend=intervals[previdx][1];
            int currstart=intervals[i][0];
            int currend=intervals[i][1];
            if(currstart<prevend){ //overlapping
            // bada end point wala hatado
               if(prevend<=currend) cnt++;  
               else {
                cnt++;
                previdx=i;
               }
            }
            else{ // non overlap
                previdx=i;
            }
            
        }
        return cnt;
    }
};

//striver

// prerquisite ques

// n meetings in one room

// https://youtu.be/mKfhTotEguk?si=iXhUQJGwDP-aophi

//sort based on end points
// then start se traverse kro and non overlapping interval uthate jao ie voh interval uthate jao jo pichle se overlap nhi krra


class Solution {
  public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>>intervals;
        for(int i=0;i<start.size();i++){
            intervals.push_back({start[i],end[i]});
            
        }
        sort(intervals.begin(),intervals.end(),comp);

        int cnt=1;
        
        int previdx=0; //prev interval idx
        for(int i=1;i<intervals.size();i++){ // curr interval idx
            int prevend=intervals[previdx][1];
            int currstart=intervals[i][0];
            if(currstart>prevend){   // touch krne wale are overlapping isiliye > and not >=
                cnt++;
                previdx=i;
            }
        }
        return cnt;
    }
};


// now our ques
// min intervals to remove = total intervals - max no of non overlapping intervals

class Solution {
public:
static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(),comp);

        int cnt=1;
        
        int previdx=0; //prev interval idx
        for(int i=1;i<intervals.size();i++){ // curr interval idx
            int prevend=intervals[previdx][1];
            int currstart=intervals[i][0];
            if(currstart>=prevend){  // touch krne wale are not overlapping isiliye >= and not >
                cnt++;
                previdx=i;
            }
        }
        return intervals.size()-cnt;
    }
};