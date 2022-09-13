// 2022-09-14
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

double dis(pair<double, double> x, pair<double, double> y){
    double a = x.first -  y.first;
    double b = x.second - y.second;
    return sqrt(a * a + b * b);
}

vi uni(100);

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

struct st{
    int a, b;
    double dis;
};


int main() {
	fastio;
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i) uni[i] = i;
    vector<st> edge;
    vector<pair<double, double> > vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            double d = dis(vec[i], vec[j]);
            edge.push_back({i, j, d});
        }
    }
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.dis < y.dis;
    });
    double ans{0};
    for(int i{0}; i < (int)edge.size(); ++i){
        if(Union(edge[i].a, edge[i].b)){
            ans += edge[i].dis;
        }
    }
    cout << ans;
}
	

