// 2022-11-21
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

int f(string a, string b){
    int x, y, z;
    x = y = z = 0;
    for(int i{0}; i < 4; ++i){
        int k = a[i] - b[i];
        x += k * k;
    }
    for(int i{4}; i < 6; ++i){
        int k = a[i] - b[i];
        y += k * k;
    }
    for(int i{6}; i < 8; ++i){
        int k = a[i] - b[i];
        z += k * k;
    }
    return x * y * z; 
}

int main() {
	fastio;	
	string str;
    int n;
    cin >> str >> n;
    string ans;
    int mx{-1};
    vector<string> A;
    for(int i{0}; i < n; ++i){
        string s;
        cin >> s;
        int k = f(str, s);
        if(mx < k){
            A.clear();
            mx = k;
            A.push_back(s);
        }
        else if(mx == k){
            A.push_back(s);
        }
    }
    sort(A.begin(), A.end());
    cout << A[0];
}
	

