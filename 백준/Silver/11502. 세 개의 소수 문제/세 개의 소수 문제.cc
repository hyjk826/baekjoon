// 2022-08-19
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
    vi prime(1001);
    prime[1] = 1;
    for(int i{2}; i <= 1000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 1000; j += i){
                prime[j] = 1;
            }
        }
    }
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = false;
        vi ans(3);
        for(int i{2}; i < 1000; ++i){
            for(int j{i}; j < 1000; ++j){
                if(prime[i] == 0 && prime[j] == 0 && n - i - j > 0 && prime[n - i - j] == 0){
                    ans[0] = i;
                    ans[1] = j;
                    ans[2] = n - i - j;
                    flag = true;
                }
            }
        }
        if(!flag) cout << 0 << "\n";
        else{
            sort(ans.begin(), ans.end());
            for(auto& i : ans){
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}