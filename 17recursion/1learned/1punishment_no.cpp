// lc 2698
//https://youtu.be/SmnRAvkkohA?si=QZBgFFTRQkMXuc0I

//rec

//likhne ka tarika 1

class Solution {
    public:
    
        bool check(int i,int currsum,string s,int target){
            if(i==s.length()){
                return currsum==target;
            }
            if(currsum>target) return false;
    
            bool ans=false;
            for(int j=i;j<s.length();j++){
                string subs=s.substr(i,j-i+1); // i se j index ka substring
                int val=stoi(subs);
                bool aage=check(j+1,currsum+val,s,target);
                if(aage) {
                    ans=true;
                    break;
                }
            }
    
        return ans;
        }
       
        int punishmentNumber(int n) {
            int punish=0;
            for(int num=1;num<=n;num++){
                int sq=num*num;
                string s=to_string(sq);
                if(check(0,0,s,num)){
                    punish+=sq;
                }
            }
            return punish;
        }
    };

    // tarika 2


class Solution {
    public:
    
        bool check(int i,int currsum,string s,int target){
            if(i==s.length()){
                return currsum==target;
            }
            if(currsum>target) return false;
    
            for(int j=i;j<s.length();j++){
                string subs=s.substr(i,j-i+1); // i se j index ka substring
                int val=stoi(subs);
                bool aage=check(j+1,currsum+val,s,target);
                if(aage) return true;
            }
    
        return false;
        }
    
        int punishmentNumber(int n) {
            int punish=0;
            for(int num=1;num<=n;num++){
                int sq=num*num;
                string s=to_string(sq);
                if(check(0,0,s,num)){
                    punish+=sq;
                }
            }
            return punish;
        }
    };


    // mem

    class Solution {
        public:
        
            bool check(int i,int currsum,string s,int target,vector<vector<int>>&dp){
                if(i==s.length()){
                    return currsum==target;
                }
                if(currsum>target) return false;
             if(dp[i][currsum]!=-1) return dp[i][currsum];
                for(int j=i;j<s.length();j++){
                    string subs=s.substr(i,j-i+1); // i se j index ka substring
                    int val=stoi(subs);
                    bool aage=check(j+1,currsum+val,s,target,dp);
                    if(aage==true) return dp[i][currsum]=true;
                }
        
            return dp[i][currsum]=false;
            }
        
            int punishmentNumber(int n) {
                int punish=0;
                for(int num=1;num<=n;num++){
                    int sq=num*num;
                    string s=to_string(sq);
                    int l=s.length();
                    vector<vector<int>>dp(l+1,vector<int>(num+1,-1));
                    if(check(0,0,s,num,dp)){
                        punish+=sq;
                    }
                }
                return punish;
            }
        };