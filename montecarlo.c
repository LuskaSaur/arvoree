#include <stdio.h>
#include <limits.h>
#include <time.h>

long long int rseed = 0;
clock_t start, end;
double cpu_time_used;

long long int rrand(){

  return rseed = (rseed * 1664525 + 1013904223) % INT_MAX;
  }


double monteCarloPi(int n){
  int acertos = 0;
  float x,y=0;
  for(int i; i < n; i++){
    x = ( rrand()/ (double)INT_MAX);
    y = ( rrand()/ (double)INT_MAX);
    if (x*x + y*y < 1){
      acertos++;
    }
  }
  double pi = ((double)acertos*4)/(double)n;
  return pi;

}

int main() {
  start = clock();
  printf("%f\n",monteCarloPi(5000000));
  end = clock();
  cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
  printf(" time (sec) = %f\n",cpu_time_used );
}
