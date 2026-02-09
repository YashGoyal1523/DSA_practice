//lc 1353

// https://youtu.be/7xa6JIuxAOo?si=fA8BxM2VEVocMtMQ

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events), end(events));
        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        int day = 1; 
        int i   = 0;
        int count = 0; 

        while(!pq.empty() || i < n) {
            
            if(pq.empty()) { //optimisation
                day = events[i][0];
            }

            while(i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()) {
                pq.pop(); //1 event attended on this day
                count++; //counting the result
            }

            day++;

            //skip those events whose endDay < day
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return count;
    }
};
