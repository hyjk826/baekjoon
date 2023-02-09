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
    for(int i{1}; i <= t; ++i){
        cout << "String #" << i << "\n";
        string str;
        cin >> str;
        for(int j{0}; j < (int)str.size(); ++j){
            int a = str[j] - 'A';
            cout << char('A' + (a + 1) % 26);
        } 
        cout << "\n\n";
    }
}
