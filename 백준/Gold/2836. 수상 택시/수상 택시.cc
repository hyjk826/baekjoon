// 2022-12-24
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
    int n, k;
    cin >> n >> k;
    vp vec;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a <= b) continue;
        vec.push_back({b, a});
    }
    sort(vec.begin(), vec.end());
    vp A;
    A.push_back(vec[0]);
    for(int i{1}; i < (int)vec.size(); ++i){
        if(vec[i].first <= A.back().second) A.back().second = max(A.back().second, vec[i].second);
        else A.push_back(vec[i]);
    }
    ll ans{0};
    for(auto& i : A){
        ans += (i.second - i.first) * 2;
    }
    cout << ans + k;
}
