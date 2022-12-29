// 2022-12-30
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
    vi ch(1001);
    for(int i{1}; i <= 1000; ++i){
        for(int j{2}; j <= 1001; ++j){
            int a = i;
            while(a){
                if(a % j == 0) ch[i]++;
                else break;
                a /= j;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ch[n] << "\n";
    }
}
