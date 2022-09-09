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

int main(){
    fastio;
    vi cnt((int)1e7 + 1, -1);
    int n;
    cin >> n;
    queue<int> Q;
    cnt[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        if(x % 3 == 0){
            if(cnt[x / 3] == -1){
                cnt[x / 3] = cnt[x] + 1;
                Q.push(x / 3);
            }
        }
        if(x % 2 == 0){
            if(cnt[x / 2] == -1){
                cnt[x / 2] = cnt[x] + 1;
                Q.push(x / 2);
            }
        }
        if(x >= 1 && cnt[x - 1] == -1){
            cnt[x - 1] = cnt[x] + 1;
            Q.push(x - 1);
        }
    }
    cout << cnt[1];
}