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


int ccw(pl a, pl b, pl c){
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pl, pl> x, pair<pl, pl> y){
    pl a = x.first;
    pl b = x.second;
    pl c = y.first;
    pl d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main(){
	fastio;
	int n;
    cin >> n;
    vp A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i].first >> A[i].second;
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i].first >> B[i].second;
    }
    vi vec(n);
    iota(vec.begin(), vec.end(), 0);
    do{
        bool ok = true;
        for(int i{0}; i < n; ++i){
            for(int j{i + 1}; j < n; ++j){
                if(isIntersect({A[i], B[vec[i]]}, {A[j], B[vec[j]]})){
                    ok = false; break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            for(auto& i : vec){
                cout << i + 1 << "\n";
            }
            return 0;
        }
    }while(next_permutation(vec.begin(), vec.end()));
}
