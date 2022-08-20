// 2022-08-21
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    vi ch(101, -1);
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(ch[a] == -1) ch[a] = b;
        else{
            if(ch[a] == b) continue;
            ans++;
            ch[a] = b;
        }
    }    
    cout << ans;
}