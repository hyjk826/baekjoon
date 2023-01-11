// 2023-01-10
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

int main(){
	fastio;
    int n;
    cin >> n;
    vl fact(21);
    fact[1] = 1;
    for(int i{2}; i <= 20; ++i){
        fact[i] = fact[i - 1] * i;
    }
    vi vec;
    for(int i{1}; i <= n; ++i){
        vec.push_back(i);
    }
    int op;
    cin >> op;
    if(op == 1){
        ll a;
        cin >> a;
        for(int i{1}; i < n; ++i){
            ll k = (a - 1) / fact[n - i];
            cout << vec[k] << " ";
            vec.erase(vec.begin() + k);
            a -= fact[n - i] * k;
        }   
        cout << vec.front();
    }
    else{
        vi A(n);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        ll ans{1};
        for(int i{0}; i < n; ++i){
            int idx = find(vec.begin(), vec.end(), A[i]) - vec.begin();
            ans += fact[n - i - 1] * idx;
            vec.erase(vec.begin() + idx);
        }
        cout << ans;
    }
}
