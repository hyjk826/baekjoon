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
    priority_queue<int, vi, greater<int> > mn;
    priority_queue<int> mx;
    ll a{0}, b{0};
    ll sum{0};
    for(int i{0}; i < n; ++i){
        int x, y;
        cin >> x >> y;
        sum += abs(x);
        if(mn.size() == mx.size()) {
            mx.push(y);
            a += y;
        }
        else {
            mn.push(y);
            b += y;
        }
        if(!mx.empty() && !mn.empty() && mx.top() > mn.top()){
            int aa = mx.top();
            int bb = mn.top();
            mn.pop();
            mx.pop();
            a -= aa;
            b -= bb;
            mx.push(bb);
            mn.push(aa);
            a += bb;
            b += aa;
        }
        int k = mx.top();
        cout << k << " " << sum + (ll)mx.size() * k - a + b - (ll)mn.size() * k << "\n";
    }

}
