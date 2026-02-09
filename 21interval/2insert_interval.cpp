//lc 57

// m1
// newInterval ko intervals array mein daaldo fir lc 56 (merge intervals) krdo

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
      vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    
    int interStart=intervals[0][0];
    int interEnd=intervals[0][1];
    int i=1;
    while(i<intervals.size()){
        int currStart=intervals[i][0];
        int currEnd=intervals[i][1];
        if(currStart<=interEnd){
           interEnd=max(interEnd,currEnd);
           i++;
        }
        else{
            ans.push_back({interStart,interEnd});
            interStart=currStart;
            interEnd=currEnd;  
            i++;  
        }
       
    }
     ans.push_back({interStart,interEnd});

     return ans;
    }
};


//m2
// insert krte hue hi sab handle krna
//strivrer
//https://youtu.be/xxRE-46OCC8?si=AEwkn8er5EfBWqBB

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>>ans;
       int n=intervals.size();
       int news=newInterval[0];
       int newe=newInterval[1];
       int i=0;
       //left side
       while(i<n&&intervals[i][1]<news){
        ans.push_back(intervals[i]);
        i++;
       }
       //insertion with handling overlapping
       while(i<n&&intervals[i][0]<=newe){    // <= aayega
        news=min(news,intervals[i][0]);
        newe=max(newe,intervals[i][1]);
        i++;
       }
       ans.push_back({news,newe});
       //right side
       while(i<n){
        ans.push_back(intervals[i]);
        i++;
       }

       return ans;
    }
};


//mik

// https://youtu.be/XXaVIDIbUn4?si=K_XtPWGRX0MWBHlf

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                break;
            } else {
                //Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        result.push_back(newInterval);
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};
