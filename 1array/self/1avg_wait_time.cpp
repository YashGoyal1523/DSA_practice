// lc 1701

// class Solution {
// public:
//     double averageWaitingTime(vector<vector<int>>& customers) {
        
//         double totaltime=0;
//         int arrivetime=0;
//         int endtime=0;
//         int starttime=0;
//         for(int i=0;i<customers.size();i++){

//                 arrivetime=customers[i][0];
//                 if(endtime<arrivetime){
//                     starttime=arrivetime;
//                 }
//                 else{
//                     starttime=endtime;
//                 }
//                 endtime=starttime+customers[i][1];
//                 int waittime=endtime-arrivetime;
//                 totaltime=totaltime+waittime;
                  
//         }
//         return totaltime/customers.size();
//     }
// };