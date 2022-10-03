// 2022-09-25
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
    int t;
    cin >> t;
    while(t--){
        string str;
        int d;
        cin >> str >> d;
        int ans{0};
        int h = stoi(str.substr(0, 2));
        int m = stoi(str.substr(3, 2));
        while(d > 0){
            if((h >= 22 || h < 3) && d > 300){
                while(h != 8){
                    h = (h + 1) % 24;
                    d -= 60;
                }
                ans += 5000;
                d += m;
                m = 0;
            }
            else{
                h = (h + 1) % 24;
                d -= 60;
                ans += 1000;
            }
        }
        cout << ans << "\n";
    }
}
	

