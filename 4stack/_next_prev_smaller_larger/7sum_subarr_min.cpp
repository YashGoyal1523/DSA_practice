//lc 907

//sum of subarray minimums

// https://youtu.be/v0e8p9JCgRc?si=jgzKXYVDc6o32tb3
// https://youtu.be/HRQB7-D2bi0?si=uZDsijUVNJNyQuDj



//bruteforce
//saare subarray nikalke dekhlo and krlo

//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int M = 1e9 + 7;
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        long result = 0;

        for (int i = 0; i < n; i++) {
            int minVal = arr[i];

            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                result = (result + minVal) % M;
            }
        }

        return result;
    }
};

//better
// https://youtu.be/HRQB7-D2bi0?si=clxjN2M09iqsZqeL
// https://youtu.be/v0e8p9JCgRc?si=y7ROgQZQav_SKxDE

// har element ka contribution nikal lo jo voh final ans m dera h and sabka add krlo
//->har element ke liye dekhlo ki voh kitne subbarray mein min h and utni baar voh ans m jod lo

//contribution of an element
// no of subarrays jisme target element min h =  ( (no of elements which are target element ke left adjacent and are greater ya equal to target) + 1) * ( (no of elements which are target element ke right adjacent and are greater ya equal to target) + 1)  or we can say (target element se start hoke no of left adjacent elements which are greater or equal to target ) * (target element se start hoke  no of right adjacent elements which are greater or equal to target)
// no of left adjacent elements which are greater ya equal = target element idx - prev smaller element idx -1    or we can say   target se shuru hoke no of left adj elements which is greater or equal = target idx- prev smaller idx
// no of right adjacent elements which are greater ya equal = next smaller element idx - target idx -1   or we can say   target se shuru hoke no of right adj elements which is greater or equal = next smaller idx - target idx

//note: if no prev smaller -> take -1 index, if no next smaller -> take n index

//IMP NOTE: agar array mein duplicate elements present hai toh final answer mein duplicate addition ho skti h 
// eg : 2,6,2,4,5 
// for 0th index 2 -> subarray counted : 2,6,2,4,5
// for 2nd index 2 -> subarray counted : 2,6,2,4,5
// ->duplicate addition hojayegi
// ->to handle this.... take left adjacent elements which are strictly greater

class Solution {
public:

int mod=1e9+7;

 vector<int> prevSmaller(vector<int>arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (!st.empty()&&arr[st.top()] > curr) //strictly greater to avoid duplicate addition
            {
                st.pop();
            }

            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int>arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (!st.empty()&&arr[st.top()] >= curr) //greater or equal
        {
            st.pop();
        }
        ans[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
} 
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prevsmall=prevSmaller(arr,n);
        vector<int>nextsmall=nextSmaller(arr,n);

        long long ans=0;

        for(int i=0;i<arr.size();i++){
            int prev=prevsmall[i];
            int next=nextsmall[i];
            long long left=i-prev;
            long long right=next-i;
            long long contri=(left*right)*arr[i];
            ans=(ans+contri)%mod;
        }

        return (int)ans;
    }
};