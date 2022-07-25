// 2022-07-25
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

int n;
vi pre, post;
vi in;

void f(int s, int e, int ss, int ee) {
    if (s > e) return;
    int k = in[post[ee]];
    cout << pre[k] << " ";
    f(s, k - 1, ss, ss + k - s - 1);
    f(k + 1, e, ss + k - s, ee - 1);
}

int main() {
    fastio;
    cin >> n;
    pre.resize(n + 1);
    post.resize(n + 1);
    in.resize(n + 1);
    for (int i{ 1 }; i <= n; ++i) {
        cin >> pre[i];
        in[pre[i]] = i;
    }
    for (int i{ 1 }; i <= n; ++i) {
        cin >> post[i];
    }
    f(1, n, 1, n);
}

