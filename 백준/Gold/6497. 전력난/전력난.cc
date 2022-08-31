// 2022-08-31
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

vi uni(200000);

struct edge{
    int a, b, dis;
};

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
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0) break;
        for(int i{0}; i < n; ++i){
            uni[i] = i;
        }
        vector<edge> vec(m);
        ll sum{0};
        for(int i{0}; i < m; ++i){
            cin >> vec[i].a >> vec[i].b >> vec[i].dis;
            sum += vec[i].dis;
        }
        ll k{0};
        sort(vec.begin(), vec.end(), [&](edge x, edge y){
            return x.dis < y.dis;
        });
        for(int i{0}; i < m; ++i){
            if(Union(vec[i].a, vec[i].b)){
                k += vec[i].dis;
            }
        }
        cout << sum - k << "\n";
    }
}

