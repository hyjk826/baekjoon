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
    int x, y, r;
};

struct E{
    int a, b;
    double w;
};

int p[1002];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a); b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

double dist(int x1, int y1, int x2, int y2){
    int x = x1 - x2;
    int y = y1 - y2;
    return sqrt(1LL * x * x + 1LL * y * y);
}

void solve(){
	int w, n;
    cin >> w >> n;  
    for(int i{0}; i <= n + 1; ++i) p[i] = i;
    vector<st> vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].r;
    }
    vector<E> edge;
    for(int i{1}; i <= n; ++i){
        edge.push_back({0, i, 0.0 + vec[i].x - vec[i].r});
        edge.push_back({i, n + 1, 0.0 + w - (vec[i].x + vec[i].r)});
    }
    for(int i{1}; i <= n; ++i){
        for(int j{i + 1}; j <= n; ++j){
            edge.push_back({i, j, dist(vec[i].x, vec[i].y, vec[j].x, vec[j].y) - vec[i].r - vec[j].r});
        }
    }
    edge.push_back({0, n + 1, 1.0 * w});
    sort(edge.begin(), edge.end(), [&](E& x, E& y){
        return x.w < y.w;
    });
    cout << fixed << setprecision(6);
    for(auto& i : edge){
        merge(i.a, i.b);
        if(find(0) == find(n + 1)){
            if(i.w <= 0.0) cout << 0 << "\n";
            else cout << i.w / 2 << "\n"; 
            return;
        }
    }
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
