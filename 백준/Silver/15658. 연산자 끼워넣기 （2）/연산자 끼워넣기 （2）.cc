// 2022-08-31
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
vi vec(12);
vi cnt(4);
int mn{MAX};
int mx{-MAX};

int calc(int a, int k, int b){
    if(k == 0) return a + b;
    if(k == 1) return a - b;
    if(k == 2) return a * b;
    if(k == 3) return a / b;
}

void dfs(int L, int sum){
    if(L == n - 1){
        mn = min(mn, sum);
        mx = max(mx, sum);
    }
    else{
        for(int i{0}; i < 4; ++i){
            if(cnt[i] == 0) continue;
            cnt[i]--;
            dfs(L + 1, calc(sum, i, vec[L + 1]));
            cnt[i]++;
        }
    }
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < 4; ++i){
        cin >> cnt[i];
    }
    dfs(0, vec[0]);
    cout << mx << "\n" << mn;
}

