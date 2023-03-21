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

int f(string str){
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    return h * 60 + m;
}

int main(){
	fastio;
    int n;
    cin >> n;
    vp A;
    for(int i{0}; i < n; ++i){
        int a; string str;
        cin >> a >> str;
        A.push_back({a, f(str)});
    }
    int a{0}, b{0};
    int pre{0};
    int x{0}, y{0};
    for(int i{0}; i < n; ++i){        
        if(a > b){
            x += A[i].second - pre;
        }
        else if(a < b){
            y += A[i].second - pre;            
        }
        pre = A[i].second;
        if(A[i].first == 1) a++;
        else b++;
    }
    if(a > b){
        x += 60 * 48 - pre;
    }
    else if(a < b){
        y += 60 * 48 - pre;
    }
    cout << setfill('0');
    cout << setw(2) << x / 60 << ":" << setw(2) << x % 60 << "\n";
    cout << setw(2) << y / 60 << ":" << setw(2) << y % 60 << "\n";
}
