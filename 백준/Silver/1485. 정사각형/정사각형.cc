// 2022-11-28
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

bool f(pl a, pl b, pl c){
    return (a.first - b.first) * (b.first - c.first) + (a.second - b.second) * (b.second - c.second) == 0;
}

ll dist(pl a, pl b){
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return x * x + y * y;
}


int main() {
	fastio;
	int t;
    cin >> t;
    while(t--){
        vector<pair<ll, ll> > vec(4);
        for(int i{0}; i < 4; ++i){
            cin >> vec[i].first >> vec[i].second;
        }
        sort(vec.begin(), vec.end());
        bool ok = false;
        do{
            bool flag = true;
            ll d = dist(vec[0], vec[1]);
            for(int i{0}; i < 4; ++i){
                flag &= (d == dist(vec[i], vec[(i + 1) % 4]));
                flag &= f(vec[i], vec[(i + 1) % 4], vec[(i + 2) % 4]);
            }
            if(flag){   
                ok = true;
                break;
            }
        }while(next_permutation(vec.begin(), vec.end()));
        if(ok) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
	
