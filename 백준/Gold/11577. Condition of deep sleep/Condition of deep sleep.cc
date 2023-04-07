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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi pre(n);
    int ans{0};
    for(int i{0}; i <= n - k; ++i){
        if(i) pre[i] += pre[i - 1];
        if(vec[i] == 1 && pre[i] % 2 == 1) continue;
        if(vec[i] == 0 && pre[i] % 2 == 0) continue;
        ans++;
        pre[i]++;
        if(i + k < n) pre[i + k]--;        
    }
    for(int i{n - k + 1}; i < n; ++i){
        pre[i] += pre[i - 1];   
        if(vec[i] == 1 && pre[i] % 2 == 1) continue;
        if(vec[i] == 0 && pre[i] % 2 == 0) continue;        
        cout << "Insomnia"; return 0;
    }
    cout << ans;
}
