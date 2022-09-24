// 2022-09-24
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
	int T;
	cin >> T;
	for(int t{1}; t <= T; ++t){
		cout << "#" << t << " ";
        int cnt{0};
        vi ch(10);
        ll n;
        cin >> n;
        int a{0};
		while(1){
            ll k = n * (cnt + 1);
            while(k){
                if(ch[k % 10] == 0) a++;
                ch[k % 10]++;
                k /= 10;
            }  
            cnt++;
            if(a == 10) break;
        }
        cout << n * cnt << "\n";
	}
}
	

