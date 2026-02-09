//lc 42

//m1 khudka

// har bar pe dekho uske uper kitna paani store hoga and add krte jao
// For any bar at index i, the amount of water it can trap depends on:
// -The tallest bar to its left (leftMax[i]).
// -The tallest bar to its right (rightMax[i]).
// -The height of the bar itself (height[i]).
// water will be stored on bar if leftmax as well as right max is more than its height 
// The water trapped at index i is the difference between the smaller of the two heights (min(leftMax[i], rightMax[i])) and the height of the bar itself (height[i]).

//will use prefix suffix array

//sc: o(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prevmax(n); //excluding curr
        prevmax[0]=-1;
        for(int i=1;i<n;i++){
            prevmax[i]=max(prevmax[i-1],height[i-1]);
        }
        vector<int>nextmax(n); //excluding curr
        nextmax[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            nextmax[i]=max(nextmax[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prevmax[i]>height[i]&&nextmax[i]>height[i]){
                 ans+=(min(prevmax[i],nextmax[i])-height[i]);
            }
        }
        return ans;
    }
};


// note: agar prevmax and nextmax incl curr krke kare toh ese kr skte

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prevmax(n); //incl curr
        prevmax[0]=height[0];
        for(int i=1;i<n;i++){
            prevmax[i]=max(prevmax[i-1],height[i]);
        }
        vector<int>nextmax(n);  // inc curr
        nextmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            nextmax[i]=max(nextmax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            
                 ans+=(min(prevmax[i],nextmax[i])-height[i]);
            
        }
        return ans;
    }
};

//note:yeh prevmax array na banake space bacha skte h.....  jab ans nikalne wala loop chlra usi m saath saath phle leftmax ka krtejao




//m2 stack