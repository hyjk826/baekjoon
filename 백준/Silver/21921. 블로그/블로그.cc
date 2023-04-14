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

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    ll mx{0};
    int cnt{0};
    for(int i{0}; i + k <= n; ++i){
        if(mx < vec[i + k] - vec[i]){
            mx = vec[i + k] - vec[i];
            cnt = 1;
        }
        else if(mx == vec[i + k] - vec[i]){
            cnt++;
        }
    }
    if(mx == 0){
        cout << "SAD"; return 0;
    }
    cout << mx << "\n" << cnt;
    
}
