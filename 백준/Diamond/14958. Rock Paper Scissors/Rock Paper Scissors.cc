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
    int a = v.size();
    int b = u.size();
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
    return vector<int>(w.begin(), w.begin() + a + b - 1);
}

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vi A(n), B(n), C(n);
    vi A2(m), B2(m), C2(m);
    for(int i{0}; i < n; ++i){
        if(s[i] == 'R') A[i] = 1;
        else if(s[i] == 'S') B[i] = 1;
        else if(s[i] == 'P') C[i] = 1;
    }
    reverse(t.begin(), t.end());
    for(int i{0}; i < m; ++i){
        if(t[i] == 'P') A2[i] = 1;
        else if(t[i] == 'R') B2[i] = 1;
        else if(t[i] == 'S') C2[i] = 1;
    }
    vi R1 = mul(A, A2);
    vi R2 = mul(B, B2);
    vi R3 = mul(C, C2);
    int ans{0};
    for(int i{m - 1}; i < (int)R1.size(); ++i){
        ans = max(ans, R1[i] + R2[i] + R3[i]);
    }
    cout << ans;
}
	
