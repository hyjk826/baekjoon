// 2022-07-28
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

int n, sz;
string str;
int ans{ -MAX };
vi num;
vc op;

int f(int a, int b, char c) {
    if (c == '+') return a + b;
    else if (c == '-') return a - b;
    else if (c == '*') return a * b;
}

void dfs(int k, vi& vec) {
    set<int> s;
    for (int i{ 0 }; i < (int)vec.size(); ++i) {
        s.insert(vec[i] * 2);
    }
    string c = str;
    vi A;
    vc B;
    for (int i{ 0 }; i < n; ++i) {
        if (i % 2 == 0) {
            if (s.count(i)) {
                A.push_back(f(str[i] - '0', str[i + 2] - '0', str[i + 1]));
                i += 2;
            }
            else A.push_back(str[i] - '0');
        }
        else {
            if (!s.count(i - 1)) B.push_back(str[i]);
        }
    }
    int sum = A.front();
    for (int i{ 1 }; i < (int)A.size(); ++i) {
        sum = f(sum, A[i], B[i - 1]);
    }
    ans = max(ans, sum);
    for (int i{ k + 2 }; i + 1 < sz; ++i) {
        vec.push_back(i);
        dfs(i, vec);
        vec.pop_back();
    }
}

int main() {
    fastio;
    cin >> n >> str;
    sz = (n + 1) / 2;
    vi vec;
    for (int i{ 0 }; i < n; ++i) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*') op.push_back(str[i]);
        else num.push_back(str[i] - '0');
    }
    dfs(-2, vec);
    cout << ans;
}

