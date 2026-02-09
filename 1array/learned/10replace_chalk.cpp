// lc 1894

// m1
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
        int n=chalk.size();
        while(chalk[i%n]<=k){
        k-=chalk[i%n];
        i++;
    }
    return i%n;
    }
};
// tle dedega

//m2

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total=accumulate(chalk.begin(),chalk.end(),0ll); // total chalks ek round mein lagege jo // long long lena pada as out of bound jaara tha
        k=k%total;
        int n=chalk.size();
        int ans=-1;
       for(int i=0;i<chalk.size();i++){
        if(chalk[i]>k){
            ans=i;
            break;
        }
        k-=chalk[i];
       }
    return ans;
    }
};