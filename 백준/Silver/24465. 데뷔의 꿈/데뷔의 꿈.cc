// 2022-12-08
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

int f(int m, int d){
    if(m == 1){
        if(d <= 19) return 12;
        else return 1;
    }
    else if(m == 2){
        if(d <= 18) return 1;
        else return 2;
    }
    else if(m == 3){
        if(d <= 20) return 2;
        else return 3;
    }
    else if(m == 4){
        if(d <= 19) return 3;
        else return 4;
    }
    else if(m == 5){
        if(d <= 20) return 4;
        else return 5;
    }
    else if(m == 6){
        if(d <= 21) return 5;
        else return 6;
    }
    else if(m == 7){
        if(d <= 22) return 6;
        else return 7;
    }
    else if(m == 8){
        if(d <= 22) return 7;
        else return 8;
    }
    else if(m == 9){
        if(d <= 22) return 8;
        else return 9;
    }
    else if(m == 10){
        if(d <= 22) return 9;
        else return 10;
    }
    else if(m == 11){
        if(d <= 22) return 10;
        else return 11;
    }
    else if(m == 12){
        if(d <= 21) return 11;
        else return 12;
    }

}



int main() {
	fastio;
    vi ch(13);
	for(int i{0}; i < 7; ++i){
        int a, b;
        cin >> a >> b;
        ch[f(a, b)] = 1;
    }
    int n;
    cin >> n;
    vp A;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(ch[f(a, b)] == 0) A.push_back({a, b});
    }
    if(A.size() == 0) cout << "ALL FAILED";
    else{
        sort(A.begin(), A.end());
        for(auto& i : A) cout << i.first << " " << i.second << "\n";
    }
}
	
