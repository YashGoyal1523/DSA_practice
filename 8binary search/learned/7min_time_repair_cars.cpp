// lc 2594

// possible value of time taken :  [min of array , max of array * n^2]  (ek car hai and min wala krdega , saari car max wala krega)
// search space : [min of array , max of array * n^2]

//m1 linearly space mein shuru se start hojao and phla valid milte hi ans milgya
//m2 space mein binary search se min valid dhundlo (binary search on answer)

// note: recognising hint of binary search on answer - 
//https://youtu.be/tOo5RX2pt0g?si=myAa72mjWDCWiXAs
// sab mechanics ko kuch kuch cars de skte h
// note: time taken to repair all the cars is the maximum time among all mechanics to complete their respective work
// minimise the maximum
// binary search on answer
// possible value of time taken :  [min of array , max of array * n^2]  (ek car hai and min wala krdega , saari car max wala krega)
// search space : [min of array , max of array * n^2]  
// minimum valid dhundlo

// valid function : for a time taken value , check if all cars can be repaired under that much total time , if yes then its valid
// check ke liye har mechanic ko max no of car dedo jo voh krdega under time constraint ....sab car hogyi toh yes vrna no

class Solution {
    public:
    
        bool check(long long mid,vector<int>& ranks, int cars){
            long long cnt=0;
            for(int i=0;i<ranks.size();i++){
                long long no=sqrt(mid / ranks[i]);
                cnt+=no;
                if(cnt>=cars) return true;                           
            }
            return false;
        }
    
    
    
        long long repairCars(vector<int>& ranks, int cars) {
            long long l=*min_element(ranks.begin(),ranks.end());
            long long h=(long long)*max_element(ranks.begin(),ranks.end())*cars*cars; // *max_element wala int mein aayega as vector is in int toh fir *car*car bhi int m hi hora as car bhi int h toh yeh out of range of int ja skta toh phle max wale ko long long m krlo before *car*car
            long long ans;
            while(l<=h){
                long long mid=l+(h-l)/2;
                if(check(mid,ranks,cars)){
                    ans=mid;
                    h=mid-1;
                }
                else l=mid+1;
            }
            return ans;
        }
    };