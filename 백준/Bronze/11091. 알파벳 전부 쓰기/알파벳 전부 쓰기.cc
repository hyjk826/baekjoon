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
    string str;
    getline(cin, str);
    while(t--){
        vi cnt(26);
        getline(cin, str);
        for(auto& c: str){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
                c = tolower(c);
                cnt[c - 'a']++;
            }
            
        }
        string ans;
        for(int i{0}; i < 26; ++i){
            if(cnt[i] == 0) ans += char('a' + i);
        }
        if(ans.empty()) cout << "pangram\n";
        else cout << "missing " << ans << "\n";
    }
}
