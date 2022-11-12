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
    vi prime(1300001);
    prime[1] = 1;
    for(int i{2}; i <= 1300000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 1300000; j += i){
                prime[j] = 1;
            }
        }
    }
    vi A;
    for(int i{1}; i <= 1300000; ++i){
        if(prime[i] == 0) A.push_back(i);
    }
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if(prime[a]){
            auto l = lower_bound(A.begin(), A.end(), a);
            auto r = upper_bound(A.begin(), A.end(), a);
            cout << *r - *prev(l) << "\n";
        }
        else cout << 0 << "\n";
    }
}
	

