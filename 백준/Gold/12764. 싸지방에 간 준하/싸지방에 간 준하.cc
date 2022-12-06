// 2022-12-04
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

struct st{
    int end, idx;
    bool operator< (const st a) const{
        return end > a.end;
    }
};


int main() {
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    priority_queue<st> pQ;
    priority_queue<int, vi, greater<int> > pQ2;
    vi ans;
    sort(vec.begin(), vec.end());
    for(int i{0}; i < n; ++i){
        while(!pQ.empty() && pQ.top().end < vec[i].first){
            int e = pQ.top().end;
            int idx = pQ.top().idx;
            pQ.pop();
            pQ2.push(idx);
        }
        if(pQ2.empty()) {
            ans.push_back(1);
            pQ.push({vec[i].second, (int)ans.size() - 1});
        }
        else{
            int idx = pQ2.top();
            pQ2.pop();
            ans[idx]++;
            pQ.push({vec[i].second, idx});
        }
    }
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << " ";
}
	
