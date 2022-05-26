// 2022-05-27
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
        string str;
        cin >> str;
        string ans = "";
        int n = (int)str.size();
        for(int i{0}; i < n; i += 2){
            ans += str[i];
        }
        if(n & 1){
            for(int i{1}; i < n; i += 2){
                ans += str[i];
            }
        }
        string ans2 = "";
        for(int i{1}; i < n; i += 2){
            ans2 += str[i];
        }
        if(n & 1){
            for(int i{0}; i < n; i += 2){
                ans2 += str[i];
            }
        }
        cout << ans << "\n" << ans2 << "\n";
    }
}