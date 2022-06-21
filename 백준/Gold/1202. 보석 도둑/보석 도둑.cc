// 2022-06-20
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
	int n, m;
    cin >> n >> m;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    priority_queue<int> pQ;
    vi bag(m);
    for(int i{0}; i < m; ++i){
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end());
    ll ans{0};
    int j{0};
    for(int i{0}; i < m; ++i){
        while(j < n && vec[j].first <= bag[i]){
            pQ.push(vec[j++].second);
        }
        if(!pQ.empty()){
            ans += pQ.top();
            pQ.pop();
        }
    }
    cout << ans;
}