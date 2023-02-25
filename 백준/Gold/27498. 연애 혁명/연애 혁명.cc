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
    cin >> n >> m;
    vi p(n + 1);
    for(int i{1}; i <= n; ++i){
        p[i] = i;
    }
    struct st{
        int a, b, c, d;
    };
    int sum{0};
    vector<st> vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c >> vec[i].d;
        sum += vec[i].c;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        if(x.d == y.d) return x.c > y.c;
        else return x.d > y.d;
    });
    function<int(int)> find = [&](int a){
        if(p[a] == a) return a;
        return p[a] = find(p[a]);
    };
    function<bool(int,int)> merge = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            p[a] = b;
            return true;
        }
        return false;
    };
    int k{0};
    for(int i{0}; i < m; ++i){
        if(merge(vec[i].a, vec[i].b)) k += vec[i].c;
    }
    cout << sum - k;
}
