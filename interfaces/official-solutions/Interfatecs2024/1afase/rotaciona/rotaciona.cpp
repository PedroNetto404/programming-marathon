#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#define PII 3.1415
#define RAD(X) (X * (PII / 180))

int main (int argc, char *argv[]) {
  int n;
  float ang, x, y, rad, nx, ny;

  cin >> n >> ang;
  rad = RAD(ang);
  cout << fixed << setprecision(2);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    nx = x*cos(rad) + y*-sin(rad);
    nx = nx > -0.009 and nx < -0.001 ? fabs(nx) : nx;
    ny = x*sin(rad) + y*cos(rad);
    ny = ny > -0.009 and ny < -0.001 ? fabs(ny) : ny;
    cout << nx << " " << ny << "\n";
  }

  return 0;
}
