// lc 2070
// https://youtu.be/kZGRjC7p3AE?si=TfZucIub9sFsmpqU
class Solution
{
public:
    int customBinarySearch(vector<vector<int>> &items, int queryPrice)
    {
        int l = 0;
        int r = items.size() - 1;

        int maxBeauty = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (items[mid][0] > queryPrice)
            {
                r = mid - 1; // ignore current and right side items. Move to left now.
            }
            else
            {
                maxBeauty =items[mid][1];  // store and check towards right
                l = mid + 1;
            }
        }
        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int n = items.size();
        int m = queries.size();
        vector<int> result(m);
        // step-1: Sort the array based on price in asencding order
        sort(begin(items), end(items)); 
        // step-2 : set maxseen for each price
        int maxBeautySeen = items[0][1];
        for (int i = 1; i < n; i++)
        {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }
        // step 3 : take the maxseen value of largest price which is <= query price
        for (int i = 0; i < m; i++)
        {
            int queryPrice = queries[i];
            result[i] = customBinarySearch(items, queryPrice);
        }
        return result;
    }
};