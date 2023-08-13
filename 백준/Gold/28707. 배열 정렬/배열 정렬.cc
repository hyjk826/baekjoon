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
    vi vec;
    int w;
    bool operator< (const st& x) const{
        return w > x.w;
    }
};

struct st2{
    int a, b, c;
};

void solve(){
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int m;
    cin >> m;
    vector<st2> A(m);
    for(auto& i : A) {
        cin >> i.a >> i.b >> i.c;
        i.a--; i.b--;
    }
    vi s = vec;
    sort(s.begin(), s.end());
    map<vi, int> mp;
    priority_queue<st> pQ;
    pQ.push({vec, 0});
    while(!pQ.empty()){
        auto v = pQ.top().vec;
        int w = pQ.top().w;
        pQ.pop();
        if(mp[v] < w) continue;
        for(int i{0}; i < m; ++i){
            swap(v[A[i].a], v[A[i].b]);
            if(!mp.count(v) || mp[v] > w + A[i].c){
                mp[v] = w + A[i].c;
                pQ.push({v, w + A[i].c});
            }
            swap(v[A[i].a], v[A[i].b]);
        }
    }
    if(!mp.count(s)) cout << -1 << "\n";
    else cout << mp[s] << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
