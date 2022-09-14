// 2022-09-14
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
    int n, m, k;
    cin >> n >> m >> k;
    vi vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vi ch(n + 1);
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        int idx = upper_bound(vec.begin(), vec.end(), a) - vec.begin();
        while(idx <= m && ch[idx]) idx++;
        cout << vec[idx] << "\n";
        ch[idx] = 1;
    }
}
	

