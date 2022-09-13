// 2022-09-14
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
    vi p(1000000, -1);
    p[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(int i{0}; i < 3; ++i){
            if(i == 0){
                if(x % 3 == 0 && p[x / 3] == -1){
                    p[x / 3] = x;
                    Q.push(x / 3);
                }
            }
            else if(i == 1){
                if(x % 2 == 0 && p[x / 2] == -1){
                    p[x / 2] = x;
                    Q.push(x / 2);
                }
            }
            else{
                if(x >= 1 && p[x - 1] == -1){
                    p[x - 1] = x;
                    Q.push(x - 1);
                }
            }
        }
    }
    vi ans;
    for(int i{1}; i != 0; i = p[i]){
        ans.push_back(i);
    }
    cout << ans.size() - 1 << "\n";
    reverse(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << " ";
}
	

