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
        int a{0}, b{0};
        for(int i{0}; i < n; ++i){            
            char x, y;
            cin >> x >> y;
            if(x == 'R'){
                if(y == 'P') b++;
                else if(y == 'S') a++;
            }
            else if(x == 'P'){
                if(y == 'R') a++;
                else if(y == 'S') b++;
            }
            else if(x == 'S'){
                if(y == 'R') b++;
                else if(y == 'P') a++;
            }            
        }
        if(a > b) cout << "Player 1\n";
        else if(a < b) cout << "Player 2\n";
        else cout << "TIE\n";
    }
}
