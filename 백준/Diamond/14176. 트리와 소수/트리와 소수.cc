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

int n;
const int sz = (int)1e5 + 10;
vector<vi> g(sz);
vi sub(sz);
vi ch(sz);

int getSub(int cur, int pre = -1){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        getSub(i, cur);
        sub[cur] += sub[i];
    }
    return sub[cur];
}

int getCent(int cur, int pre, int s){
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        if(sub[i] * 2 > s){
            return getCent(i, cur, s);
        }
    }
    return cur;
}

ll cnt{0};

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();
    for(int i=1, j=0; i<S; i++) {
        int bit = S/2;
        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;
        if(i < j) swap(v[i], v[j]);
    }
    for(int k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));
        for(int i=0; i<S; i+=k*2) {
            cpx z(1, 0);
            for(int j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];
                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;
                z *= w;
            }
        }
    }
    if(inv) for(int i=0; i<S; i++) v[i] /= S;
}

vector<int> mul(vector<int> &v, vector<int> &u) {
    int a = (int)v.size();
    int b = (int)u.size();
    vector<cpx> A(v.begin(), v.end());
    vector<cpx> B(u.begin(), u.end());
    int S = 2;
    while(S < a + b) S *= 2;
    A.resize(S); FFT(A, false);
    B.resize(S); FFT(B, false);
    for(int i=0; i<S; i++) A[i] *= B[i];
    FFT(A, true);
    vector<int> w(S);
    for(int i=0; i<S; i++) w[i] = round(A[i].real());
    return vector<int>(w.begin(), w.begin() + a + b - 1);
}

vi A(sz);
vi prime(sz);
int mx{0};

void dfs(vi& B, int L, int cur, int pre){
    mx = max(mx, L);
    B[L]++;
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        dfs(B, L + 1, i, cur);
    }
}

void update(vi& B){
    vi R = mul(A, B);
    for(int i{1}; i < (int)R.size(); ++i){
        if(prime[i] == 0) cnt += R[i];
        if(i < (int)A.size() && i < (int)B.size()) A[i] += B[i];
    }
}

void buildCentroidTree(int cur, int pre = -1){
    int cent = getCent(cur, -1, getSub(cur, -1));
    getSub(cent, -1);
    sort(g[cent].begin(), g[cent].end(), [&](int a, int b){
        return sub[a] < sub[b];
    });
    ch[cent] = 1;
    A.resize(1);
    A[0] = 1;
    A.reserve(sub[cent] + 1);
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        mx = 0;
        vi B(sub[i] + 1);
        dfs(B, 1, i, cent);
        if(A.size() <= mx) A.resize(mx + 1);
        update(B);
    }    
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        buildCentroidTree(i, cent);
    }
}

int main(){
	fastio;
    prime[1] = 1;
    for(ll i{2}; i <= 1e5; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= 1e5; j += i) prime[j] = 1;
    }
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    buildCentroidTree(1);
    ll all = 1LL * n * (n - 1) / 2;
    cout << fixed << setprecision(20);
    cout << 1.0 * cnt / all;
}
