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
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        string str;
        cin >> str;
        for(int i{0}; i < (int)str.size(); ++i){
            int x = str[i] - 'A';
            cout << char('A' + (a * x + b) % 26);
        }
        cout << "\n";
    }
}
