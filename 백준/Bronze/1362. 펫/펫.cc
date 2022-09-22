// 2022-09-21
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

int main() {
	fastio;
    int o, w;
    int cnt{1};
    while(cin >> o >> w){
        if(o == 0 && w == 0) break;
        bool ok = true;
        while(1){
            char a;
            int b;
            cin >> a >> b;
            if(a == '#') break;
            if(a == 'E') w -= b;
            else w += b;
            if(w <= 0) ok = false;
        }
        cout << cnt << " ";
        if(!ok) cout << "RIP\n";
        else{
            if(o / 2 < w && w < o * 2) cout << ":-)\n";
            else cout << ":-(\n";
        }
        cnt++;
    }
}
	

