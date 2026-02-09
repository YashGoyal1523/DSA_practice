// given array with n elements where elements are from range [1,n] . all the numbers in array can appear any times . find numbers from range not present in array

// eg : size 4 : range : [1,4]  : array can be  {1,1,2,2} -> missing 3,4  , {1,1,2,3}->missing 4 ....etc...


// method 1: 
// visit mark within array using negative marking method wala method 
// note : numbers are [1,n] and indexes are [0,n-1] toh number value wale index par mark krke nhi kar paayege....  number n and index 0 mein dikkat hojaygei  .......so numbers ko number-1 index par mark krke ie  1 ke liye 0 index par mark krlo, 2 ke liye 1 par and so on ese krke krlege
//  array mein shuru se traverse krte hue sab elements ke liye mark krdege phle fir mark ke baad saare check krege and jo jo positive nikla uska index+1 se ans miljayega..... 
// note mark krte hue koi phle se neg mile toh aage bhadd jana
// tc o(n) sc o(1)

// #include<iostream>
// using namespace std ;

// void missing(vector<int>nums){

//     //marking
//     for(int i=0;i<nums.size();i++){
//         int index=abs(nums[i])-1;
//         if(nums[index]>0){
//             nums[index]*=-1;
//         }
//     }
//     //checking
//      for(int i=0;i<nums.size();i++){
//         if(nums[i]>0){
//             cout<<i+1<<" ";
//         }
//      }
// }


// int main()
// {
//     vector<int>nums(4,1); //{1,1,1,1}
//     missing(nums);
// return 0;
// }


// method 2: positioning method : apne value wale index par pahuchana wala 
// note : value ko value-1 index par pahuchake krna pdega as indexes are [0,n-1] and nos are [1,n]
// shuru se start hoke sabko apni position par lagadege...fir last m shuru se sab check krege agar koi value and index+1 match na krre toh index+1 is ans
// note position par lagate hue agar position par phle se hi shi mile toh aage bhad jana


#include<iostream>
using namespace std ;

void missing(vector<int>nums){

    // positioning
    int i=0;
    while( i<nums.size()){
    
        int index=nums[i]-1;
        if(nums[index]!=nums[i]){
            swap(nums[index],nums[i]);
        }
        else i++;
    }
    //checking
     for(int i=0;i<nums.size();i++){
        if(nums[i]!=i+1){
            cout<<i+1<<" ";
        }
     }
}


int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(1);
    missing(nums);
return 0;
}