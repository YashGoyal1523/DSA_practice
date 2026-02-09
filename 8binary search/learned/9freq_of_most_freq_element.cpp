//lc 1838

// https://youtu.be/iOqH_JnXIOQ?si=trkcHpFe7UJ2_kV5

//har element ko target value leke dekhege uski max freq kitni ho skti...sabme se max lelege
//->
//note:value increase hi kr skte and not decrease ..toh ek target element ke liye usse chote value wale elements mein hi dekhege
// note : target ki max possible freq chahie .... toh iske liye target se niche walo mein ...sabse bade element se shuru hoge ops krne and descending m nich jaayge
//phle sort krlege 
//fir one by one har element ko target lege and uski max freq possible nikalege
//for a target element hum nikal lege ki  usse start hoke backwards kitne no of elements tak no of operations required is <=k ... isse uski max frequency possible miljayegi 
//sabke ke liye krke ...sabse max lelege
//ab yeh no of elements nikalne wala linear search se krskte ie target idx se backwards shuru hojao and dekhte jao kaha tak valid h par constraints doesnt allow it
// -> binary search se krege
//binary search se min idx nikal lege jaha tak valid hai ...isse count miljayega .. target_idx-idx+1
//note: total no of operations required for a window is : (size of window)*target value - sum of window (new sum of window - old sum of window)
class Solution {
public:

    vector<long long>presum;

    int ops(int mid,int r,int target){
        //old sum of window
        long long oldval=presum[r]-(mid-1>=0?presum[mid-1]:0);
        //new sum of window
        int windowsize=r-mid+1;
        long long newval=(long long)windowsize*target;

        int ops=newval-oldval;

        return ops;
    }


    int bs(int i,int target, int k){
        int l=0;
        int h=i-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(ops(mid,i-1,target)<=k){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
       int n=nums.size();  
       presum.resize(n);
      presum[0]=nums[0];
      for(int i=1;i<n;i++){
        presum[i]=presum[i-1]+nums[i];
      }

      int ans=1;
      for(int i=1;i<n;i++){
        int target=nums[i];
        int idx=bs(i,target,k);
        if(idx!=-1){
        int currans=i-idx+1;
        ans=max(ans,currans);
        }
      }

      return ans;

    }
};