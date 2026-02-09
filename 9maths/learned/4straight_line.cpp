// lc 1232

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
         if(coordinates.size() <= 2) return true;
        //point 1
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        //point 2
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        
        for(int i=2;i<coordinates.size();i++){
            //point 3
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if((y2 - y1) * (x1 - x) != (y1 - y) * (x2 - x1)) //check whether slope bw point 1 and 2 and bw point 1 and 3 is same or not  // slope = y2-y1/x2-x1      // y2-y1/x2-x1 != y1-y/x1-x nhi kiya as niche 0-0 aa skta toh divide by zero m dikkat aajayegi islye transpose krke ..multiply ki terms rkhli toh * 0 mein koi dikkat ni hogi
                return false;
        }
        return true;
    }
};