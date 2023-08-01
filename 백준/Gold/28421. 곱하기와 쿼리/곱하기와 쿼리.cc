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

void solve(){
	int n, q;
    cin >> n >> q;
    vi vec(n);
    vi ch(10001);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        ch[vec[i]]++;
    }
    while(q--){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            if(n == 1){
                cout << 0 << "\n"; continue;
            }
            if(x == 0){
                if(ch[0]) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
            else{
                bool ok = false;
                for(int i{1}; i * i <= x; ++i){
                    if(x % i) continue;
                    int a = i;
                    int b = x / i;
                    if(a > 10000 || b > 10000) continue;
                    if(a != b && ch[a] > 0 && ch[b] > 0) ok = true;
                    if(a == b && ch[a] >= 2) ok = true;
                }
                if(ok) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
        }
        else{
            x--;
            ch[vec[x]]--;
            if(vec[x]) {
                vec[x] = 0;
                ch[0]++;
            }
        }
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
