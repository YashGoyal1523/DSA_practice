//lc 128

// bruteforce   n^2
// ek ek krke har element ko sequence ka starting element banao ie seq ka sabse chota wla element maanlo and dekho usse baaki array m kitna lamba sequence bana skte ...sabse max lelo

//better   nlogn
//sort krlo elements ko ...fir longest consecutive dekhlo

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0) return 0;
        int ans=1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1){
                cnt++;
            }
            else{
                ans=max(cnt,ans);
                cnt=1;
            }
        }
        ans=max(cnt,ans);
        return ans;
    }
};


//dsu - union by size
// nlogn

class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

  
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(); // n range is [0,10^5]

      //given values range is [-10^9,10^9] toh yeh dsu mein vector ke index mein dikkat krege as index : [0,n-1]
      // So we need to map given values  to values in range [0,n-1]
        unordered_map<int,int>valtoNodeidx;
        int x=0;
        for(int i=0;i<n;i++ ){
            valtoNodeidx[nums[i]]=x;
            x++;
        }


        DisjointSet ds(n);
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]+1]) ds.unionBySize(valtoNodeidx[nums[i]], valtoNodeidx[nums[i]+1]);
            if(mp[nums[i]-1]) ds.unionBySize(valtoNodeidx[nums[i]], valtoNodeidx[nums[i]-1]);
            mp[nums[i]]=true;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(valtoNodeidx[nums[i]])==valtoNodeidx[nums[i]])
            ans=max(ans,ds.size[valtoNodeidx[nums[i]]]);
        }
        return ans;
    }
};


// optimal 
// using unordered set
// o(n)

// set -> find() : o(logn) tc on average
// unordered_Set -> find() : o(1) tc on average

// https://youtu.be/oO5uLE7EUlM?si=ACJcIDY-lZAhC-52

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

int longest = 0;
unordered_set<int> st;
for (int i = 0; i < n; i++) {
    st.insert(nums[i]);
}

for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
        int cnt = 1;
        int x = it;
        while (st.find(x + 1) != st.end()) {
            x = x + 1;
            cnt = cnt + 1;
        }
        longest = max(longest, cnt);
    }
}

return longest;
    }
};