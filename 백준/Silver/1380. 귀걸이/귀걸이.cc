// 2022-09-21
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
    int cnt{1};
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        vs vec(n);
        getline(cin, vec[0]);
        for(int i{0}; i < n; ++i){
            getline(cin, vec[i]);
        }
        vi ch(n);
        for(int i{0}; i < 2 * n - 1; ++i){
            int a;
            cin >> a;
            if(a == 0) break;
            char c;
            cin >> c;
            a--;   
            if(ch[a] == 0) ch[a]++;
            else ch[a]--;
        }
        cout << cnt << " ";
        for(int i{0}; i < n; ++i){
            if(ch[i]){
                cout << vec[i] << "\n";
            }
        }
        cnt++;
    }
}
	

