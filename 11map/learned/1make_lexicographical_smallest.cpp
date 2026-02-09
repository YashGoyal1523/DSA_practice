//lc 2948

//https://youtu.be/_rQ4lJlI6nI?si=7rO_lYT9RovGlCjZ

class Solution{
    public:
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (true) {
            int smallValue = nums[i];
            int idx = -1;
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= limit) {
                    if (nums[j] < smallValue) {
                        smallValue = nums[j];
                        idx = j;
                    }
                }
            }
            if (idx != -1) {
                swap(nums[i], nums[idx]);
            } else {
                break;
            }
        }
    }
    return nums;
}
};

// optimal 
// groups banado of elements jo apas m swap ho skte
// origial array m traverse kro and har element ko replace krdo use group ke available smallest se

//note:
// vector : push_back , pop_back -> o(1) .... push_front , pop_front -> o(n)
// in c++ list datastructure is implemented through doubly ll .... push_back  , pop_back  , push_front , pop_front -> o(1)

class Solution{
    public:
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
  int n = nums.size();
vector<int> vec = nums;
//sort the vec
sort(begin(vec), end(vec));
int groupNum = 0;
unordered_map<int, int> numToGroup;
numToGroup[vec[0]] = 0;
unordered_map<int, list<int>> groupToList;
groupToList [groupNum].push_back(vec[0]); //0(1)
for(int i = 1; i < n; i++) {
if(abs(vec[i] -vec[i-1]) > limit) {
groupNum ++;
}
numToGroup[vec[i]] = groupNum;
groupToList[groupNum].push_back(vec[i]);
}
// sab groups bangye and in sorted order

//Build the anwer Merge the groups
vector<int> result(n);
for(int i = 0; i < n; i++){
int num = nums[i];
int group =numToGroup[num];
//smallest available number in this group
result[i] = *groupToList[group].begin(); //use hogaya to delete kardo used element ko
groupToList[group].pop_front();
}
return result;

}
};