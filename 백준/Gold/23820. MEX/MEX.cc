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

int ch[2000004];

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        ch[a] = 1;
    }
    vi A;
    for(int i{0}; i <= 2000003; ++i){
        if(ch[i]) A.push_back(i);
        ch[i] = 0;
    }
    for(auto& i : A){
        for(ll j{0}; j < (int)A.size() && 1LL * i * A[j] <= 2000003; ++j){
            ch[i * A[j]] = 1;
        }
    }
    for(int i{0}; i <= 2000003; ++i){
        if(ch[i]) continue;
        cout << i; return 0;
    }
}
