// 2022-11-21
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi uni(100001);
vl cnt(100001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

int main() {
	fastio;	
	int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i){
        cin >> cnt[i];
        uni[i] = i;
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a == b){
            cout << cnt[b] << "\n";
            continue;
        }
        uni[a] = b;
        cnt[b] += cnt[a];
        cout << cnt[b] << "\n";
    }
}
	

