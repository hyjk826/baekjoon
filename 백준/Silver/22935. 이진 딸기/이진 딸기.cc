// 2022-12-15
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n >= 16){
            int a = (n - 16) / 14;
            int b = (n - 16) % 14;
            if(a & 1){
                n = 2 + b;
            }
            else{
                n = 14 - b;
            }
        }
        string str;
        while(n){
            str += char('0' + n % 2);
            n /= 2;
        }
        reverse(str.begin(), str.end());
        cout << string(4 - (int)str.size(), 'V');
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == '0') cout << "V";
            else cout << "딸기";
        }
        cout << "\n";
    }
}
	
