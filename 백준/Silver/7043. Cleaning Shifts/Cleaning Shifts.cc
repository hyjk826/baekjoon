// 2022-11-21
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
	int n, m;
    cin >> n >> m;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end(), [&](pi x, pi y){
        if(x.first == y.first){
            return x.second > y.second;
        }
        else return x.first < y.first;
    });
    int ans{1};
    int r{vec[0].second};
    bool flag = true;
    if(vec[0].first != 1){
        flag = false;
    }
    if(r >= m){
        cout << 1;
        return 0;
    }
    int idx{1};
    priority_queue<int> pQ;
    while(idx < n){
        while(idx < n  && vec[idx].first <= r + 1){
            pQ.push(vec[idx].second);
            idx++;
        }   
        if(pQ.empty()){
            cout << -1;
            return 0;
        }
        ans++;
        r = pQ.top();
        pQ.pop();
        if(r >= m) break;
    }
    if(r < m) flag = false;
    if(!flag) cout << -1;
    else cout << ans;

}
	

