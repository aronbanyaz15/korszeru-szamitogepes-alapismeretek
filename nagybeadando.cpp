#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
struct polinom {
    std::vector<T> data{};

};
//oszzeadast vegzo fugveny
template<typename T>
polinom<T> operator+( polinom<T> const& v1, polinom<T> const& v2 )//polinomok betoltese v1 v2 valtozoba
{
polinom<T> result; result.data.resize(v1.data.size());
std::transform(v1.data.begin(),
v1.data.end(),
v2.data.begin(),
result.data.begin(),
[](T const& x, T const& y){ return x+y; });
return result;

}

//kivonast vegzo fugveny
template<typename T>
polinom<T> operator-( polinom<T> const& v1, polinom<T> const& v2 )
{
polinom<T> result; result.data.resize(v1.data.size());
std::transform(v1.data.begin(),
v1.data.end(),
v2.data.begin(),
result.data.begin(),
[](T const& x, T const& y){ return x-y; });
return result;

}
//polinomok szorzasat vegzo fugveny
template<typename T>
polinom<T> szorzas( polinom<T> const& x, polinom<T> const& y )
{

       int x_len=x.data.size();//x hossza
       int y_len=y.data.size();
       vector<double> vect(x_len*y_len,0);
       polinom<double> z {vect};//eredmenyt tarolja
       for(int i=0;i<x_len;i++){
           for(int e=0;e<y_len;e++){
                z.data[i+e]+=x.data[i]*y.data[e];
      }}


return z;
}

template<typename T>
polinom<T> szammal_szorzas( polinom<T> const& x, double N )
{

       int x_len=x.data.size();

       vector<double> vect(x_len,0);
       polinom<double> z {vect};
       for(int i=0;i<x_len;i++){
            z.data[i]=N*x.data[i];

                }
return z;
}


//polinom erteket szamolo fuggveny
template<typename T>
T ertek( polinom<T> const& a, double n )
{
    int len = a.data.size();// polinom hosszanak meghatarozasa
    double f=0;
    for (int i=0;i<len;i++){

        f=f+a.data[i]*pow(n,i);
    }
return f;
}
//derivaltat szamolo fuggveny adott helyen
template<typename T>
T deriv( polinom<T> const& a, double x,double dx )
{
    double df=0;//derivalt
    double s=(ertek(a,x+dx)-ertek(a,x-dx))/(2*dx);
    double s2=(ertek(a,x+2*dx)-ertek(a,x-2*dx))/(4*dx);
    df=(16*s-s2)/15;//derivalt kiszamolasa

return df;
}

//integraltat szamolo fuggveny adott intervalumon
template<typename T>
T integral( polinom<T> const& p, double a,double b,int n )
{

    double s=0;//integralas erteke
    double dx=(b-a)/n;
   for(int i=0;i<n;i++){

        s+=ertek(p,i*dx)*dx;
    }

return s;
}
//fuggveny polinom 1 gyoket szamolja
template<typename T>
T newton_iterator( polinom<T> const& a ,double x0)
{
double x1=x0-ertek(a,x0)/deriv(a,x0,0.001);
int n=0;//futas szama
while (abs(x1-x0)>0.0001){
    if(n>1000000){return -0.0;}//ha nincs gyok akkor visszateresi ertek:-0
    n=n+1;
    x0=x1;
    x1=x0-ertek(a,x0)/deriv(a,x0,0.001);
}
    return x1;
    }


template<typename T>//polinom kirasa
polinom<T> poli_print( polinom<T> const& b )
{
int len = b.data.size();

for(int i=0;i<len;i++){
    if (b.data[i]!=0){ //csak a nem nulla egyuthatokat irja ki
        std::cout <<b.data[i]<< "x^"<<i<<" +";}
}
return b;
}


template<typename T>//polinom hatvanyozasa
polinom<T> hatvany( polinom<T> const& b,double N)
{

polinom<double> z {b.data};
for(int i=0;i<N-1;i++){
    z=szorzas(z,b); //szorzas fuggveny
}
return z;
}


template<typename T>//polinom kompozicio
polinom<T> kompozicio( polinom<T> const& f,polinom<T> const& g)
{int len_f = f.data.size();
int len_g = g.data.size();
vector<double> vec(((len_f)*(len_g)),0);
polinom<double> z {vec};

for (int i=1;i<len_f;i++ ){

    z=z+szammal_szorzas(hatvany(g,i),f.data[i]);

}

return z;
}




int main()
{

    polinom<double> v {{1,1,1}};
    polinom<double> u {{-10.1,1,3}};

    auto y2=v+u;
    auto y3=szorzas(v,u);
    auto y4=v-u;
    auto e=ertek(v,2);
    auto d=deriv(v,0.1,0.001);
    auto i=integral(v,-1,1,100000);
    auto n=newton_iterator(v,2.2);
    auto h=hatvany(u,10);
    auto fog=kompozicio(v,u);
    std::cout <<"polinom v=";
    poli_print(v);
    std::cout <<"\n polinom u=";
    poli_print(u);
    std::cout <<"\n v+u=";
    poli_print(y2);
    std::cout <<"\n v-u=";
    poli_print(y4);
    std::cout <<"\n v*u=";
    poli_print(y3);
    std::cout <<"\n v^2=";
    poli_print(h);
    std::cout <<"\n fog=";
    poli_print(fog);
    std::cout <<"\n v derivalt="<<d;
    std::cout <<"\n v integralt="<<i;


        return 0;


}
