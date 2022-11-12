// 2022-11-13
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

int main() {
	fastio;
    vi prime((int)1e7 + 1);
    prime[1] = 1;
    for(int i{2}; i <= (int)1e7; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= (int)1e7; j += i){
                prime[j] = 1;
            }
        }
    }
    vl A;
    for(int i{1}; i <= (int)1e7; ++i){
        if(prime[i] == 0) A.push_back(i);
    }
    ll a, b;
    cin >> a >> b;
    ll ans{0};
    for(auto& i : A){
        ll k = i * i;
        while(k <= b){
            if(k >= a) {
                ans++;
            }
            if(to_string(k).size() + to_string(i).size() - 1 > to_string(b).size()) break;
            k *= i;
        }
    }
    cout << ans;
}
	

