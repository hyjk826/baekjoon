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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    bool ok = true;
    for(int i{2}; i < n; ++i){
        ok &= (vec[i] - vec[i - 1] == vec[1] - vec[0]);
    }
    if(ok){
        cout << "YES\n";
        for(int i{0}; i < n; ++i) cout << 0 << " ";
        cout << "\n";
        for(int i{0}; i < n; ++i) cout << vec[i] << " ";
        cout << "\n";
    }
    else cout << "NO";
}
