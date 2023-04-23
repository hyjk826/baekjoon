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
    cout << "n e\n";
    cout << "- -----------\n";
    int k{1};
    double sum{0};
    cout << fixed << setprecision(9);
    cout << "0 1" << "\n";
    cout << "1 2" << "\n";
    cout << "2 2.5" << "\n";
    for(int i{0}; i <= 9; ++i){        
        sum += 1.0 / k;
        k *= (i + 1);        
        if(i <= 2) continue;
        cout << i << " ";
        cout << sum << "\n";
    }
}
