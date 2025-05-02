#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[]) {
  ofstream outfile;
  int n, start, shift, ni, lower, upper;
  double error;

  string fname(argv[1]);   // file name
  n = atoi(argv[2]);       // sequence size 
  ni = atoi(argv[3]);      // bounderies
  lower = atoi(argv[4]);   // lower limit
  upper = atoi(argv[5]);   // upper limit
  error = atof(argv[6]);   // error
  outfile.open(fname);

  outfile << n << endl;
  outfile << lower << " " << upper << endl;
  for(int i=0; i<n; i++)
    if ((double)rand() / RAND_MAX < error)
      outfile << rand() % lower << endl;
    else 
      outfile << lower + rand() % (upper-lower) << endl;

  for(int i=0; i<ni; i++) {
    start = rand() % n + 1;
    shift = start + rand() % (n-start);
    outfile << start << " " << shift << endl;
  }

  outfile.close();
  return 0;
}
