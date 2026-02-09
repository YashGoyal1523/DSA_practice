// lc 2064

// minimise the maximum 
// binary search on answer
// possible max no of products to a shop : [1,max of array]
// search space  : [1,max of array]
// minimum valid value nikal lo
// ans always posible as m<=n
// valid fn : for a max no of products value , check if ALL products can be distributed in <=n stores with max product to a store equal to that value, if yes then its valid

class Solution {
public:


    bool valid(int maxi,int n,vector<int> quantities){
        int storesCnt=0;
        int i=0;
        while(i<quantities.size()){
            if(quantities[i]<=maxi){
                quantities[i]=0;
                storesCnt++;
                i++;
            }
            else{
                quantities[i]-=maxi;
                storesCnt++;
            }
        }
        return storesCnt<=n;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,n,quantities)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

// search space : [1,max of array]

class Solution {
public:

    bool valid(int maxi,int n,vector<int> quantities){
        int storesCnt=0;
        for(int i=0;i<quantities.size();i++){
            int store=ceil(quantities[i]/mid);
            storesCnt+=store;
        }
        return storesCnt<=n;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,n,quantities)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//valid function ka alag tarika

class Solution {
public:

    bool valid(int maxi,int n,vector<int> quantities){
        int storesCnt=0;
        for(int i=0;i<quantities.size();i++){
            int stores=ceil((double)quantities[i]/maxi);  // (quantities[i]+maxi-1)/maxi ;
            storesCnt+=stores;
        }
        return storesCnt<=n;
    }


    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,n,quantities)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};