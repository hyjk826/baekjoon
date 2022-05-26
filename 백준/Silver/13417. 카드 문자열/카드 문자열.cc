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
        int n;
        cin >> n;
        string ans = "";
        for(int i{0}; i < n; ++i){
            char c;
            cin >> c;
            if(ans.empty()){
                ans += c;
            }
            else{
                if(c <= ans.front()) ans = c + ans;
                else ans += c;
            }
        }
        cout << ans << "\n";
    }
}