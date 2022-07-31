// 2022-07-31
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
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi dis;
    sort(vec.begin(), vec.end());
    for(int i{0}; i < n - 1; ++i){
        dis.push_back(vec[i + 1] - vec[i]);
    }
    sort(dis.begin(), dis.end());
    int ans{0};
    for(int i{0}; i < n - k; ++i){
        ans += dis[i];
    }
    cout << ans;
}

