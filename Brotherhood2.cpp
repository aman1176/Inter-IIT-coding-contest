
/*
AUTHOR: Aman Raj
College:IIT JODHPUR
Branch:CSE
LANG: C++
*/

using namespace std;

typedef     long long ll;
#include <bits/stdc++.h>


//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
#define fast  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin,a.rend()
//#define mod 998244353





#define inf 1e18
//#define mod 3
#define flush fflush(stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<ll, ll, hash< ll > > ht;

// find_by_order()  // order_of_key
typedef tree<
    pair<ll,ll>,
    null_type,
    less<pair<ll,ll> >,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;




ll mod=1e9+7;

ll power1(ll a, ll b)//a raised to power b
   {  if(b<=0) return 1; if(b==1) return a;
       ll c=power1(a,b/2);
        c*=c;c%=mod;if(b%2==1) c*=a;c%=mod;
        return c;
   }
   ll mi(ll a)
   { ll c= power1(a,mod-2);

     return c;
   }



 struct less_then_greater {
    template<typename T, typename U>
    bool operator()(T const& lhs, U const& rhs) const {
        if (lhs.first < rhs.first) return true;
        if (rhs.first < lhs.first) return false;
        return lhs.second > rhs.second;
    }
};

 /*std::priority_queue<std::pair<int, int>,
                    std::vector<std::pair<int, int>>,
                    less_then_greater
                    > pq;*/
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
//cout<<"Case #"<<tt<<": "<<ans<<endl;

void self_max(ll &a,ll b)
{
    a=max(a,b);
}

int main()
{  fast;
   ll t;cin>>t;
    while(t--)
    {
        ll a,b,k1,k2;
        cin>>a>>b>>k1>>k2;
        bool ok=true;
        if(k1!=k2&&(k1>0&&k2>0))
        {ll y2=(a*k2-b*k1)/(k2*k2-k1*k1);
        if(y2*(k2*k2-k1*k1)!=a*k2-b*k1){ok=false; }
        ll y1=(a-k2*y2)/k1;
        if(y1*k1!=a-k2*y2){ok=false;}
        }
        else if(k1==k2)
        {   if(a!=b)ok=false;
            if(k1>0)
            {
            if(a%k1==0){ }
            else ok=false;
            }
            else
            {
               if(a!=0)ok=false;
            }
        }
        else
        {   //both are different
            ll k=max(k1,k2);
            if(a%k==0&&b%k==0){ }
            else ok=false;
        }

        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

   return 0;
}
