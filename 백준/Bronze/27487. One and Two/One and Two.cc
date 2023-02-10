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
        int cnt{0};
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            if(vec[i] == 2) cnt++;
        }
        if(cnt & 1) cout << -1 << "\n";
        else{
            cnt /= 2;
            for(int i{0}; i < n; ++i){
                if(vec[i] == 2) cnt--;
                if(cnt == 0){
                    cout << i + 1 << "\n";
                    break;
                }
            }
        }
    }
}
