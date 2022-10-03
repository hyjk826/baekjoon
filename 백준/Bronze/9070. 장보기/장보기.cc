// 2022-10-02
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vp vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i].first >> vec[i].second;
        }
        sort(vec.begin(), vec.end(), [&](pi x, pi y){
            if(x.second * y.first == y.second * x.first){
                return x.second < y.second;
            }
            return x.second * y.first < y.second * x.first;
        });
        cout << vec.front().second << "\n";
    }
}
	

