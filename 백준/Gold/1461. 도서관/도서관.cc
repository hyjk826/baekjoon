// 2022-08-14
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
    int n, m;
    cin >> n >> m;
    vi A, B;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a > 0) A.push_back(a);
        else B.push_back(-a);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans{0};
    int mx{0};
    for(int i{(int)A.size() - 1}; i >= 0; i -= m){
        ans += 2 * A[i];
        mx = max(mx, A[i]);
    }
    for(int i{(int)B.size() - 1}; i >= 0; i -= m){
        ans += 2 * B[i];
        mx = max(mx, B[i]);
    }
    cout << ans - mx;
}

