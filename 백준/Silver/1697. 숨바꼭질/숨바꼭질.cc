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
    vi cnt(200001, -1);
    int a, b;
    cin >> a >> b;
    cnt[a] = 0;
    queue<int> Q;
    Q.push(a);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        if(x * 2 <= 200000 && cnt[x * 2] == -1){
            cnt[x * 2] = cnt[x] + 1;
            Q.push(x * 2);
        }
        if(x - 1 >= 0 && cnt[x - 1] == -1){
            cnt[x - 1] = cnt[x] + 1;
            Q.push(x - 1);
        }
        if(x + 1 <= 200000 && cnt[x + 1] == -1){
            cnt[x + 1] = cnt[x] + 1;
            Q.push(x + 1);
        }
    }
    cout << cnt[b];
}