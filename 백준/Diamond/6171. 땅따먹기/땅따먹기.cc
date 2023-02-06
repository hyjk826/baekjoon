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

struct line{  // y = a*x + b
    ll a,b;
};
 
const int N = (int)5e4;

struct convexhull_trick{
    int s=0,e=0;
    int idx[N+5];
    line deq[N+5];
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
        while(s+1<e && deq[s+1].b - deq[s].b <= x * (deq[s].a - deq[s+1].a))
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
    int n;
    cin >> n;
    vpl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    vpl A;
    for(int i{0}; i < n; ++i){
        while(!A.empty() && A.back().second <= vec[i].second) A.pop_back();
        A.push_back(vec[i]);
    }
    convexhull_trick cht;
    cht.insert({A[0].second, 0}, 0);
    vl dp((int)A.size());
    for(int i{0}; i < (int)A.size(); ++i){
        dp[i] = cht.query2(A[i].first).first;
        if(i < (int)A.size() - 1){
            cht.insert({A[i + 1].second, dp[i]}, i + 1);
        }
    }
    cout << dp.back();
}
