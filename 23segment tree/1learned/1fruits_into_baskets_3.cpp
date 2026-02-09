//lc 3479

// bruteforce 
// n2

// tarika 1..vis array banake
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        unordered_map<int,int>vis;
        for(int i=0;i<n;i++){
            int placed=0;
            for(int j=0;j<n;j++){
                if(vis[j]!=1&&baskets[j]>=fruits[i]){
                    placed=1;
                    vis[j]=1;
                    break;
                }
                
            }
            if(!placed) cnt++;
        }
        return cnt;
    }
};

// tarika 2
//bina vis array

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int placed=0;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i]){
                    placed=1;
                    baskets[j]=-1;
                    break;
                }
                
            }
            if(!placed) cnt++;
        }
        return cnt;
    }
};


//optimal

// https://youtu.be/OC3zzMwCdSk?si=L8AwQj-Uswjneczm

//segment tree



//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets, vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        int m = (l + r) / 2;

        build(2*i + 1, l, m, baskets, segmentTree);
        build(2*i + 2, m + 1, r, baskets, segmentTree);

        segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);
    }

    bool querySegmentTree(int i, int l, int r, vector<int>& segmentTree, int val) {
        if (segmentTree[i] < val)
            return false; // No basket in this segment

        if (l == r) {
            segmentTree[i] = -1; // Mark basket as used
            return true;
        }

        int mid = (l + r) / 2;
        bool placed = false;

        if (segmentTree[2*i + 1] >= val) {
            placed = querySegmentTree(2*i + 1, l, mid, segmentTree, val);
        } else {
            placed = querySegmentTree(2*i + 2, mid + 1, r, segmentTree, val);
        }

        segmentTree[i] = max(segmentTree[2*i + 1], segmentTree[2*i + 2]);

        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> segmentTree(4 * n, -1);

        build(0, 0, n - 1, baskets, segmentTree);

        int unplaced = 0;
        for (int &fruit : fruits) {
            if (!querySegmentTree(0, 0, n - 1, segmentTree, fruit)) {
                unplaced++;
            }
        }

        return unplaced;
    }
};
