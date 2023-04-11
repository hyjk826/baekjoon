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

int cnt[1000001];

int main(){
	fastio;
    int n;
    cin >> n;    
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(cnt[a + 1]){
            cnt[a + 1]--;
            cnt[a]++;
        }
        else{
            cnt[a]++;
            ans++;
        }
    }
    cout << ans;
}
