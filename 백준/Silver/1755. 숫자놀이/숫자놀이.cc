// 2022-08-19
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
	vs vec(10);
    vec = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<pair<string, int> > A;
    int a, b;
    cin >> a >> b;
    for(int i{a}; i <= b; ++i){
        string str;
        string k = to_string(i);
        for(int j{0}; j < (int)k.size(); ++j){
            str += vec[k[j] - '0'];
        }
        A.push_back({str, i});
    }
    sort(A.begin(), A.end());
    for(int i{0}; i < (int)A.size(); ++i){
        cout << A[i].second << " ";
        if(i % 10 == 9) cout << "\n";
    }
}