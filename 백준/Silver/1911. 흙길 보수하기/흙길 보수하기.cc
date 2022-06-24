// 2022-06-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, k;
    cin >> n >> k;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    vp v;
    v.push_back(vec[0]);
    for(int i{1}; i < n; ++i){
        if(vec[i].first <= v.back().second){
            v.back().second = max(v.back().second, vec[i].second);
        }
        else v.push_back(vec[i]);
    }
    int ans{0};
    int s{vec[0].first};
    for(int i{0}; i < n; ++i){
        if(s < vec[i].first) s = vec[i].first;
        int a = (vec[i].second - s + k - 1) / k;
        ans += a;
        s += a * k;
    }
    cout << ans;
}
