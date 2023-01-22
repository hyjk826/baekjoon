// 2023-01-23
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
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, MAX){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] = min(BIT[i], x);
      i += i & -i;
    }
  }
  T query(int i){
    T ans = MAX;
    while (i > 0){
      ans = min(ans, BIT[i]);
      i -= i & -i;
    }
    return ans;
  }
};

int main(){
	fastio;
    int n;
    cin >> n;
    vi A(3);
    for(int i{0}; i < 3; ++i){
        cin >> A[i];
        A[i]--;
    }
    int m;
    cin >> m;
    vector<vp> g(n);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    function<vi(int)> f = [&](int s){
        vi dijk(n, MAX);
        dijk[s] = 0;
        priority_queue<st> pQ;
        pQ.push({s, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(dijk[v] < w) continue;
            for(auto& i : g[v]){
                int nv{i.first};
                int nw{w + i.second};
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk;
    };
    vector<vi> B(3);
    for(int i{0}; i < 3; ++i){
        B[i] = f(A[i]);
    }
    struct st2{
        int a, b, c, idx;
    };
    vector<st2> vec;
    vi dist;
    for(int j{0}; j < n; ++j){
        vec.push_back({B[0][j], B[1][j], B[2][j], j});
        for(int i{0}; i < 3; ++i){
            dist.push_back(B[i][j]);
        }
    }
    sort(dist.begin(), dist.end());
    dist.erase(unique(dist.begin(), dist.end()));
    for(int i{0}; i < n; ++i){
        vec[i].a = lower_bound(dist.begin(), dist.end(), vec[i].a) - dist.begin();
        vec[i].b = lower_bound(dist.begin(), dist.end(), vec[i].b) - dist.begin();
        vec[i].c = lower_bound(dist.begin(), dist.end(), vec[i].c) - dist.begin();
    }
    sort(vec.begin(), vec.end(), [&](st2& x, st2& y){
        return x.a < y.a;
    });
    vi ch(n);
    vp temp;
    binary_indexed_tree<ll> BIT((int)dist.size() + 100);
    for(int i{0}; i < n; ++i){
        if(BIT.query(vec[i].b) >= vec[i].c) {
            ch[vec[i].idx] = 1;
        }
        temp.push_back({vec[i].b, vec[i].c});
        if(i < n - 1 && vec[i].a != vec[i + 1].a){
            for(auto& j : temp){
                BIT.add(j.first, j.second);
            }
            temp.clear();
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        a--;
        if(ch[a]) cout << "YES\n";
        else cout << "NO\n";
    }
}
