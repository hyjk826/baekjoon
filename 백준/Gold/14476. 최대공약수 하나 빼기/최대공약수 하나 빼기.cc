// 2022-12-18
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(){
	fastio;
	int n;
    cin >> n;
    vi pre(n + 2);
    vi post(n + 2);
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    pre[1] = vec[1];
    for(int i{2}; i <= n; ++i){
        pre[i] = gcd(pre[i - 1], vec[i]);
    }
    post[n] = vec[n];
    for(int i{n - 1}; i >= 1; --i){
        post[i] = gcd(post[i + 1], vec[i]);
    }
    int mx{0}, k{-1};
    for(int i{1}; i <= n; ++i){
        int g = gcd(pre[i - 1], post[i + 1]);
        if(vec[i] % g == 0) continue;
        if(mx < g){
            mx = g;
            k = vec[i];
        }
    }
    if(mx == 0) cout << -1;
    else cout << mx << " " << k;
}
	
