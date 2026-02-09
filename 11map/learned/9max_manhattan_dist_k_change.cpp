//lc 3443

// https://youtu.be/LjgDv-WeXfM?si=iYGfiXij2XdTgDIZ

class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E')
                east++;
            else if (s[i] == 'W')
                west++;
            else if (s[i] == 'N')
                north++;
            else if (s[i] == 'S')
                south++;

            int currMD = abs(east - west) + abs(north - south);
            int steps = i + 1;
            if(steps>currMD){
                //steps waste hue h (as max manhattan distance possible after n steps is n)
                int wastedval=steps-currMD;
                int extraval=min(2 * k, wastedval);  // 2*k as ek step badalne  pe 2 val ka change hoga and atmost k changes kr skte
                currMD+=extraval;
            }
            maxMD = max(maxMD, currMD);
        }
        return maxMD;
    }
};