//lc 1394


//m1 use map

//tarika 1
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }
        
        int ans = -1;
        for(auto &it : mp) {
            if(it.first == it.second)
                ans = max(ans, it.first);
        }
        
        return ans;
    }
};

//tarika 2
//(Using fixed size array to store frequency)
//T.C : O(n)
//S.C : O(501) ~ O(1)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {0};

        for(int &num : arr) {
            freq[num]++;
        }

        for(int i = 500; i >= 1; i--) {
            if(freq[i] == i)
                return i;
        }

        return -1;
    }
};


//m2 
//no extra space

//tarika 1

class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int>());
        int ans=-1;
        int cnt=1;
        int prev=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]==prev) cnt++;
            else{
                if(cnt==prev){
                    ans=prev;
                    break;
                }
                cnt=1;
                prev=arr[i];
            }
        }
        if(ans==-1&&cnt==prev) ans=prev; // last ka handle

        return ans;
    }
};

//tarika 2

class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int>());
        int ans=-1;
        int cnt=1;
        int prev=arr[0];
        int i=1;
        while(i<arr.size()){
            while(i<arr.size()&&arr[i]==prev) {
                cnt++;
                i++;
            }
            if(cnt==prev){
             ans=prev;
             break;
            }
             cnt=1;
             prev=arr[i];
             i++;
            
        }
        if(ans==-1&&cnt==prev) ans=prev; // last group handle

        return ans;
    }
};