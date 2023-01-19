// 2023-01-18
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

int main(){
	fastio;
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vi uni(n + 1), dist(n + 1);
        for(int i{1}; i <= n; ++i){
            uni[i] = i;
        }
        function<int(int)> find = [&](int a){
            if(a == uni[a]) return a;
            int root = find(uni[a]);
            dist[a] += dist[uni[a]];
            return uni[a] = root;
        };
        function<bool(int,int,int)> Union = [&](int a, int b, int w){
            int roota = find(a);
            int rootb = find(b);
            if(a != b){
                dist[roota] = -dist[a] + dist[b] + w;
                uni[roota] = rootb;
                return true;
            }
            return false;
        };
        for(int i{0}; i < m; ++i){
            char op; int a, b, w;
            cin >> op;
            if(op == '!'){
                cin >> a >> b >> w;
                Union(a, b, w);
            }
            else{
                cin >> a >> b;
                if(find(a) != find(b)) cout << "UNKNOWN\n";
                else cout << dist[a] - dist[b] << "\n";
            }
        }
    }
}
