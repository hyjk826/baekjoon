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

int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve(){
    vi ch(10);
    for(int i{0}; i <= 9; ++i){
        cin >> ch[i];
    }
    int ans{0};
    for(int i{1}; i <= 12; ++i){
        for(int j{1}; j <= month[i]; ++j){
            vi A;
            int a = i;
            int b = j;
            while(a){
                A.push_back(a % 10); a /= 10;;
            }
            while(b){
                A.push_back(b % 10); b /= 10;
            }
            bool ok = true;
            for(auto& k : A){
                ok &= (ch[k] == 0);
            }
            if(ok) ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
