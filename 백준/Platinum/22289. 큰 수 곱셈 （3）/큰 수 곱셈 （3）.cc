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
    while(S < v.size() + u.size()) S *= 2;

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
    string s, t;
    cin >> s >> t;
    vi A(1000001), B(1000001);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(int i{0}; i < (int)s.size(); ++i){
        A[i] = s[i] - '0';
    }
    for(int i{0}; i < (int)t.size(); ++i){
        B[i] = t[i] - '0';
    }
    vi r = mul(A, B);
    string ans;
    for(int i{0}; i < (int)r.size(); ++i){
        r[i + 1] += r[i] / 10;
        r[i] %= 10;
        ans += char('0' + r[i]);
    }
    while(ans.size() >= 2 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans;
}

