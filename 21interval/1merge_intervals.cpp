// lc 56

// likhne ka tarika 1

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//     vector<vector<int>>ans;
//     sort(intervals.begin(),intervals.end());
    
//     int interStart=intervals[0][0];
//     int interEnd=intervals[0][1];
//     int i=1;
//     while(i<intervals.size()){
//         int currStart=intervals[i][0];
//         int currEnd=intervals[i][1];
//         if(currStart<=interEnd){
//            interEnd=max(interEnd,currEnd);
//            i++;
//         }
//         else{
//             ans.push_back({interStart,interEnd});
//             interStart=currStart;
//             interEnd=currEnd;  
//             i++;  
//         }
       
//     }
//      ans.push_back({interStart,interEnd});

//      return ans;

//     }
// };


// likhne ka tarika 2

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ans ; 
//         int n = intervals.size() ;
//         sort(intervals.begin(),intervals.end()) ;

//         int i=0 ;    

//         while(i<n) {
//             int start = intervals[i][0] ;
//             int end = intervals[i][1] ;

//             while(i<n && end >= intervals[i][0]) {
//                 end = max(end,intervals[i][1]) ;
//                 i++ ;
//             }

//             ans.push_back({start,end}) ;
//         }
//         return ans ;
//     }
// };



//tip:
// interval based ques : 
// approach -> sort based on start time / sort based on end time