//lc 338




//m1 o(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int num = i;
            while (num > 0) {
                if (num & 1) count++;  // Check last bit
                num >>= 1;             // Shift right
            }
            ans.push_back(count);
        }
        return ans;
    }
};


// m2

class Solution {
public:
int solve(int n){
    int count=0;
    while(n>0){
        n=n&(n-1);
        count++;
    }
    return count;
}
    vector<int> countBits(int n) {
      vector<int>ans;
      for(int i=0;i<=n;i++){
        ans.push_back(solve(i));
      }  

      return ans;
    }
};


// m2 o(n)

class Solution {
public:

    vector<int> countBits(int n) {
      vector<int>ans;
      for(int i=0;i<=n;i++){  
        ans.push_back(__builtin_popcount(i));  //o(1)
      }  

      return ans;
    }
};


// m3 o(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        
        
        result[0] = 0;
        
        for(int i = 1; i<= n; i++) {
            
            if(i%2 == 0) {
                result[i] = result[i/2];
            } else {
                result[i] = result[i/2] + 1;
            }
            
        }
        
        return result;
        
    }
};
