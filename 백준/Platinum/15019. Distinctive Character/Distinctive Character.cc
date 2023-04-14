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
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    vi ch(1 << k, -1);
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        int a{0};
        int k{1};
        for(int j{(int)str.size() - 1}; j >= 0; --j){
            a += (str[j] - '0') * k;
            k <<= 1;
        }
        Q.push(a);
        ch[a] = 0;
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(int i{0}; i < k; ++i){
            if(ch[x ^ (1 << i)] == -1){
                ch[x ^ (1 << i)] = ch[x] + 1;
                Q.push(x ^ (1 << i));
            }
        }
    }
    int x = max_element(ch.begin(), ch.end()) - ch.begin();
    string ans;
    while(x){
        ans += char('0' + x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << string(k - (int)ans.size(), '0') << ans;
}
