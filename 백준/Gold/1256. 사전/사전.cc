// 2023-01-10
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
    vector<vi> com(201, vi(201, -1));
    function<int(int, int)> f = [&](int a, int b){
        if(com[a][b] != -1) return com[a][b];
        if(a == b || b == 0) return com[a][b] = 1;
        return com[a][b] = min((int)1e9 + 10, f(a - 1, b - 1) + f(a - 1, b));
    };
    int n, m, k;
    cin >> n >> m >> k;
    if(f(n + m, m) < k){
        cout << -1;
        return 0;
    }
    string ans;
    int sz = n + m;
    for(int i{0}; i < sz; ++i){
        if(n){
            int a = f(n - 1 + m, m);
            if(k > a){
                ans += 'z';
                k -= a;
                m--;
            }
            else{
                ans += 'a';
                n--;
            }
        }
        else{
            ans += 'z';
            m--;
        }
    }
    cout << ans;
}
