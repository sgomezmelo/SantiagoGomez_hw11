#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double dvxdt (double x, double y){
  double G = 10;
  double M = 1000;
  double a = -(G*M/(x*x + y*y))*(x/sqrt(x*x + y*y));
  return a;
}

double dvydt (double x, double y){
  double G = 10;
  double M = 1000;
  double a = -(G*M/(x*x + y*y))*(y/sqrt(x*x + y*y));
  return a;
}

double dxdt(double vx){
  return vx;
}

double dydt(double vy){
  return vy;
}

int main(){
  double x_0 = 10;
  double y_0 = 0;

  
  double vx_0 = 0;
  double vy_0 = 5;
  double h = 0.001;
  
  double x = x_0;
  double vx = vx_0;
  double y = y_0;
  double vy = vy_0;
  double t = 0;
  
  while(x > 0.01*x_0){
    cout << t << " " << x << " " << y << " " << vx << " "<< vy << endl;
    double k1_x = dxdt(vx);
    double k2_x = dxdt(vx+k1_x*h/2);
    double k3_x = dxdt(vx+k2_x*h/2);
    double k4_x = dxdt(vx+k3_x*h);
    double k_x = (h/6)*(k1_x+2*k2_x+2*k3_x+k4_x);

    double k1_vx = dvxdt(x,y);
    double k2_vx = dvxdt(x+k1_vx*h/2,y+k1_vx*h/2);
    double k3_vx = dvxdt(x+k2_vx*h/2,y+k2_vx*h/2);
    double k4_vx = dvxdt(x+k3_vx*h,y+k3_vx*h);
    double k_vx = (h/6)*(k1_vx+2*k2_vx+2*k3_vx+k4_vx);

    double k1_y = dydt(vy);
    double k2_y = dydt(vy+k1_y*h/2);
    double k3_y = dydt(vy+k2_y*h/2);
    double k4_y = dydt(vy+k3_y*h);
    double k_y = (h/6)*(k1_y+2*k2_y+2*k3_y+k4_y);

    double k1_vy = dvydt(x,y);
    double k2_vy = dvydt(x+k1_vy*h/2,y+k1_vy*h/2);
    double k3_vy = dvydt(x+k2_vy*h/2,y+k2_vy*h/2);
    double k4_vy = dvydt(x+k3_vy*h,y+k3_vy*h);
    double k_vy = (h/6)*(k1_vy+2*k2_vy+2*k3_vy+k4_vy);

    x += k_x;
    y += k_y;
    vy += k_vy;
    vx += k_vx;
    t += h;
  }

  return 0;
  
}
