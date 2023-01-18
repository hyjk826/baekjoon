#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_set>
#include <map>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

int main(){
    fastio;
    string s, t, ans;
    cin >> s >> t;
    for (int i{ 0 }; i < (int)s.size(); ++i) {
        ans += s[i];
        if (ans.back() == t.back()) {
            if (ans.size() >= t.size()) {
                bool flag = true;
                for (int i{ (int)t.size() - 2 }, k{ 1 }; i >= 0; --i, ++k) {
                    if (ans[(int)ans.size() - 1 - k] != t[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int i{ 0 }; i < (int)t.size(); ++i) {
                        ans.pop_back();
                    }
                }
            }
        }
    }
    if (ans.size() == 0) cout << "FRULA";
    else cout << ans;
}