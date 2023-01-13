// 2023-01-13
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
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << "\n";
            continue;
        }
        vp ch(n, {-1,-1});
        ch[1] = {-2, 1};
        queue<int> Q;
        Q.push(1);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(int i{0}; i < 2; ++i){
                if(ch[(x * 10 + i) % n].first == -1){
                    ch[(x * 10 + i) % n] = {x, i};
                    Q.push((x * 10 + i) % n);
                }
            }
        }
        if(ch[0].first == -1) cout << "BRAK\n";
        else{
            string ans;
            int k = 0;
            while(k != -2){
                ans += char('0' + ch[k].second);
                k = ch[k].first;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
}
