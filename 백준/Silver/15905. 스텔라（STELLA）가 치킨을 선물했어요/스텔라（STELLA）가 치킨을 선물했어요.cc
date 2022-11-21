// 2022-11-20
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

int main() {
	fastio;	
	int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end(), [&](pi a, pi b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        else return a.first > b.first;
    });
    int ans{0};
    for(int i{5}; i < n; ++i){
        if(vec[i].first == vec[4].first){
            ans++;
        }
        else break;
    }
    cout << ans;
}
	

