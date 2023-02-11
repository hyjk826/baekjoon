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
    int n, m;
    cin >> n >> m;
    queue<int> Q;
    vi ch((int)1e6 + 1);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        Q.push(a);
        ch[a] = 1;
    }
    int cnt{0};
    for(int i{0}; i <= 1e6; ++i){
        if(ch[i]) continue;
        if(!Q.empty() && Q.front() - m <= i && i < Q.front() && cnt){
            Q.pop();
            cnt--;
        }
        else cnt++;
    }
    if(Q.empty()) cout << "success";
    else cout << "fail";
}
