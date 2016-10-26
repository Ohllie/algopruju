#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull gcd(ull a, ull b){return b?gcd(b,a%b):a;}

ull mulmod(ull a, ull b, ull m){
  ull r = 0;
  while(a!=0){
    if(a & 1) r = (r+b)%m;
    a>>=1;
    b=(b<<1)%m;
  }
  return r;
}

ull mulmodplus(ull a, ull b, ull m, ull c){
  return (mulmod(a,b,m)+c)%m;
}

ull powm(ull a, ull d, ull m){
  if(!d)return 1;
  else if(d&1)return mulmod(a,powm(a,d-1,m),m);
  else return powm(mulmod(a,a,m),d>>1,m);
}

bool isprime(ull n){
  static const ull v[] = {2,325,9375,28178,
                          450775,9780504,1795265022};
  if(n == 2 || n == 3)return 1;
  if(n < 2 || ~n&1)return 0;
  ull d = n-1;
  ull s = __builtin_ctzll(d);
  d >>= s;
  for(int i = 0; i < 7; ++i){
    ull a = v[i]%n;
    if(a == 0)return 1;
    ull x = powm(a,d,n);
    if(x == 1 || x == n-1)continue;
    ull r = 0;
    for(; r < s; ++r){
      x=mulmod(x,x,n);
      if(x==n-1)break;
    }
    if(r==s)return 0;
  }
  return 1;
}

ull randint(ull s, ull e){return rand()%(e-s+1)+s;}

ull factorize_(ull n){
  if(n<4)return n;
  if(~n&1)return 2;
  if(n%3 == 0)return 3;
  ull y = randint(1, n-1);
  ull c = randint(1, n-1);
  ull m = randint(1, n-1);
  ull g = 1, r = 1, q = 1;
  ull x, i, k, ys;
  while(g==1){
    x = y;
    for(i = 0; i < r; i++)
      y = mulmodplus(y, y, n, c);
    k = 0;
    while(k<r && g==1){
      ys = y;
      ull ss = r-k;
      if(ss>m) ss=m;
      for(i=0;i<ss;i++){
        y = mulmodplus(y,y,n,c);
        ull v;
        if(x < y)v = y-x;
        else v = x-y;
        q = mulmod(q,v,n);
      }
      g = gcd(q,n);
      k += m;
    }
    r <<= 1;
  }
  if(g == n){
    do{
      ys = mulmodplus(ys,ys,n,c);
      if(x < ys)g = gcd(ys-x,n);
      else g = gcd(x-ys,n);
    }while(g == 1);
  }
  return g;
}

ull factorize(ull n){
  if(n<2||isprime(n)) return n;
  ull v;
  while((v=factorize_(n))==n);
  return v;
}

void count_prime_factors(ull n, map<ull,ull>& m){
  if(n<2)return;
  ull v = factorize(n);
  if(v==n){m[n]++;return;}
  count_prime_factors(v,m);
  count_prime_factors(n/v,m);
}

int main(){
  ull n;
  cin>>n;
  map<ull,ull> m;
  count_prime_factors(n,m);
  n=1;
  for(auto& it : m)n*=it.second+1;
  cout<<n<<'\n';
  return 0;
}

