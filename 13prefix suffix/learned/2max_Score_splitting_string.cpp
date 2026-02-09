// lc 1422

//m1 bruteforce
//for every i ...find zeroes in 0 to i and ones in i+1 to n-1 and sum lelo....max sum is ans

// m2 prefix suffix

class Solution {
public:
    int maxScore(string s) {
                int n=s.size();

        if(s.find("0")==string::npos ||s.find("1")==string::npos ) return n-1;

        vector<int>pre(n); // prefix zeroes // inc curr
        vector<int>suf(n); //suffx ones // excl curr

        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') cnt++;
            pre[i]=cnt;
        }
        cnt=0;
         for(int i=n-1;i>=0;i--){
            suf[i]=cnt;
            if(s[i]=='1') cnt++; 
        }

        int ans=0;
        for(int i=0;i<n-1;i++){//hum jis index pe h uspe kaatre string ko and usse index ko left substring m rkhkre ie left ka end h voh and uske aage wala right substring banega.......toh  second last tak chalayge as voh last splitting possibility h
            ans=max(ans,pre[i]+suf[i]);
        }

return ans;

    }
};


//m3 

// likhne ka tarika 1
class Solution {
public:
    int maxScore(string s) {
        int total_ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int left_zeros = 0; // inc curr
        int left_ones = 0; // inc curr
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                left_ones++;
            } else {
                left_zeros++;
            }
            int right_ones=total_ones-left_ones; // exc curr
            ans = max(ans, left_zeros + right_ones);
        }
        
        return ans;
    }
};


//likhne ka tarika 2
class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};