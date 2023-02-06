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
    int a = v.size();
    int b = u.size();
    vector<cpx> A(v.begin(), v.end());
    vector<cpx> B(u.begin(), u.end());
    int S = 2;
    while(S < a + b) S *= 2;
    A.resize(S); FFT(A, false);
    B.resize(S); FFT(B, false);
    for(int i=0; i<S; i++) A[i] *= B[i];
    FFT(A, true);
    vector<int> w(S);
    for(int i=0; i<S; i++){
        w[i] = round(A[i].real());
        if(w[i]) w[i] = 1;
    }
    return vector<int>(w.begin(), w.begin() + a + b - 1);
}

vector<int> f(vector<int> vec, int k){
    vi ret = vec;
    k--;
    while(k){
        if(k & 1){
            ret = mul(ret, vec);
        }
        k >>= 1;
        vec = mul(vec, vec);
    }
    return ret;
}

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vi vec(1001);
    for(int i{0}; i < n; ++i) {
        int a;
        cin >> a;
        vec[a] = 1;
    }
    vi r = f(vec, k);
    for(int i{0}; i < (int)r.size(); ++i){
        if(r[i]) cout << i << " ";
    }
}
