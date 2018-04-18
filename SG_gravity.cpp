#include <iostream>

using std::cout;
using std::endl;

/*Suma de fuerzas */
double dvdt (double x){
  double G = 10;
  double M = 1000;
  double a = -G*M/(x*x);
  return a;
}

/*Velocidad */
double dxdt(double v){
  return v;
}

int main(){
  double x_0 = 10;
  double v_0 = 30;
  double h = 0.0001;
  
  double x = x_0;
  double v = v_0;
  double t = 0;
  
  while(x > 0.01*x_0){
    /*RK para posicion */
    cout << t << " " << x << " " << v << endl;
    double k1_x = dxdt(v);
    double k2_x = dxdt(v+k1_x*h/2);
    double k3_x = dxdt(v+k2_x*h/2);
    double k4_x = dxdt(v+k3_x*h);
    double k_x = (h/6)*(k1_x+2*k2_x+2*k3_x+k4_x);

    /*RK velocidad */

    double k1_v = dvdt(x);
    double k2_v = dvdt(x+k1_v*h/2);
    double k3_v = dvdt(x+k2_v*h/2);
    double k4_v = dvdt(x+k3_v*h);
    double k_v = (h/6)*(k1_v+2*k2_v+2*k3_v+k4_v);

    /*Actualizacion*/

    x += k_x;
    v += k_v;
    t += h;
  }

  return 0;
  
}
