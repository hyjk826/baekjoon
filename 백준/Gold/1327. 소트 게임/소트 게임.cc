// 2022-11-25
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
    int n, k;
    cin >> n >> k;
    string str;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        str += char('0' + a);
    }
    queue<string> Q;
    Q.push(str);
    map<string, int> mp;
    mp[str] = 0;
    while(!Q.empty()){
        string s = Q.front();
        int a = mp[s];
        Q.pop();
        for(int i{0}; i + k <= n; ++i){
            reverse(s.begin() + i, s.begin() + i + k);
            if(mp.count(s) == 0){
                mp[s] = a + 1;
                Q.push(s);
            }            
            reverse(s.begin() + i, s.begin() + i + k);
        }
    }
    string t;
    for(int i{1}; i <= n; ++i){
        t += char('0' + i);
    }
    if(mp.count(t)) cout << mp[t];
    else  cout << -1;
}
	
