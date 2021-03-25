#include <iostream>
#include <cmath>
#include <array>
#include <vector>
using namespace std;
template<typename T>
struct Vector2d {
     T x, y;

Vector2d<T>& operator+=( Vector2d<T> const& v )//osszeadas es ertekadas
{
x += v.x; y += v.y;
return *this;
}

Vector2d<T>& operator-=( Vector2d<T> const& v )//kivonsas es ertekadas
{
x += -v.x; y += -v.y;
return *this;
}

Vector2d<T>& operator*=( Vector2d<T> const& v)//skalarral szorzas
{
x =x*v.x; y= y*v.x;
return *this;
}

Vector2d<T>& operator/=( Vector2d<T> const& v )
{
x =x/v.x; y=y/v.x;
return *this;
}

};

template<typename T>
Vector2d<T> operator+( Vector2d<T> const& a, Vector2d<T> const& b )//osszeadas
{
return Vector2d<T>{ a.x + b.x, a.y + b.y };
}

template<typename T>
Vector2d<T> operator-( Vector2d<T> const& a, Vector2d<T> const& b )//kivonas
{
return Vector2d<T>{ a.x - b.x, a.y - b.y };
}

template<typename T>
Vector2d<T> operator*( double a, Vector2d<T> const& b )//skalaral szorzas
{
return Vector2d<T>{ a *b.x, a*b.y };
}

template<typename T>
Vector2d<T> operator/(Vector2d<T> const& b,double a )//skalaral osztas
{
return Vector2d<T>{ b.x/a, b.y/a };
}

template<typename T>
double dot( Vector2d<T> const& a, Vector2d<T> const& b )//skalaris szorzat
{
return double{ a.x *b.x+a.x*b.y };
}

template<typename T>
double lenght( Vector2d<T> const& a)//vektor hossz
{
return double{ sqrt(a.x*a.x+a.y*a.y)};
}



int main()
{

Vector2d<double> v = {1.0, 2.0};//v vektor megadasa
Vector2d<double> u = {4.0,-2.0}; //u vektor megadasa

auto w = v+=u;

std::cout <<"osszeadas es ertekadas: "<< w.x << " " << w.y <<"\n";

auto w1 = v-=u;
std::cout <<"kivonas es ertekadas: "<< w1.x << " " << w1.y <<"\n";
u = {4.0,0};
auto w3 = v*=u;
std::cout <<"skalaral szorzas : "<< w3.x << " " << w3.y <<"\n";
u = {4.0,0};
auto w4 = v/=u;
std::cout <<"skalaral osztas:"<< w4.x << " " << w4.y <<"\n";
u = {10.0,2.4};
auto w5 = u+v;
std::cout <<"osszeadas:"<< w5.x << " " << w5.y <<"\n";

auto w6 = u-v;
std::cout <<"kivonas:"<< w6.x << " " << w6.y <<"\n";

auto w7=dot(u,v);
std::cout <<"skalaris szorzat:"<< w7<<"\n";

auto w8=lenght(u);
std::cout <<"hossz:"<< w8<<"\n";
        return 0;


}

