// 2022-05-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int w{0}, b{0};
        for(int i{0}; i < n; ++i){
            if(s[i] != t[i]){
                if(s[i] == 'W') w++;
                else b++;
            }
        }
        cout << max(w, b) << "\n";
    }
}