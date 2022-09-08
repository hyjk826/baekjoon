// 2022-09-09
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

int main(){
    fastio;
	int n;
    cin >> n;
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a == 1) continue;
        bool flag = true;
        for(int j{2}; j * j <= a; ++j){
            if(a % j == 0){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans;
}