#include <iostream>
using namespace std;

int Solve(int x) 
{
  for (int i = 1; i<=x; i++) 
  {
    cout << "()";
    x-= i;
  }
  cout << "(";
  return x;
}


int main() 
{
  int x;
  cin >> x;

  while (x > 0) 
  {
    x =Solve(x);
  }

  return 0;
}
