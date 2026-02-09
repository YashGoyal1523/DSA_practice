//lc 898

// bruteoforce

// o(n3)

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>s;
        for(int i=0;i<arr.size();i++){
            int val=0;
            for(int j=i;j<arr.size();j++){
                val|=arr[j];
                s.insert(val);
            }
        }
        return s.size();
    }
};

//optimal
// https://youtu.be/Jlj4LUJhQJY?si=IKenL_3bCGg6GwPr
//Approach (using hashset to store previous or values)
//T.C : O(n*32) ~ O(n)
//S.C : O(n*32) ~ O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        for(int i = 0; i < arr.size(); i++) {

            for(const int& x : prev) {
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};

