// 2022-12-18
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
	for(int i{1};;++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) break;
        int ans{0};
        cout << "Triangle #" << i << "\n";
        if(a == -1){
            ans = max(ans, c * c - b * b);
        }
        else if(b == -1){
            ans = max(ans, c * c - a * a);
        }
        else if(c == -1){
            ans = max(ans, a * a + b * b);
        }
        if(ans == 0) cout << "Impossible.\n\n";
        else{
            if(a == -1) cout << "a = ";
            else if(b == -1) cout << "b = ";
            else if(c == -1) cout << "c = ";
            cout << fixed << setprecision(3);
            cout << sqrt(ans) << "\n\n";
        }
    }
}
	
