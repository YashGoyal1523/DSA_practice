// lc 1154

class Solution {
public:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }

    int dayOfYear(string date) {
        int y=stoi(date.substr(0,4));
        int m=stoi(date.substr(5,2));
        int d=stoi(date.substr(8,2));

        // precomputing no of days upto any month no.  ...... in non leap year
         int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; // index represent month no.

         int priorMonthsDays=days[m-1];
         int currMonthDays=d;

         int ans=priorMonthsDays+currMonthDays;
        // if leap yr and feb se aage wala month h then add 1
          if (m> 2 && isLeapYear(y)) {
            ans++;
        }
        
        return ans;
        
    }
};