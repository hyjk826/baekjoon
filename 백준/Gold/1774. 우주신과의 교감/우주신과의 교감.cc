// 2022-07-12
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

int uni[1001];

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


struct edge{
    int x, y;
    double dis;
};

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    vector<edge> v;
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            int a = vec[i].first - vec[j].first;
            int b = vec[i].second - vec[j].second;
            double dis = sqrt(1LL * a * a + 1LL * b * b);
            v.push_back({i + 1, j + 1, dis});
        }
    }
    sort(v.begin(), v.end(), [&](edge a, edge b){
        return a.dis < b.dis;
    });
    double ans{0.0};
    for(int i{0}; i < (int)v.size(); ++i){
        if(Union(v[i].x, v[i].y)) ans += v[i].dis;
    }
    cout << fixed << setprecision(2);
    cout << ans;
}
