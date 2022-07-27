// 2022-07-27
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
    int n, h;
    cin >> n >> h;
    vi A, B;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(i & 1) B.push_back(a);
        else A.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vi cnt(n + 1);
    int mn{MAX};
    for(int i{1}; i <= h; ++i){
        int sum{0};
        int a = A.end() - lower_bound(A.begin(), A.end(), i);
        int b = B.end() - lower_bound(B.begin(), B.end(), h - i + 1); 
        sum += a + b;
        mn = min(mn, sum);
        cnt[sum]++;
    }
    cout << mn << " " << cnt[mn];
}

