// 2022-09-24
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

struct st{
    int a, b, c;
};

vi uni(100001);

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
	int T;
	cin >> T;
	for(int t{1}; t <= T; ++t){
		cout << "#" << t << " ";
        int n, m;
        cin >> n >> m;
        vector<st> edge(m);
        for(int i{0}; i < m; ++i){
            cin >> edge[i].a >> edge[i].b >> edge[i].c;
        }
        sort(edge.begin(), edge.end(), [&](st x, st y){
            return x.c < y.c;
        });
        for(int i{1}; i <= n; ++i){
            uni[i] = i;
        }
        ll ans{0};
        for(auto& i : edge){
            if(Union(i.a, i.b)){
                ans += i.c;
            }
        }
        cout << ans << "\n";
	}
}
	