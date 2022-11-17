// 2022-11-16
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

int main() {
	fastio;
    vi prime(4000001);
    prime[1] = 1;
    for(int i{2}; i <= 4000000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 4000000; j += i){
                prime[j] = 1;
            }
        }
    }
    int a, b, d;
    cin >> a >> b >> d;
    int ans{0};
    for(int i{a}; i <= b; ++i){
        if(prime[i] == 0){
            int c = i;
            bool flag = false;
            while(c){
                flag |= ((c % 10) == d);
                c /= 10;
            }
            if(flag) ans++;
        }
    }
    cout << ans;
}
	

