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

int main() {
	fastio;	
	vi prime((int)1e5);
    prime[1] = 1;
    for(ll i{2}; i < (int)1e5; ++i){
        if(prime[i] == 0){
            for(ll j{i * i}; j < (int)1e5; j += i) prime[j] = 1;
        }
    }
    string str;
    while(1){
        cin >> str;
        if(str == "0") break;
        int ans{0};
        for(int i{0}; i < (int)str.size(); ++i){
            string t;       
            for(int j{i}; j < i + 5; ++j){
                t += str[j];
                if(prime[stoi(t)] == 0){
                    ans = max(ans, stoi(t));
                }
            }
        }
        cout << ans << "\n";
    }
}
	

