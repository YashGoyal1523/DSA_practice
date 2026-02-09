//lc 3333
//(iss ques ka easy version is lc 3330) (solved in /string/self )
// https://youtu.be/Rfmhi6krtJU?si=gYQiSmb-GazrhiB-


//method
// if no of unique characters >=k -> return all possible strings (which is given by product of freq of all char)
// else find no of invalid strings (strings jinki length < k) -> ans=total-invalid


//rec - tle

class Solution {
public:
    int M = 1e9+7;
    
    int solve(int i, int cnt, vector<int>& freq, int k) {
        if(cnt>=k) return 0;
        if(i == freq.size()) return 1; //found invalid string     
      
        long long result = 0;

        for(int take = 1; take <= freq[i]; take++) {
                result = (result + solve(i+1, cnt+take, freq, k)) % M;
        }

        return result;
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        //We have to now find count of invalid strings 
        int index=0;
        int cnt=0;
        long long invalidCount = solve(index, cnt, freq, k);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;

    }
};


//mem - tle

class Solution {
public:
    int M = 1e9+7;
   
    int solve(int i, int cnt, vector<int>& freq, int k, vector<vector<int>>&dp) {
        if(cnt>=k) return 0;
        if(i == freq.size())  return 1; //found invalid string
           
        if(dp[i][cnt] != -1) {
            return dp[i][cnt];
        }

        long long result = 0;

        for(int take = 1; take <= freq[i]; take++) {
            
                result = (result + solve(i+1, cnt+take, freq, k,dp)) % M;
           
        }

        return dp[i][cnt] = result;
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        int w=word.length();
        int index=0;
        int cnt=0;
        vector<vector<int>>dp(n+1, vector<int>(w+1, -1));
        long long invalidCount = solve(index, cnt, freq, k,dp);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;


    }
};

//tabu -tle

class Solution {
public:
    int M = 1e9+7;
   
    int solve(string word, vector<int>& freq, int k) {
        int n = freq.size();
        int w=word.length();
        
         vector<vector<int>>dp(n+1, vector<int>(w+1, 0));

        for(int cnt=0;cnt<k;cnt++) {
            dp[freq.size()][cnt]=1;
        }

    for(int idx=freq.size()-1;idx>=0;idx--){
        for(int cnt=k-1;cnt>=0;cnt--){
        long long result = 0;
        for(int take = 1; take <= freq[idx]; take++) {
               if(cnt+take<=w) result = (result + dp[idx+1][cnt+take]) % M;  // many of the cells are logically impossible — they represent configurations that can never occur in a valid construction // yeh if condtion daalni pdegi to avoid overflow 
               else break;
        }
        dp[idx][cnt] = result;
            }
        }

      return dp[0][0];
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        long long invalidCount = solve( word,freq, k);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;


    }
};

//space opt -tle
//ans of curr row depends on next row

class Solution {
public:
    int M = 1e9+7;
   
    int solve(string word, vector<int>& freq, int k) {
        int n = freq.size();
        int w=word.length();
        
         vector<int>curr(w+1,0); //currently on freq.size()-1 row
         vector<int>next(w+1,0); // currently on freq.size() row

        for(int j=0;j<k;j++) {
            next[j]=1;
        }

    for(int idx=freq.size()-1;idx>=0;idx--){
        for(int cnt=k-1;cnt>=0;cnt--){
        long long result = 0;
        for(int take = 1; take <= freq[idx]; take++) {
               if(cnt+take<=w) result = (result + next[cnt+take]) % M;   // many of the cells are logically impossible — they represent configurations that can never occur in a valid construction // yeh if condtion daalni pdegi to avoid overflow 
               else break;
        }
        curr[cnt] = result;
            }
        next=curr;
        }

      return next[0];
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        long long invalidCount = solve( word,freq, k);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;


    }
};

// sab tle degaa


// need optimisation -> use prefix sum

//optimised tabu - mle

class Solution {
public:
    int M = 1e9+7;
   
    int solve(string word, vector<int>& freq, int k) {
        int n = freq.size();
        int w=word.length();
        
         vector<vector<int>>dp(n+1, vector<int>(w+1, 0));

        for(int cnt=0;cnt<k;cnt++) {
            dp[freq.size()][cnt]=1;
        }

    for (int idx = n - 1; idx >= 0; idx--) {
            // Build prefix sum of dp[idx + 1]
            vector<int> prefix(w + 2, 0);
            for (int i = 0; i <= w; i++) {
                prefix[i + 1] = (prefix[i] + dp[idx + 1][i]) % M;
            }

            for (int cnt = k - 1; cnt >= 0; cnt--) {
                int l = cnt + 1;
                int r = cnt + freq[idx];

                if (l > w) {
                    dp[idx][cnt] = 0;
                } else {
                    r = min(r, w);
                    dp[idx][cnt] = (prefix[r + 1] - prefix[l] + M) % M;
                }
            }
        }

      return dp[0][0];
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        long long invalidCount = solve( word,freq, k);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;


    }
};

// mle dega

//optimised space optimisation - tle

class Solution {
public:
    int M = 1e9+7;
   
   int solve(string word, vector<int>& freq, int k) {
        int n = freq.size();
        int w = word.length();

        vector<int> curr(w + 1, 0), next(w + 1, 0);

        for (int cnt = 0; cnt < k; cnt++) {
            next[cnt] = 1;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            // build prefix sum of `next`
            vector<int> prefix(w + 2, 0);
            for (int i = 0; i <= w; i++) {
                prefix[i + 1] = (prefix[i] + next[i]) % M;
            }

            for (int cnt = k - 1; cnt >= 0; cnt--) {
                int l = cnt + 1;
                int r = cnt + freq[idx];

                if (l > w) {
                    curr[cnt] = 0;
                } else {
                    r = min(r, w);
                    curr[cnt] = (prefix[r + 1] - prefix[l] + M) % M;
                }
            }

            next = curr;
        }

        return next[0];
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        long long invalidCount = solve( word,freq, k);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;


    }
};
//yeh bhi tle



// LOGIC MEIN OPTIMISATION ->optimising the recursive solve fn

//rec -tle

class Solution {
public:
    int M = 1e9+7;
    
    int solve(int i, int count, vector<int>& freq, int k) {
        if(i == freq.size()) return 1; //found invalid string
            
        long long result = 0;

        for(int take = 1; take <= freq[i]; take++) {
            if(count + take < k) { 
                result = (result + solve(i+1, count+take, freq, k)) % M;
            } else {  //early break
                break;
            }
        }

        return result;
    }


    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        //We have to now find count of invalid strings 
        int index=0;
        int cnt=0;
        long long invalidCount = solve(index, cnt, freq, k);

        //return (P - invalidCount ); //yeh negative jaa skta h as mod use kiya h jagah jagah so do
        return (P-invalidCount+M)%M;

    }
};

//mem -tle

class Solution {
public:
    int M = 1e9+7;

    int solve(int i, int cnt, vector<int>& freq, int k,vector<vector<int>> &dp) {
        if(i == freq.size()) return 1;
            
        if(dp[i][cnt] != -1) {
            return dp[i][cnt];
        }

        long long result = 0;

        for(int take = 1; take <= freq[i]; take++) {
            if(cnt + take < k) {
                result = (result + solve(i+1, cnt+take, freq, k,dp)) % M;
            } else {
                break;
            }
        }

        return dp[i][cnt] = result;
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        int cnt=0;
        int index=0;
        vector<vector<int>> dp(n+1, vector<int>(k, -1)); 
        //We have to now find count of invalid strings 
        long long invalidCount = solve(index, cnt, freq, k,dp);

        return (P - invalidCount + M) % M;


    }
};


//tabu - tle

class Solution {
public:
    int M = 1e9+7;

    int solve( vector<int>& freq, int k) {
        int n = freq.size();
        vector<vector<int>> dp(n+1, vector<int>(k, -1)); 
        
        for(int cnt=0;cnt<k;cnt++){
            dp[freq.size()][cnt]=1;
        }
            
       for(int i=freq.size()-1;i>=0;i--){
        for(int cnt=k-1;cnt>=0;cnt--){
            long long result = 0;
            for(int take = 1; take <= freq[i]; take++) {
            if(cnt + take < k) {
                result = (result + dp[i+1][cnt+take]) % M;
            } else {
                break;
            }
        }
         dp[i][cnt] = result;
        }
       }
        
        
    return dp[0][0];        
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        long long invalidCount = solve( freq, k);

        return (P - invalidCount + M) % M;


    }
};


// need optimisation -> use prefix sum

//optimised tabu - chaljayega


class Solution {
public:
    int M = 1e9+7;

    int solve( vector<int>& freq, int k) {
        int n = freq.size();
        vector<vector<int>> dp(n+1, vector<int>(k, 0));  // 0 se initialiise hoga
        
        for(int cnt=0;cnt<k;cnt++){
            dp[freq.size()][cnt]=1;
        }
            
       for(int i=freq.size()-1;i>=0;i--){
        vector<int> prefix(k+1, 0);
            for(int h = 1; h <=k; h++) {
                prefix[h] = (prefix[h-1] + dp[i+1][h-1]) % M;
            }
        for(int cnt=k-1;cnt>=0;cnt--){
                int l = cnt + 1;
                int r = cnt + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    dp[i][cnt] = (prefix[r+1] - prefix[l] + M) % M;
                }
        }
       }
        
        
    return dp[0][0];        
    }

    int possibleStringCount(string word, int k) {
        if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        
        long long invalidCount = solve( freq, k);

        return (P - invalidCount + M) % M;


    }
};

