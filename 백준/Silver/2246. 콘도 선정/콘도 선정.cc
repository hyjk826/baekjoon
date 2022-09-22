// 2022-09-22
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
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        bool flag = true;
        for(int j{0}; j < n; ++j){
            if(i == j) continue;
            if(vec[j].first < vec[i].first && vec[j].second <= vec[i].second) flag = false;
            if(vec[j].second < vec[i].second && vec[j].first <= vec[i].first) flag = false;
        }
        if(flag) ans++;
    }
    cout << ans;
}
	

