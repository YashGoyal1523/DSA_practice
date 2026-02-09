// codechef contest ques

// https://www.codechef.com/problems/GRIDPATHEZ?tab=statement

// https://youtu.be/PtMqwrEWVzI?si=2yJybW4HRghcHs_i

//approach - saare possible paths m se min wala uthalege
//method ->
//1st row wale saare 1 left end se lagado , 2nd row wale saare 1 right end se lagado
//isse saare possible paths set hojayege 
//saare paths mein se min uthalo


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<vector<char>> v(2, vector<char>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        vector<int> pos1_1; //positions of 1 in 1 row
        for (int i = 0; i < n; i++) {
            if (v[0][i] == '1') pos1_1.push_back(i);
        }

        vector<int> pos1_2; // positions of 1 in 2 row
        for (int i = n - 1; i >= 0; i--) {
            if (v[1][i] == '1') pos1_2.push_back(i);
        }

        if (pos1_1.empty() || pos1_2.empty()) {
            cout << -1 << endl;
            continue;
        }

        //1 row mein saare 1 ko left end se lagana hoga
        //2 row mein saare 1 ko right end se lagana hoga

        vector<ll> pre(n, -1); // in 1 row  ,for a valid index (ispe 1 hai after rearranging) ,  store cost to reach that index from left end ... (-1 value for invalid indexes (ispe 1 nhi h after rearranging))
        pre[0] = pos1_1[0];
        for (int i = 1; i < pos1_1.size(); i++) {
            pre[i] = pre[i - 1] + (pos1_1[i] - i);
        }

        vector<ll> post(n, -1); // in 2 row , for a valid index (ispe 1 hai after rearranging) , store cost to reach right end from that index .....(-1 value for invalid indexes (ispe 1 nhi h after rearranging))
        post[n - 1] = (n - 1) - pos1_2[0];
        int idx = n - 2;
        for (int i = 1; i < pos1_2.size() ; i++) {
            post[idx] = post[idx + 1] + (idx - pos1_2[i]);
            idx--;
        }

        //finding min path
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (pre[i] !=-1 && post[i] != -1)
                ans = min(ans, pre[i] + post[i]);
        }

        if (ans == LLONG_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
