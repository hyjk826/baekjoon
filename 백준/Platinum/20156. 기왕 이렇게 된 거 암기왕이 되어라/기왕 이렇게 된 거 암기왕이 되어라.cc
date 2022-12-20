// 2022-12-20
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
    int a, b, c, idx;
};

vi uni(100001);
vi p(100001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}



int main(){
	fastio;
	int n, m, k;
    cin >> n >> m >> k;
    set<pi> s;
    for(int i{1}; i <= n; ++i){
        cin >> p[i];
        uni[i] = i;
    }
    vi A(m);
    map<pi, int> mp;
    for(int i{0}; i < m; ++i){
        cin >> A[i];
        s.insert({min(A[i], p[A[i]]), max(A[i], p[A[i]])});
        mp[{min(A[i], p[A[i]]), max(A[i], p[A[i]])}]++;
    }
    for(int i{1}; i <= n; ++i){
        if(s.count({min(i, p[i]), max(i, p[i])})) continue;
        if(p[i] == -1) continue;
        Union(i, p[i]);
    }
    vector<st> query;
    for(int i{0}; i < k; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        query.push_back({a, b, c, i});
    }
    sort(query.begin(), query.end(), [&](st x, st y){
        return x.a < y.a;
    });
    int idx{k - 1};
    vi ans(k);
    for(int i{m}; i >= 0; --i){
        while(idx >= 0 && query[idx].a >= i){
            int a = find(query[idx].b);
            int b = find(query[idx].c);
            if(a == b) ans[query[idx].idx] = 1;
            idx--;
        }
        if(i){
            if(p[A[i - 1]] == -1) continue;
            int a = min(A[i - 1], p[A[i - 1]]);
            int b = max(A[i - 1], p[A[i - 1]]);
            mp[{a, b}]--;
            if(mp[{a, b}] == 0){
                Union(A[i - 1], p[A[i - 1]]);
            }
        }
    }
    for(auto& i : ans){
        if(i == 0) cout << "No;";
        else cout << "Same Same;";
        cout << "\n";
    }
}
	
