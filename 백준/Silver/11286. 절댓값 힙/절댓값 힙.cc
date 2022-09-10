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

struct st{
    int x;
    bool operator< (const st a) const{
        if(abs(x) == abs(a.x)){
            return x > a.x;
        }
        else return abs(x) > abs(a.x);
    }
};

int main(){
    fastio;
    priority_queue<st> pQ;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 0){
            if(pQ.empty()) cout << 0 << "\n";
            else{
                cout << pQ.top().x << "\n";
                pQ.pop();
            }
        }
        else pQ.push({n});
    }
}