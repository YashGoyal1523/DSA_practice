//lc 983

//explore all possible ways

// method 1 : 2d dp : khud kiya
// days array mein traverse kro ...har travel wale day pe dekho ..agar uska pass le rkha toh agle pe jao vrna uss din teeno paas leke aage ka ans nikalo ese hi and teeno ka min lo

//rec
class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,int index,int validity){
        if(index>=days.size()) return 0;

        int money=0; 
        if(days[index]<=validity){  // pass kharid rkha is din  ka 
            money=solve(days,costs,index+1,validity);
        }
        else{ // pass lena pdega 
            int option1=costs[0]+solve(days,costs,index+1,days[index]+1-1);  // -1 as current day ne ek use krliya
            int option2=costs[1]+solve(days,costs,index+1,days[index]+7-1);
            int option3=costs[2]+solve(days,costs,index+1,days[index]+30-1);

            money=min(option1,min(option2,option3));
        }

        return money;

    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int index=0;
        int validity=0;
        int ans=solve(days,costs,index,validity);
        return ans;
    }
};

// mem
class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,int index,int validity, vector<vector<int>>&dp){
        if(index>=days.size()) return 0;

        if(dp[index][validity]!=-1) return dp[index][validity];

        int money=0;
        if(days[index]<=validity){
            money=solve(days,costs,index+1,validity,dp);
        }
        else{
            int option1=costs[0]+solve(days,costs,index+1,days[index]+1-1,dp);
            int option2=costs[1]+solve(days,costs,index+1,days[index]+7-1,dp);
            int option3=costs[2]+solve(days,costs,index+1,days[index]+30-1,dp);

            money=min(option1,min(option2,option3));
        }

        return dp[index][validity]=money;

    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int index=0;
        int validity=0;
        vector<vector<int>>dp(n+1,vector<int>(400,-1));
        int ans=solve(days,costs,index,validity,dp);
        return ans;
    }
};

// method 2 : 1d dp
//phle travel day ko currday leke shuru hojao...uspe teeno paas leke aage ka ans nikalo and teeno ka min lo
//aage ka ans nikalne k liye ... ab next currday banjayega prev currday+1/7/30.....ab next currday agar travel day h toh ese hi uspe teeno paas leke aage bhado...agar voh travel day nhi h toh ek ek din aage bhadate jao jabtak travel day na mile....travel day milke fir uspe process lagao
// ese krte jao...curr day banate jao and har travel day pe pass leke krte jao....ese krte jao jabtak last travel day cross na hojaye
// konse konse travel day h yeh dekhne k liye map m store krlo phle saare travel days


// rec
class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,unordered_map<int,bool>&travelday,int currday){
        if(currday>days[days.size()-1]) return 0;

        int money=0;
        if(travelday.find(currday)==travelday.end()){
            money=solve(days,costs,travelday,currday+1);
        }
        else{
            int option1=costs[0]+solve(days,costs,travelday,currday+1);
            int option2=costs[1]+solve(days,costs,travelday,currday+7);
            int option3=costs[2]+solve(days,costs,travelday,currday+30);


            money=min(option1,min(option2,option3));
        }

        return money;

    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,bool>travelday;
        for(auto i:days){
            travelday[i]=true;
        }
        int currday=days[0];
        int ans=solve(days,costs,travelday,currday);
        return ans;
    }
};

// mem

class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,unordered_map<int,bool>&travelday,int currday,vector<int>&dp){
        if(currday>days[days.size()-1]) return 0;

        if(dp[currday]!=-1) return dp[currday];
        int money=0;
        if(travelday.find(currday)==travelday.end()){
            money=solve(days,costs,travelday,currday+1,dp);
        }
        else{
            int option1=costs[0]+solve(days,costs,travelday,currday+1,dp);
            int option2=costs[1]+solve(days,costs,travelday,currday+7,dp);
            int option3=costs[2]+solve(days,costs,travelday,currday+30,dp);


            money=min(option1,min(option2,option3));
        }

        return dp[currday]=money;

    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,bool>travelday;
        for(auto i:days){
            travelday[i]=true;
        }
        int currday=days[0];
        vector<int>dp(400,-1);
        int ans=solve(days,costs,travelday,currday,dp);
        return ans;
    }
};