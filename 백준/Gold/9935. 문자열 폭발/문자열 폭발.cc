// 2022-09-13
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
    fastio;
    string s, t;
    cin >> s >> t;
    string str;
    for (int i{ 0 }; i < (int)s.size(); ++i) {
        str += s[i];
        bool flag = false;;
        if (str.size() >= t.size() && str.back() == t.back()) {
            flag = true;
            for (int j{ 0 }; j < (int)t.size(); ++j) {
                if (t[j] != str[(int)str.size() - (int)t.size() + j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            for (int j{ 0 }; j < (int)t.size(); ++j) str.pop_back();
        }
    }
    if (str.size() == 0) cout << "FRULA";
    else cout << str;
}


