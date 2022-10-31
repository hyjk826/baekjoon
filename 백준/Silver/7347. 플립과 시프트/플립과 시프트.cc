// 2022-11-01
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
#define MOD 100000007
using namespace std;

int main() {
	fastio;
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        if(n & 1) cout << "YES\n";
        else{
            int a, b;
            a = b = 0;
            for(int i{0}; i < n; i += 2){
                if(vec[i] == 1) a++;
            }
            for(int i{1}; i < n; i += 2){
                if(vec[i] == 1) b++;
            }
            if(abs(a - b) >= 2) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
	

