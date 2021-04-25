#include <iostream>
#include <math.h>
#include<array>
#include <fstream>
using namespace std;
float f(double y)
{
    return(1 +y*y);
}
int main()
{
ofstream myfile("eredmeny.txt");//eredmeny fajl letrehozasa es megnyitasa
myfile <<"newton:  runge_k: analitikus:\n";
//newton modszerel
int n=100;//lepes szam
double h=0.01;//iteracios lepes hossz
double y[n];//y taralo vektor newton modszer eseten
double y2[n];//y taralo vektor Runge kutta modszer eseten
double y3[n];//y taralo vektor analitikus megoldasra

y[0]=0.0;//kezdeti ertek
double tn=0;
double k1,k2,k3,k4;

for(int i=1;i<n+1;i++){

    y[i]=y[i-1]+h*f(y[i-1]);//

    k1 = h*f(y[i-1]);//runge kutta egyuthatok
    k2 = h*f( y[i-1] + 0.5*k1);
    k3 = h*f(y[i-1] + 0.5*k2);
    k4 = h*f(y[i-1] + k3);
    y2[i]=y[i-1]+(h/6)*(k1+2*k2+2*k3+k4);

    y3[i]=tan(0+(i-1)*h);
    std::cout <<y[i]<<"  "<<y2[i]<<"  "<<y3[i]<<"\n";
    myfile <<y[i]<<"  "<<y2[i]<<"  "<<y3[i]<<"\n";//fajlba kiiras
}
myfile.close();
    return 0;
}
