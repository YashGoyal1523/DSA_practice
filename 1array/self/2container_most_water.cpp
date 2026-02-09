// lc 11

// nested loops se har pair of dande ka area nikalke max wala lena :o(n^2) : tle dega

// better : two pointer : o(n)
// dono end ke dando pe khade hojao
// area nikal lo
// chote wale dande ko khiskado 
// area nikal lo
// fir chota khiska do
// area nikal lo
// ...ese krte jao bich m ek dande tak rhne tak
// max maintain krte jaana

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;

        int ans=INT_MIN;
        while(i<j){
            if(height[i]<=height[j]){
                int area=(j-i)*height[i];
                ans=max(area,ans);
                i++;
            }
            else{  // height[j]<height[i]
                int area=(j-i)*height[j];
                ans=max(area,ans);
                j--;
            }

        }
        return ans;
    }
};