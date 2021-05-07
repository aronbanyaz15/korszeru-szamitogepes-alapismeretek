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

template<typename T>
polinom<T> operator+( polinom<T> const& v1, polinom<T> const& v2 )
{
polinom<T> result; result.data.resize(v1.data.size());
std::transform(v1.data.begin(),
v1.data.end(),
v2.data.begin(),
result.data.begin(),
[](T const& x, T const& y){ return x+y; });
return result;

}


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

template<typename T>
polinom<T> operator*( polinom<T> const& v1, polinom<T> const& v2 )
{
polinom<T> result; result.data.resize(v1.data.size());
std::transform(v1.data.begin(),
v1.data.end(),
v2.data.begin(),
result.data.begin(),
[](T const& x, T const& y){ return x*y; });
return result;
}



template<typename T>
double ertek( polinom<T> const& a, double n )
{
    int len = sizeof(a)/sizeof(a.data[0]);
    double f=0;
    for (int i=0;i<len;i++){
        f=f+a.data[i]*pow(n,i);
    }
return f;
}

template<typename T>
double deriv( polinom<T> const& a, double x,double dx )
{
    double df=0;//derivalt
    double s=(ertek(a,x+dx)-ertek(a,x-dx))/(2*dx);
    double s2=(ertek(a,x+2*dx)-ertek(a,x-2*dx))/(4*dx);
    df=(16*s-s2)/15;//derivalt kiszamolasa

return df;
}

template<typename T>
double integral( polinom<T> const& p, double a,double b,int n )
{

    double s=0;//integralas erteke
    double dx=(b-a)/n;
   for(int i=0;i<n;i++){

        s+=ertek(p,i*dx)*dx;
    }

return s;
}

template<typename T>
double newton_iterator( polinom<T> const& a ,double x0)
{
double x1=x0-ertek(a,x0)/deriv(a,x0,0.001);
while (abs(x1-x0)>0.0001){
    x0=x1;
    x1=x0-ertek(a,x0)/deriv(a,x0,0.001);
}
    return x1;
    }





int main()
{

    polinom<double> v {{1,1,1}};
    polinom<double> u {{2,2,2}};

    auto y2=v+u;
    auto y3=v*u;
    auto y4=v-u;
    polinom<double> b {{1.0,1.0,0.0}};
    double e=ertek(b,1);
    double d=deriv(b,1.110,0.001);
    double i=integral(b,0,1,100000);
    double n=newton_iterator(b,2.2);

    std::cout << y2.data[0] << y2.data[1] << y2.data[2]<< " osszeadas\n";
    std::cout << y3.data[0]  <<y3.data[1] <<y3.data[2]<< " szorzas\n";
    std::cout << y4.data[0] <<y4.data[1]<<y4.data[2]<< " kivonas\n";

    std::cout << e << " ertek\n";
    std::cout << d << " derivalt\n";
    std::cout << i << " integral\n";
    std::cout << n << "newton\n";



        return 0;


}

