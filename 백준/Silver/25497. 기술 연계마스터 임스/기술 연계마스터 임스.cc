// 2022-09-17
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans{0};
    vi ch(2);
    for(int i{0}; i < n; ++i){
        if('1' <= str[i] && str[i] <= '9') ans++;
        else{
            if(str[i] == 'S') ch[0]++;
            else if(str[i] == 'K'){
                if(ch[0]){
                    ans++;
                    ch[0]--;
                }
                else break;
            }
            else if(str[i] == 'L') ch[1]++;
            else if(str[i] == 'R'){
                if(ch[1]){
                    ans++;
                    ch[1]--;
                }
                else break;
            }
        }
    }
	cout << ans;
}
	

