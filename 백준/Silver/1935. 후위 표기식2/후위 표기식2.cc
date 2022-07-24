// 2022-07-25
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<double> vec(n);
    string str;
    cin >> str;
    for(int i{0}; i < n; ++i) cin >> vec[i];
    vector<double> A;
    for(int i{0}; i < (int)str.size(); ++i){
        if('A' <= str[i] && str[i] <= 'Z'){
            A.push_back(vec[str[i] - 'A']);
        }
        else{
            double a, b;
            a = A.back();
            A.pop_back();
            b = A.back();
            A.pop_back();
            swap(a, b);
            if(str[i] == '+') A.push_back(a + b);
            else if(str[i] == '-') A.push_back(a - b);
            else if(str[i] == '*') A.push_back(a * b);
            else if(str[i] == '/') A.push_back(a / b);
        }
    }
    cout << fixed << setprecision(2);
    cout << A.back();
}

