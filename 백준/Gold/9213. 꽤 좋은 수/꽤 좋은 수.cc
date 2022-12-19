// 2022-12-20
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
	vi sum((int)1e6 + 1, 1);
    for(int i{2}; i <= (int)1e6; ++i){
        for(int j{i * 2}; j <= (int)1e6; j += i){
            sum[j] += i;
        }
    }
    for(int t{1};;++t){
        int l, r, b;
        cin >> l >> r >> b;
        if(l == 0 && r == 0 && b == 0) break;
        cout << "Test " << t << ": ";
        int ans{0};
        for(int i{l}; i <= r; ++i){
            int k = abs(i - sum[i]);
            if(k <= b) ans++;
        }
        cout << ans << "\n";
    }
}
	
