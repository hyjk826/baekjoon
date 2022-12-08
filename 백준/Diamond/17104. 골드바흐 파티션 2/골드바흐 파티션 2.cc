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
	vi prime((int)1e6 + 1);
    prime[1] = 1;
    for(ll i{2}; i <= (int)1e6; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)1e6; j += i){
            prime[j] = 1;
        }
    }
    vi A((int)5e5 + 1);
    for(int i{3}; i <= (int)1e6; ++i){
        if(prime[i]) continue;
        A[(i - 1) / 2] = 1;
    } 
    vi B = A;
    vi r = mul(A, B);
    vi C((int)1e6 + 1);
    for(int i{2}; i <= (int)1e6 / 2; ++i){
        if(prime[i] == 0){
            C[i * 2]++;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n == 4) cout << 1 << "\n";
        else{
            n /= 2;
            cout << (r[n - 1] - C[n * 2]) / 2 + C[n * 2] << "\n";
        }
    }
}
	
