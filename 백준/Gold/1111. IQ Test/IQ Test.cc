// 2023-01-12
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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    if(n == 1) cout << 'A';
    else if(n == 2){
        if(vec[0] == vec[1]) cout << vec[0];
        else cout << "A";
    }
    else{
        if(vec[0] == vec[1]){
            bool ok = true;
            for(int i{2}; i < n; ++i){
                ok &= (vec[i] == vec[0]);
            }
            if(ok) cout << vec[0];
            else cout << "B";
        }
        else{
            if((vec[1] - vec[2]) % (vec[0] - vec[1]) == 0){
                int x = (vec[1] - vec[2]) / (vec[0] - vec[1]);
                int y = -vec[0] * x + vec[1];
                bool ok = true;
                for(int i{2}; i < n; ++i){
                    ok &= (vec[i] == vec[i - 1] * x + y);
                }
                if(ok) cout << vec.back() * x + y;
                else cout << "B";
            }
            else cout << "B";
        }
    }
}
