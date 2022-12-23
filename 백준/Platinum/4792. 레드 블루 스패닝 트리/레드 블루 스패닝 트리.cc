// 2022-12-23
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
    int a, b, c;
};

int main(){
	fastio;
    while(1){
        int n, m, k;
        cin >> n >> m >> k;
        if(n == 0) break;
        vi uni(n + 1);
        for(int i{1}; i <= n; ++i){
            uni[i] = i;
        }
        vector<st> edge(m);
        for(int i{0}; i < m; ++i){
            char c;
            cin >> c >> edge[i].b >> edge[i].c;
            if(c == 'R') edge[i].a = 0;
            else edge[i].a = 1;
        }
        sort(edge.begin(), edge.end(), [&](st& x, st& y){
            return x.a < y.a;
        });
        function<int(int)> find = [&](int a){
            if(a == uni[a]) return a;
            return uni[a] = find(uni[a]);
        };

        function<bool(int,int)> Union = [&](int a, int b){
            a = find(a);
            b = find(b);
            if(a != b){
                uni[a] = b;
                return true;
            }
            return false;
        };
        int mn{0}, mx{0};
        for(int i{0}; i < m; ++i){
            if(Union(edge[i].b, edge[i].c)){
                if(edge[i].a == 1) mn++;
            }
        }
        for(int i{1}; i <= n; ++i){
            uni[i] = i;
        }
        for(int i{m - 1}; i >= 0; --i){
            if(Union(edge[i].b, edge[i].c)){
                if(edge[i].a == 1) mx++;
            }
        }
        if(mn <= k && k <= mx) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
