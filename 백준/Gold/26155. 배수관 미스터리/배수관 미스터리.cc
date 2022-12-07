// 2022-12-07
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
    int a, b, p;
};

vi uni((int)1e5 + 1);

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

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vector<st> e(m);
    for(int i{0}; i < m; ++i){
        string str;
        cin >> e[i].a >> e[i].b >> str;
        if(str[0] == '1') e[i].p = 10000;
        else e[i].p = stoi(str.substr(2));
    }
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    int q;
    cin >> q;
    vp A(q);
    for(int i{0}; i < q; ++i){
        string str;
        cin >> str;
        if(str[0] == '1') A[i].first = 10000;
        else A[i].first = stoi(str.substr(2));
        A[i].second = i;
    }
    sort(A.rbegin(), A.rend());
    vi ans(q);
    sort(e.begin(), e.end(), [&](st x, st y){
        return x.p > y.p;
    });
    int idx{0};
    int k{n};
    for(auto& i : A){
        while(idx < m && e[idx].p >= i.first){
            if(Union(e[idx].a, e[idx].b)) k--;
            idx++;
        }
        ans[i.second] = k;
    }
    for(auto& i : ans) cout << i << "\n";
}
	
