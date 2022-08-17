// 2022-08-17
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
    ll n, m, k;
    cin >> n >> m >> k;
    if(n - k + 1 < m || (n + k - 1) / k > m) cout << -1;
    else{
        vl A, B;
        for(ll i{1}; i <= n; ++i){
            A.push_back(i);
        }
        for(ll i{n}; i >= 1; --i){
            B.push_back(i);
        }
        vl vec;
        ll a = m;
        ll b = n;
        while(a >= 1){
            if(b - k >= a - 1) vec.push_back(k);
            else{
                vec.push_back(b - (a - 1));
            }
            b -= k;
            a--;
        }
        a = n - 1;
        for(int i{0}; i < (int)vec.size(); ++i){
            reverse(A.begin() + a + 1 - vec[i], A.begin() + a + 1);
            a -= vec[i];
        }
        swap(m, k);
        vec.clear();
        a = m;
        b = n;
        while(a >= 1){
            if(b - k >= a - 1) vec.push_back(k);
            else{
                vec.push_back(b - (a - 1));
            }
            b -= k;
            a--;
        }
        a = n - 1;
        for(int i{0}; i < (int)vec.size(); ++i){
            reverse(B.begin() + a + 1 - vec[i], B.begin() + a + 1);
            a -= vec[i];
        }
        for(auto& i : A) cout << i << " ";
        cout << "\n";
        for(auto& i : B) cout << i << " ";
    }
}

