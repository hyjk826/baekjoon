// 2022-06-21
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;


double ans{MAX};
vp vec(100000);
vi ch(100000);
int cnt{0};
void dfs(int L, int n, int k){
    if(L == n / 2){
        pair<ll,ll> p = {0, 0};
        for(int i{0}; i < n; ++i){
            if(ch[i]){
                p.first += vec[i].first;
                p.second += vec[i].second;
            }
            else{
                p.first -= vec[i].first;
                p.second -= vec[i].second;
            }
        }
        ans = min(ans, sqrt(p.first * p.first + p.second * p.second));
    }
    else{
        for(int i{k + 1}; i < n; ++i){
            if(ch[i] == 0){
                ch[i] = 1;
                dfs(L + 1, n, i);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    cout << fixed << setprecision(10);
    fastio;
	int t;
    cin >> t;
    while(t--){
        ans = MAX;
        int n;
        cin >> n;
        for(int i{0}; i < n; ++i){
            ch[i] = 0;
            cin >> vec[i].first >> vec[i].second;
        }
        dfs(0, n, -1);
        cout << ans << "\n";
    }
}