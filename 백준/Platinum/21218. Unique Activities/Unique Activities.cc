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

struct SuffixArray {
    vi sa , lcp ;
    SuffixArray ( string &s , int lim = 256 ) {
        int n = (int)s.size() + 1, k = 0 ,a , b ;
        vi x(s.begin(), s.end() + 1) , y(n), ws(max(n,lim)),rank(n);
        sa = lcp = y, iota(sa.begin(), sa.end(),0) ;
        for ( int j = 0 , p = 0 ; p < n ; j = max ( 1 , j * 2 ) , lim = p ) {
            p = j , iota(y.begin(), y.end(),n-j);
            for(int i{0}; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(ws.begin(), ws.end(),0);
            for(int i{0}; i < n; ++i) ws[x[i]]++;
            for(int i{1}; i < lim; ++i) ws[i] += ws[i-1];
            for ( int i=n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p=1, x[sa[0]]=0;
            for(int i{1}; i < n; ++i) a = sa[ i - 1 ], b = sa[i], x[b] =
                (y[a] == y[b] && y[a+j] == y[b+j]) ? p - 1 : p ++ ;
        }
        for(int i{1}; i < n; ++i) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                 s[i+k] == s[j+k];k++);
    }
};

int main(){
	fastio;
    string str;
    cin >> str;
    SuffixArray sfx(str);
    int mn{(int)str.size()};
    int s{0};
    for(int i{1}; i <= (int)str.size(); ++i){
        int sz = str.size() - sfx.sa[i];
        int mx = sfx.lcp[i];
        if(i < (int)str.size()) mx = max(mx, sfx.lcp[i + 1]);
        if(mx < sz){
            if(mx + 1 < mn){
                mn = mx + 1;
                s = sfx.sa[i];
            }
            else if(mx + 1 == mn){
                if(sfx.sa[i] < s){
                    s = sfx.sa[i];
                }
            }
        }
    }
    cout << str.substr(s, mn);
}
