#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<iterator>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli,lli>
#define vii vector<pi >
#define Endl endl
#define ITA 200005
#define ROH 100005
#define deb(x) cout<<(#x)<<" "<<x<<endl
using namespace std;
const lli mod = 1e9 +7;
lli test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}


// problem link : https://cses.fi/problemset/task/1637/

lli n;

lli dp[(int)1e6+1];

lli f(lli num){
    if(num == 0){
        return 0;
    }
    if(dp[num] != -1){
        return dp[num];
    }
    vi v;
    lli x = num;
    while(x>0){
        if(x%10 !=0){
            v.pb(x%10);
        }
        x/=10;
    }
    lli here = num;
    for(lli digi : v){
        here = min(here , f(num - digi) + 1);
    }
    dp[num] = here;
    return here;
}
void solve(){
    cin>>n;
    fo(i,n+1){
        dp[i] = -1;
    }
    cout<<f(n)<<endl;
}
 
int main(){
    ULTRA_INSTINCT;
    lli t =1;
    // cin>>t;
    fo(i,t){
        solve();
    }
    return 0;
}
 