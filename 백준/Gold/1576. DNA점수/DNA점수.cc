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

void solve(){
    int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi ch(26);
    map<int, int> mp;
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            for(int k{0}; k < (int)vec[i].size(); ++k){
                int a = vec[i][k] - 'A' + 1;
                int b = vec[j][k] - 'A' + 1;
                if(a < b) swap(a, b);
                mp[a * 100 + b]++;
            }
        }
    }
    vc C = {'A', 'T', 'G', 'C'};
    for(int i{0}; i < 4; ++i){
        for(int j{i}; j < 4; ++j){
            int a = C[i] - 'A' + 1;
            int b = C[j] - 'A' + 1;
            if(a < b) swap(a, b);
            if(!mp.count(a * 100 + b)) mp[a * 100 + b] = 0;
        }
    }
    vp A;
    for(auto& i : mp) A.push_back({i.first, i.second});
    sort(A.begin(), A.end(), [&](pi& x, pi& y){
        return x.second < y.second;
    });
    vector<vi> dp((int)A.size(), vi(321, -1));
    function<int(int, int)> f = [&](int a, int b){
        if(b < 0 || b > 320) return -(int)1e9;
        if(a == 0){
            b -= 160;
            if(A[a].first / 100 == A[a].first % 100){
                if(b > 0 && b <= 10) return A[a].second * b;
                else return -(int)1e9;
            }
            else{
                if(b >= -10 && b <= 10) return A[a].second * b;
                else return -(int)1e9;
            }
        }
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        ret = -MAX;
        int ed = -10;
        if(A[a].first / 100 == A[a].first % 100) ed = 1;
        for(int i{10}; i >= ed; --i){
            if(ed == 1) ret = max(ret, A[a].second * i + f(a - 1, b - i));
            else ret = max(ret, A[a].second * i + f(a - 1, b - i * 2));
        }
        return ret;
    };
    cout << fixed << setprecision(20);
    cout << 1.0 * f((int)A.size() - 1, 160) / (n * (n - 1) / 2) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}