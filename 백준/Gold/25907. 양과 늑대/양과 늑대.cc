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
    int l{1}, r{n};
    int ans{-1};
    while(l <= r){
        int mid{(l + r)/ 2};
        cout << "? " << mid << endl;
        int a;
        cin >> a;
        if(a == mid - a){
            cout << "! " << mid << endl;
            return 0;
        }
        if(a > mid - a){
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << "! 0" << endl;
}
