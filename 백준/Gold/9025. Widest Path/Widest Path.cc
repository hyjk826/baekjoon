// 2022-10-01
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

vi uni(1001);

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
    int a, b, c;
};

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        for(int i{1}; i <= n; ++i){
            uni[i] = i;
        }
        vector<st> edge(m);
        for(int i{0}; i < m; ++i){
            cin >> edge[i].a >> edge[i].b >> edge[i].c;
        }
        sort(edge.begin(), edge.end(), [&](st x, st y){
            return x.c > y.c;
        });
        for(int i{0}; i < m; ++i){
            Union(edge[i].a, edge[i].b);
            int a = find(s);
            int b = find(t);
            if(a == b){
                cout << edge[i].c << "\n";
                break;
            }
        }
    }
}
	

