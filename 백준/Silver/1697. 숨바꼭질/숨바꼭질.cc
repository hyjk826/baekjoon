// 2022-09-06
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
    int n, k;
    cin >> n >> k;
    vi ch(200001, -1);
    ch[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        if(x >= 1 && ch[x - 1] == -1){
            ch[x - 1] = ch[x] + 1;
            Q.push(x - 1);
        }
        if(x + 1 <= 200000 && ch[x + 1] == -1){
            ch[x + 1] = ch[x] + 1;
            Q.push(x + 1);
        }
        if(2 * x <= 200000 && ch[x * 2] == -1){
            ch[x * 2] = ch[x] + 1;
            Q.push(2 * x);
        }
    }
    cout << ch[k];
}
	

