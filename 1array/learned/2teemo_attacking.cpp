// lc 495


// m1 

// saare seconds jispe poisoned h voh nikal lo .....fir count kr lo kitne seconds h
// THIS WILL GIVE TLE
// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         map<int,bool>m;
//         for(int i=0;i<timeSeries.size();i++){
//             int j=timeSeries[i];
//             while(j<timeSeries[i]+duration){
//                 if(m[j]!=true){         // nhi lagayege yeh toh bhi chal jaayega par hume pata h koi seconds repeat ho skti in different elements of timeseries so  kyu processing repeat kre for seconds jo already note krli h ..jo new aari usko kro
//                 m[j]=true;      
//                 } 
//                 j++;
//             }
//         }
// no of elements in map will give us the ans
//         int count=m.size();        
//         return count;
//     }
// };






// m2

// phle elements ke liye pura duration ginlo...fir aage walo ke liye uske piche wala dekho....agar curr wala piche wale ke duration khatm hone ke baad aara toh curr wale k liye pura duration lelo vrna agar phle hi aajara toh unka common wala hatake sirf curr wale ka extra wala lelo

// class Solution
// {
// public:
//     int findPoisonedDuration(vector<int> &timeSeries, int duration)
//     {
//         int count = 0;
//         // for 1st element
//         count = count + duration;
//         // for other elements
//         for (int i = 1; i < timeSeries.size(); i++)
//         {
//             if (timeSeries[i] - timeSeries[i - 1] >= duration)  // curr pichle ke khatm hone ke baad aara
//             {
//                 count += duration;
//             }
//             else     // curr phle hi aajara
//             {
//                 count += timeSeries[i] - timeSeries[i - 1];   // this will give us the extra time that curr wala have
//             }
//         }
//         return count;
//     }
// };