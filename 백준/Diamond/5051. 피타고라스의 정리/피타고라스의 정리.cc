// 2022-12-08
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

    if(inv)
        for(int i=0; i<S; i++) v[i] /= S;
}

vector<int> mul(vector<int> &v, vector<int> &u) {
    vector<cpx> A(v.begin(), v.end());
    vector<cpx> B(u.begin(), u.end());

    int S = 2;
    while(S < (int)v.size() + (int)u.size()) S *= 2;

    A.resize(S); FFT(A, false);
    B.resize(S); FFT(B, false);

    for(int i=0; i<S; i++) A[i] *= B[i];
    FFT(A, true);

    vector<int> w(S);
    for(int i=0; i<S; i++) w[i] = round(A[i].real());

    return w;
}

int main() {
	fastio;
	ll n;
    cin >> n;
    vi cnt(n);
    vi A, B;
    for(ll i{1}; i < n; ++i){
        cnt[(i * i) % n]++;
    }
    A = B = cnt;
    ll b{0};
    for(ll i{1}; i < n; ++i){
        ll k = i *i * 2 % n;
        b += cnt[k];
    }
    vi r = mul(A, B);
    ll a{0};
    for(int i{0}; i < (int)A.size() + (int)B.size() - 1; ++i){
        a += 1LL * r[i] * cnt[i % n];
    }
    cout << (a - b) / 2 + b;
}
	
