// 2022-11-27
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

vi fibo((int)1e6 + 1);

int main() {
	fastio;
    int n, q;
    cin >> n >> q;
    vp query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].first >> query[i].second;
    }
    fibo[0] = fibo[1] = 1;
    for(int i{2}; i <= (int)1e6; ++i){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }
    vi ans(n + 1);
    vi jump(n + 1, 0);
    for(int i{q - 1}; i >= 0; --i){
        int l = query[i].first;
        int r = query[i].second;
        for(int j{l}; j <= r;){
            if(jump[j] == 0){
                ans[j] = fibo[j - l + 1];                
                jump[j] = r - l + 1 - (j - l);
                j++;
            }
            else j += jump[j];
        }
        // for(int j{1}; j <= n; ++j){
        //     cout << ans[j] << " ";
        // }
        // cout << "\n";
    }
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << " ";
    }
}
	
