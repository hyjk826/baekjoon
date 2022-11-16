// 2022-11-16
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

int main() {
	fastio;
    int n, l;
    cin >> n >> l;
    int cnt{0};
    for(int i{1};;++i){
        bool flag = true;
        int a = i;
        while(a){
            if(a % 10 == l){
                flag = false;
                break;
            }
            a /= 10;
        }
        if(flag){
            cnt++;
        }
        if(cnt == n){
            cout << i;
            return 0;
        }
    }
}
	

