//lc 973

//note: sqrt returns in double

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;

        for(int i=0;i<points.size();i++){
            int pt1=points[i][0];
            int pt2=points[i][1];
            pq.push({sqrt(pt1*pt1+pt2*pt2),{pt1,pt2}});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


// note hum sqrt((x1 - x2)^2 + (y1 - y2)^2) ki jagah (x1 - x2)^2 + (y1 - y2)^2  mein bhi kr skte h comparison

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;

        for(int i=0;i<points.size();i++){
            int pt1=points[i][0];
            int pt2=points[i][1];
            pq.push({(pt1*pt1+pt2*pt2),{pt1,pt2}});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};