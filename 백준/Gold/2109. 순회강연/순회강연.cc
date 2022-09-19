// 2022-09-19
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
        cin >> vec[i].second >> vec[i].first;
    }
    sort(vec.begin(), vec.end());
    int idx{n - 1};
    priority_queue<int> pQ;
    int ans{0};
    for(int i{10000}; i >= 1; --i){
        while(idx >= 0 && vec[idx].first >= i){
            pQ.push(vec[idx].second);
            idx--;
        }
        if(!pQ.empty()){
            ans += pQ.top();
            pQ.pop();
        }
    }
    cout << ans;
}
	

