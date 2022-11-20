// 2022-11-20
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

bool checkPrime(int n){
    if(n == 1) return false;
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
	fastio;	
	int t;
    cin >> t;
    while(t--){
        int a, c;
        cin >> a >> c;
        int b = c;
        set<int> st;
        bool ok = false;
        while(1){
            if(b == 1){
                ok = true;
                break;
            }
            int sum{0};
            while(b){
                sum += (b % 10) * (b % 10);
                b /= 10;
            }
            if(st.count(sum)) break;
            st.insert(sum);
            b = sum;
        }
        cout << a << " " << c << " ";
        if(ok && checkPrime(c)) cout << "YES\n";
        else cout << "NO\n";
    }
}
	

