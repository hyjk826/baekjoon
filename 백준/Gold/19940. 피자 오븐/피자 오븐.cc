// 2023-01-14
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
    vi A = {60, 10, -10, 1, -1};
    vector<vi> vec(61, vi(6));
    queue<vector<int>> Q;
    Q.push({0, 0, 0, 0, 0, 0});
    vi ch(61);
    ch[0] = 1;
    while(!Q.empty()){
        auto x = Q.front();
        Q.pop();
        for(int i{4}; i >= 0; --i){
            int nx{x[5] + A[i]};
            auto temp = x;
            if(nx >= 0 && nx <= 60 && ch[nx] == 0){
                ch[nx] = 1;
                temp[i]++;
                temp[5] = nx;
                vec[nx] = temp;
                Q.push(temp);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a = n / 60;
        n %= 60;
        vec[n][0] += a;
        for(int i{0}; i < 5; ++i){
            cout << vec[n][i] << " ";
        }
        cout << "\n";
        vec[n][0] -= a;
    }
}
