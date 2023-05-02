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
    int n, m;
    cin >> n >> m;
    vl X(n), Y(n);
    ll x{0}, y{0};
    for(int i{0}; i < n; ++i){
        cin >> X[i] >> Y[i];
        x += abs(X[i]);
        y += abs(Y[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    vl px = X;
    vl py = Y;
    for(int i{1}; i < n; ++i){
        px[i] += px[i - 1];
        py[i] += py[i - 1];
    }
    int a{0}, b{0};    
    while(m--){
        char c;
        cin >> c;
        if(c == 'S') b++;
        else if(c == 'J') b--;
        else if(c == 'I') a++;
        else a--;
        if(c == 'S' || c == 'J'){
            y = 0;
            int idx = lower_bound(Y.begin(), Y.end(), b) - Y.begin();
            if(idx - 1 >= 0) y += 1LL * b * idx - py[idx - 1];
            if(idx != n){
                if(idx == 0) y += py.back() - 1LL * b * (n - idx);
                else y += (py.back() - py[idx - 1]) - 1LL * b * (n - idx);
            }
        }
        else{
            x = 0;
            int idx = lower_bound(X.begin(), X.end(), a) - X.begin();
            if(idx - 1 >= 0) x += 1LL * a * idx - px[idx - 1];
            if(idx != n){
                if(idx == 0) x += px.back() - 1LL * a * (n - idx);
                else x += (px.back() - px[idx - 1]) - 1LL * a * (n - idx);
            }
        }
        cout << x + y << "\n";
    }
}
