// lc 3394


// x dir alag uthao , y dir alag uthao
//rectangle ke starting pt and ending pt (x coordinates if x dir m dekhre , y coordinates if y dir m dekhre) ko ek interval banao ...saare intervals mein merge intervals  krdo (lc56) (thoda change ki merge tab krna jab end1>start2).....merge krne ke baaad if no of intervals >=3 then possible in this dir 
// (horizontal) x dir mein dekhlo ...x coordinates use krke for starting ending pt
// (vertical) y dir mein dekhlo...y coordinates use krke for starting ending pt
// kisi m bhi possible toh answer is yes

class Solution {
public:


bool merge(vector<vector<int>>&intervals){
           vector<vector<int>> ans ; 
        int n = intervals.size() ;
        sort(intervals.begin(),intervals.end()) ;

        int i=0 ;    

        while(i<n) {
            int start = intervals[i][0] ;
            int end = intervals[i][1] ;
            

            while(i<n && end > intervals[i][0]) { //merge krna jab end1>start2 
                end = max(end,intervals[i][1]) ;
                i++ ;
            }

            ans.push_back({start,end}) ;
        }

        return ans.size()>2;
        
}

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x;
        vector<vector<int>>y;
        for(auto i:rectangles){
            x.push_back({i[0],i[2]});
            y.push_back({i[1],i[3]});
        }
        bool ansx=merge(x);
        bool ansy=merge(y);

        return ansx||ansy;
    }
};