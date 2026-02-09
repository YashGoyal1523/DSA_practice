//lc 2683

//m1 building original array
class Solution {
public:
  bool check(vector<int>& arr,vector<int>& derived){
    int n=derived.size();
     for(int i =1;i<n;i++){
            //  if(arr[i-1]==0&&derived[i-1]==0) arr[i]=0;
            //     if(arr[i-1]==0&&derived[i-1]==1) arr[i]=1;
            //     if(arr[i-1]==1&&derived[i-1]==0) arr[i]=1;
            //     if(arr[i-1]==1&&derived[i-1]==1) arr[i]=0;
            arr[i]=arr[i-1]^derived[i-1];                              // a^b=c => a^c=b  , b^c=a
            } if(arr[n-1]^arr[0]==derived[n-1]) return true;
                return false;
  }
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        vector<int>arr(n);
        arr[0]=0;
        bool ans1=check(arr,derived);
        arr[0]=1;
     bool ans2=check(arr,derived);
          
        return ans1||ans2;
    }
};

//m2
// we are using each element twice to construct the derived array
// The xor-sum of the derived array should be 0 since there is always a duplicate occurrence of each element.

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= derived[i];
        }
        if(ans == 0)return true;
        return false;
    }
};