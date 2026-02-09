//lc 496


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int,int>nextg;
    stack<int>st;
    st.push(-1); //-1 for no nge
    int n=nums2.size();
    for(int i=n-1;i>=0;i--){
        int curr=nums2[i];
        while(st.top()!=-1&&st.top()<curr){
            st.pop();
        }
        nextg[curr]=st.top();
        st.push(curr);
    }
    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        int element=nums1[i];
        ans.push_back(nextg[element]);
    }
    return ans;
    }
};

//or

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int,int>nextg;
    stack<int>st;
    int n=nums2.size();
    for(int i=n-1;i>=0;i--){
        int curr=nums2[i];
        while(!st.empty()&&st.top()<curr){
            st.pop();
        }
        nextg[curr]=st.empty()?-1:st.top();
        st.push(curr);
    }
    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        int element=nums1[i];
        ans.push_back(nextg[element]);
    }
    return ans;
    }
};