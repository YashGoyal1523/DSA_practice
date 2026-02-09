//lc 3439


//khud

//each k contigous events ki shifting se gap nikal lo jo bana skte ........sabme se max lelo


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
      
        int maxi = 0;

        //handle first window of size k
        int left = 0;
        int right = k==n?eventTime:startTime[k];  
        int sum = 0;
        // Calculate busy time for first `k` events
        for (int i = 0; i < k; i++) {
            sum += endTime[i] - startTime[i];
        }
        int total = right - left;
        int gap = total - sum;
        maxi = gap;

//handle rest windows
        int i = 0, j = k+1; //index for end pts
        while (j <= n) {  // index for right endpoint for last set is n
            left = endTime[i];
            right = (j == n) ? eventTime : startTime[j];

            sum += endTime[j-1] - startTime[j-1];  // Add new event
            sum -= endTime[i] - startTime[i];  // Remove old event

            total = right - left;
            gap = total - sum;
            maxi = max(gap, maxi);

            i++;
            j++;
        }

        return maxi;
    }
};

//mik

// https://youtu.be/JPWBTUyGCnM?si=cJ1JEuADb3_xFHCR


//shifting k contigous events combine unke k+1 gaps
//gaps ka array banalo
//->max sum k+1 size subbaray


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,    vector<int>& endTime) {
    int n=startTime.size();
       vector<int>gaps;
    
       gaps.push_back(startTime[0]-0);
       for(int i=1;i<n;i++){
        int gap=startTime[i]-endTime[i-1];
        gaps.push_back(gap);
       
       }
       gaps.push_back(eventTime-endTime[n-1]);

        int maxi=0;
        int currsum=0;

        //process first k+1 element
        for(int i=0;i<k+1;i++){
            currsum+=gaps[i];
        }
        maxi=max(currsum,maxi);

        //handle rest elements
        int i=0,j=k+1;
        while(j<gaps.size()){
            currsum+=gaps[j];
            currsum-=gaps[i];
            j++;
            i++;
            maxi=max(currsum,maxi);
        }

    return maxi;
    }
};
