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
        if(n & 1){
            int s = (3 * n + 3) / 2;
            cout << "Yes\n";
            int j = (n + 1) / 2;
            for(int i{2 * n}; i > 2 * n - (n + 1) / 2; --i){
                cout << i << " " << j << "\n";
                j--;
            }
            s++;
            for(int i{(n + 1) / 2 + 1}; i < (n + 1) / 2 + 1 + n / 2; ++i){
                cout << i << " " << s - i << "\n";
                s += 2;
            }
        }
        else{
            cout << "No\n";
        }
    }
}
