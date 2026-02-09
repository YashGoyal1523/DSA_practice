// // lc 1518

// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//        // initial full bottles
//         int fullbottles=numBottles;
//         // sab peegye
//         // hence empty bottles
//         int emptybottles=fullbottles;
//         //drink count 
//         int drink=fullbottles;
        
        
//         while(emptybottles>=numExchange){
//             //emptybottles se exhange krke new fullbottles lelo
//             fullbottles=emptybottles/numExchange;
//             // new bottles ko bhi peegye
//             // hence now emptybottles (new pii hui full bottles + puraani empty remaining jo exchange nhi hui thi)
//             emptybottles=fullbottles+emptybottles%numExchange;
//             // drink count update
//             drink=drink+fullbottles;
            

//         }

//        return drink;
//     }
// };