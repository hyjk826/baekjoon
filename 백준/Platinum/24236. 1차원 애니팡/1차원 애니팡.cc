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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

ll n, x, y, t;
const int sz = 1e5;
vl vec(sz);
vector<vector<vl> > seg(sz * 4, vector<vl>(3, vl(3, (ll)1e18)));

void init(int node, int l, int r){
    if(l == r) {
        if(vec[l] == 0){
            seg[node][0][0] = seg[node][2][2] = y; seg[node][1][1] = 0;
        }
        else if(vec[l] < 0){
            seg[node][0][0] = 0; seg[node][1][1] = -vec[l] * y;
            seg[node][2][2] = min((ll)x, (-vec[l] + 1) * y);
        }
        else{
            seg[node][0][0] = min((ll)x, (vec[l] + 1) * y);
            seg[node][1][1] = vec[l] * y;
            seg[node][2][2] = 0;
        }
    }
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < 3; ++j){
                seg[node][i][j] = (ll)1e18;
            }
        }      
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < 3; ++j){
                for(int k{0}; k < 3; ++k){
                    ll a = min(seg[node * 2 + 1][(k + 1) % 3][j], seg[node * 2 + 1][(k + 2) % 3][j]);
                    seg[node][i][j] = min(seg[node][i][j], seg[node * 2][i][k] + a);
                }
            }
        }
    }
}

void update(int node, int l, int r, int idx, ll value){
    if(l > idx || r < idx) return;
    if(l == r) {
        vec[l] = value;
        if(vec[l] == 0){
            seg[node][0][0] = seg[node][2][2] = y; seg[node][1][1] = 0;
        }
        else if(vec[l] < 0){
            seg[node][0][0] = 0; seg[node][1][1] = -vec[l] * y;
            seg[node][2][2] = min((ll)x, (-vec[l] + 1) * y);
        }
        else{
            seg[node][0][0] = min((ll)x, (vec[l] + 1) * y);
            seg[node][1][1] = vec[l] * y;
            seg[node][2][2] = 0;
        }
    }
    else{
        int m = (l + r) >> 1;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);      
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < 3; ++j){
                seg[node][i][j] = (ll)1e18;
            }
        }      
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < 3; ++j){
                for(int k{0}; k < 3; ++k){
                    ll a = min(seg[node * 2 + 1][(k + 1) % 3][j], seg[node * 2 + 1][(k + 2) % 3][j]);
                    seg[node][i][j] = min(seg[node][i][j], seg[node * 2][i][k] + a);
                }
            }
        }
    }
}

ll query(){
    ll ret{LLONG_MAX};
    for(int i{0}; i < 3; ++i){
        for(int j{0}; j < 3; ++j){
            ret = min(ret, seg[1][i][j]);
        }
    }
    return ret;
}

int main(){
	fastio;
    cin >> n >> x >> y >> t;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    cout << query() << "\n";
    for(int i{0}; i < t; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        update(1, 0, n - 1, a, b);
        cout << query() << "\n";
    }
}
