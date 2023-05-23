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
    vp A, B;
    vi C;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a <= b) A.push_back({a, b});
        else B.push_back({a, b});
    }
    sort(A.begin(), A.end());
    ll cur{0};
    for(auto& i : A){
        if(cur < i.first){
            cout << 0; return 0;
        }
        cur -= i.first;
        cur += i.second;
    }
    sort(B.begin(), B.end(), [&](pi& x, pi& y){
        if(x.second == y.second) return x.first > y.first;
        else return x.second > y.second;
    });
    for(auto& i : B){
        if(cur < i.first){
            cout << 0; return 0;
        }
        cur -= i.first;
        cur += i.second;
    }
    cout << 1;
}
