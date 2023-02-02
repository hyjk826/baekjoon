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
    vp vec(11);
    for(int i{0}; i < 11; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int ans{0};
    int cnt{0};
    sort(vec.begin(), vec.end());
    for(int i{0}; i < 11; ++i){
        cnt += vec[i].first;
        ans += cnt + 20 * vec[i].second;
    }
    cout << ans;
}
