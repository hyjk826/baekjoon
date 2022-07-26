// 2022-07-26
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
    int n;
    cin >> n;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            for(int i{b}; i <= n; i += b) vec[i] ^= 1;
        }
        else{
            for(int i{0}; i < n; ++i){
                if(b - i < 1 || b + i > n) break;
                if(vec[b - i] == vec[b + i]){
                    if(i == 0) vec[b - i] ^= 1;
                    else{
                        vec[b - i] ^= 1;
                        vec[b + i] ^= 1;
                    }
                }
                else break;
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        cout << vec[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
}

