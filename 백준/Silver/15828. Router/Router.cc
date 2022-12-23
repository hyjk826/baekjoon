// 2022-12-24
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
    queue<int> Q;
    while(1){
        int a;
        cin >> a;
        if(a == -1) break;
        if(a == 0){
            Q.pop();
        }
        else{
            if(Q.size() == n) continue;
            Q.push(a);
        }
    }
    if(Q.empty()) cout << "empty\n";
    else{
        while(!Q.empty()){
            cout << Q.front() << " ";
            Q.pop();
        }
    }
}
