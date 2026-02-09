// lc 1769


// if you want to move a ball from box j to box i, you'll need abs(i-j) moves.
// To move all balls to some box, you can move them one by one.



// m1 bruteforce
// For each box i, iterate on each ball in a box j, and add abs(i-j) to answers[i].


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
       vector<int>ans(n);
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(boxes[j]=='1') sum+=abs(j-i);
        }
        ans[i]=sum;
       } 
return ans;
    }
};

// m2- prefix suffix sum
// observe that a ball can move in only one direction: either left or right. If the target box is to the left of the ball, it will move left. If the target box is to the right of the ball, it will move right. So, for each box, some balls will come from the left side, and others will come from the right side.
// To calculate the distances for all the balls coming from the left in just one pass, we use a combined approach within a single loop. As we iterate through the boxes from left to right, we keep track of how many balls we’ve encountered so far using the variable ballsToLeft. Each time we move to the next box, the distance for all the balls we’ve passed increases by one. So, the total number of operations for those balls increases by the number of balls we've encountered up to that point. We also keep track of the cumulative number of moves using the variable movesToLeft.
// Similarly, we calculate the distances for the balls coming from the right by iterating through the boxes from right to left. This is achieved using the variable ballsToRight to track how many balls we’ve encountered, and movesToRight to track the cumulative moves. During this reverse pass, we simultaneously calculate and accumulate the number of moves required for balls coming from the right.
// In each iteration, we update the answer array by adding the moves calculated from both the left and right sides. The value for each box in answer[i] (for the left pass) and answer[j] (for the right pass) represents the total moves required for balls to reach that box.

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // calculate moves from left and right
        //left
        for (int i = 0; i < n; i++) {
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] == '0'?0:1;
            movesToLeft += ballsToLeft;
        }
        //right
        for(int i=n-1;i>=0;i--){
            answer[i]+=movesToRight;
            ballsToRight+=boxes[i]=='0'?0:1;
            movesToRight += ballsToRight;

        }

        return answer;
    }
};