// 2023-01-03
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
    vi ch(n);
    int a = 0;
    for(int i{1};;++i){
        a = (a * 10 + 1) % n;
        if(a == 0){
            cout << i;
            return 0;
        }
        if(ch[a]){
            cout << -1;
            return 0;
        }
        ch[a] = 1;
    }
}
