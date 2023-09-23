#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#define lli long long int
#define mp make_pair
#define ULTRA_INSTINCT                 \
     ios_base::sync_with_stdio(false); \
     cin.tie(0)
#define fo(i, n) for (lli i = 0; i < (n); i++)
#define FO(i, x, n) for (lli i = (x); i < (n); i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli, lli>
#define vii vector<pi>
#define Endl "\n"
using namespace std;
const lli mod = 1e9 + 7;

lli gcd(lli a, lli b){
      if (b == 0)
        return a;
      return gcd(b, a % b);
}


void solve(){
     lli n, m,k;
     cin>>n>>m>>k;

     vi a(n) , b(m);
     fo(i,n){
          cin>>a[i];
     }
     fo(i,m){
          cin>>b[i];
     }

     sort(b.begin(),b.end());

     vi B(m);
     B[0] = b[0];
     FO(i,1,m){
          B[i] = B[i-1] + b[i];
     }

     lli ans = 0;

     fo(i,n){
          // if a[i] + b[j] > k, then b[j] > k - a[i] ... find this value

          lli tb = k - a[i];

          vi :: iterator it = lower_bound(b.begin(),b.end(), tb);

          lli idx = it - b.begin();

          // cout<<idx<<"  is  for "<<a[i]<<"\n"; 
          lli sum = (idx * a[i]) + ( idx >0 ? B[idx-1] : 0) + (m-idx) * k;

          ans += sum;
          // cout<<sum<<" at "<<a[i]<<"\n";

     }

     cout<<ans<<"\n";
}

int main(){

     ULTRA_INSTINCT;
     lli t = 1;
     // cin >> t;
     fo(i, t){
          //   cout<<"Case #"<<i+1<<": ";
          solve();
     }
     return 0;
}