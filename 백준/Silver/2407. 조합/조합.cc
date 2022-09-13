// 2022-09-13
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

string f(string a, string b){
    string r;
    int n = (int)a.size();
    int m = (int)b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vi vec(max(n, m));
    for(int i{0}; i < (int)vec.size(); ++i){
        if(i < (int)a.size()) vec[i] += a[i] - '0';
        if(i < (int)b.size()) vec[i] += b[i] - '0';
    }
    for(int i{0}; i < (int)vec.size() - 1; ++i){
        vec[i + 1] += vec[i] / 10;
        vec[i] %= 10;
        r += char('0' + vec[i]);
    }
    r += char('0' + (vec.back() % 10));
    if(vec.back() >= 10){        
        r += '1';
    }
    reverse(r.begin(), r.end());
    return r;
}

string com[101][101]{};

string ff(int n, int m){
    if(com[n][m].size() != 0) return com[n][m];
    if(n == m || m == 0) return com[n][m] = "1";
    return com[n][m] = f(ff(n - 1, m - 1), ff(n - 1, m));
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    cout << ff(n, m);
}
	

