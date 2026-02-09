// lc 2914

// sab adjacent pairs m dekh ke count krlo
class Solution {
public:
    int minChanges(string s) {
       int count = 0;
    for (int i = 0; i < s.size() - 1; i += 2) {
        if (s[i] != s[i + 1]) {
            count++;
        }
    }
    return count;
}
};