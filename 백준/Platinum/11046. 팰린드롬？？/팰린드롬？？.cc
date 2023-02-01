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

vi mnc;

vi manacher(vi& vec){
    vi s;
    for(int i{0}; i < (int)vec.size(); ++i){
        s.push_back(0);
        s.push_back(vec[i]);
    }
    s.push_back(0);
    int n = (int)s.size();
    int r{0}, p{0};
    vi A(n);
    for(int i{0}; i < n; ++i){
        if(i <= r) A[i] = min(r - i, A[2 * p - i]);
        else A[i] = 0;
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && s[i - A[i] - 1] ==s[i + A[i] + 1]) A[i]++;
        if(r < i + A[i]){
            r = i + A[i];
            p = i;
        }
    }
    return A;
}

bool is_palin(int l, int r){
    if(mnc[l + r + 1] >= r - l + 1) return true;
    else return false;
}

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    mnc = manacher(vec);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(is_palin(l, r)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
