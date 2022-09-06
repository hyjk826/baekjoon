// 2022-09-06
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
    sort(vec.begin(), vec.end(), [&](pi a, pi b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else return a.second < b.second;
    });
    int r = vec[0].second;
    int cnt{1};
    for(int i{1}; i < n; ++i){
        if(vec[i].first >= r){
            r = vec[i].second;
            cnt++;
        }
    }
    cout << cnt;
}
	

