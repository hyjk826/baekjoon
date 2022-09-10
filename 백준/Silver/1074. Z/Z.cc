// 2022-09-10
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

int n, r, c;
int ans{0};
void f(int x, int y, int k){
    if(x == r && y == c){
        cout << ans;
        exit(0);
    }
    else{
        if(x <= r && r < x + k && y <= c && c < y + k){
            f(x, y, k / 2);
            f(x, y + k / 2, k / 2);
            f(x + k / 2, y, k / 2);
            f(x + k / 2, y + k / 2, k / 2);
        }
        else{
            ans += k * k;
        }
    }
}

int main(){
    fastio;
    cin >> n >> r >> c;
    f(0, 0, (1 << n));
    cout << ans;
}