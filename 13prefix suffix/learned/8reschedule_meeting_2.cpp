// lc 3440

//ek ek krke har meeting ke liye dekhlo ki usko shift krke uss position pe kitna max gap banega....sabme se max lelo
//note:
//ek meeting ko 
//uthake left ya right rkh skte 
//left ya right khiska skte

//agar uthake rkh skte toh usse milega max gap vrna khiskake milega  
//agar uthake rkh skte ->max gap = left gap+right gap +meeting length
//uthake nhi rkh skte toh khiskake dekhege -> max gap = left gap+right gap

//https://youtu.be/nRQwEyJBW-I?si=uU4QpdLxpVSYEhuY
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; //store durations of free gaps

        freeArray.push_back(startTime[0]-0);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0); //excl curr
        vector<int> maxLeftFree(n, 0); //excl curr
        for(int i = n-2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }


        int result = 0;
        //Iterating on the freeArray .... ith gap represents i-1th event
        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1]; 

            
            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])) { // Moving completely out ...... note: yeh maxLeftFree[i-1] yaha i-1 hai...(ith gap represnts i-1th event ..toh i-1th gap ka leftmax dekhege)
                result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
            }
            else // shift left or right
            result = max(result, freeArray[i-1] + freeArray[i]);
        }

        return result;


    }
};