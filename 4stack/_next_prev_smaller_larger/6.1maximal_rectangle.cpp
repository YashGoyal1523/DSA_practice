//lc 85 maximal rectangle
// https://youtu.be/tOylVCugy9k?si=z9aCuV8tcxo40Z8S


// helping ques
//lc 84 Largest rectangle in a histogram

// approach :  ek element ke liye uske height ka max widhth nikalo.... rectangle milgya area nikal lo......har element ke liye area dekho...sabke areas ka max lo


// babbar

// M1 : O(n^2) : tle

// class Solution
// {
// public:

//  int largestRectangleArea(vector<int> &heights)
//     {

//    int area = INT_MIN;

//         for (int i = 0; i < heights.size(); i++)
//         {
//             int j = i-1; // left bars dekhne k liye
//             int k = i+1; // right bars dekhne k liye
//             int a = 1; // total bar // intially 1 rkhdia for current bar

//             // left
//             // Move left while the bar is higher or equal
//             while (j >= 0 && heights[j] >= heights[i])
//             {
//                 a++;
//                 j--;
//             }

//             //right
//             // Move right while the bar is higher or equal
//             while (k < heights.size() && heights[k] >= heights[i])
//             {
//                 a++;
//                 k++;
//             }

//             int multi = heights[i] * a;
//             area = max(area, multi);
//         }

//         return area;
//     }
// };

// M2 : stack : o(n)

// width=nextSmallerIdx-prevSmallerIdx-1

// class Solution
// {
// public:
//     vector<int> nextSmaller(vector<int> &arr, int n)
//     {
//         stack<int> st;
//         vector<int> ans(n);
//         st.push(-1); //-1 for no nse found
//         for (int i = n - 1; i >= 0; i--)
//         {
//             int curr = arr[i];
//             while (st.top() != -1 && arr[st.top()] >= curr)
//             {
//                 st.pop();
//             }
//             if (st.top() == -1)
//                 ans[i] = n;
//             else
//                 ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }

//     vector<int> prevSmaller(vector<int> &arr, int n)
//     {
//         stack<int> st;
//         vector<int> ans(n);
//         st.push(-1); //-1 for no pse found
//         for (int i = 0; i < n; i++)
//         {
//             int curr = arr[i];
//             while (st.top()!= -1 && arr[st.top()] >= curr)
//             {
//                 st.pop();
//             }

//             ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }
//     int largestRectangleArea(vector<int> &heights)
//     {
//         int n=heights.size();
//         if(n==1)return heights[0]; // iss case m toh solve krne ki zrurat noi...vse logic mein handle hojayega par pakad m aagya toh likhlo alag se
//         vector<int> prevIdx=prevSmaller(heights,n);  // agar kisi ka prev smaller not present toh -1 index
//         vector<int> nextIdx=nextSmaller(heights,n);  // agar kisi ka next smaller not present toh n index

//         vector<int>area(n);
//         for(int i=0;i<n;i++){
//             int width=nextIdx[i]-prevIdx[i]-1;
//             int length=heights[i];
//             area[i]=width*length;
//         }
//         int maxi=INT_MIN;
//         for(int i=0;i<area.size();i++){
//             maxi=max(maxi,area[i]);
//         }
//         return maxi;
//     }
// };


// striver

// m3

// https://youtu.be/X0X6G-eWgQ8?si=RPERF4NF0AloNLRl
// https://youtu.be/jC_cWLy7jSI?si=VXcI4Z7rIVjI6KdZ

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};


// now lc 85
// har row ko base banake histogram wala ques krdo
// sabhi row walo ka max lelo


class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }


int maximalRectangle(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
 int maxArea = 0;
vector<int> height(m, 0);
for(int i = 0; i< n; i++) {
for(int j = 0;j<m;j++) {
if(matrix[i][j] == '1') height[j]++;
else height[j] = 0;
}
int area = largestRectangleArea(height); 
maxArea = max(area, maxArea);
}
return maxArea;
    }
};


