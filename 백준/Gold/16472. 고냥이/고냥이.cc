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
    int k;
    cin >> k;
    string str;
    cin >> str;
    vi ch(26);
    int j{0};
    int ans{0};
    int cnt{0};
    for(int i{0}; i < (int)str.size(); ++i){
        while(j < (int)str.size() && (cnt < k || (cnt == k && ch[str[j] - 'a'] >= 1))){
            ch[str[j] - 'a']++;
            if(ch[str[j] - 'a'] == 1) cnt++;
            j++;
        }
        ans = max(ans, j - i);
        ch[str[i] - 'a']--;
        if(ch[str[i] - 'a'] == 0) cnt--;
    }
    cout << ans;
}
