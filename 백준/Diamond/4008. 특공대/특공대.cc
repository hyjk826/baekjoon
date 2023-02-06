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

const int N = 1000000;

struct line{  // y = a*x + b
    long long a,b;
};
 
struct convexhull_trick{
    int s=0,e=0;
    int idx[N + 5];
    line deq[N + 5];
    double cross(int a, int b) {
        return 1.0 * (deq[a].b - deq[b].b) / (deq[b].a - deq[a].a);
    }
    void insert(line v,int line_idx){
        deq[e] = v;
        idx[e] = line_idx;
        while(s+1<e && cross(e - 2, e - 1) > cross(e - 1, e)){
            deq[e-1] = deq[e];
            idx[e-1] = idx[e];
            e--;
        }
        e++;
    }
    pl query(ll x){  // query가 증가수열일 경우
        while(s+1<e && deq[s+1].b - deq[s].b >= x * (deq[s].a - deq[s+1].a))
            s++;
        return {deq[s].a*x+deq[s].b,idx[s]};
    }
    pl query2(ll x){ // 일반 query
        int l = 0, r = e - 1;
        while (l != r) {
            int m = (l + r) / 2;
            if (cross(m, m + 1) <= x) l = m + 1;
            else r = m;
        }
        return {deq[l].a*x+deq[l].b,idx[l]};
    }
    void clear(){s = e = 0;}
};


int main(){
	fastio;
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vl pre = vec;
    for(int i{1}; i <= n; ++i){
        pre[i] += pre[i - 1];
    }
    convexhull_trick cht;
    vl dp(n + 1);
    cht.insert({b, 0},0);
    for(int i=1; i<=n; i++){
        dp[i] = cht.query2(pre[i]).first + a * pre[i] * pre[i] + c;
        cht.insert({-2 * a * pre[i] + b, dp[i] - b * pre[i] + a * pre[i] * pre[i]},i);
    }
    cout << dp[n];
}
