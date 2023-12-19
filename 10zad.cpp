#include <iostream>

using namespace std;

// The Fibonacci sequence formula
int fib(int n)
{
  if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else 
      return fib(n-1) + fib(n-2);
}

int main()
{
	int n;
	cout << "n: "; 
	cin >> n;
	
	if (n < 0 || n > 20) {
	    cout << "'n' must be in the rage [0, 20]";
	    return 1;
	}
	
	cout << "F(n): " << fib(n) << "\n";
	return 0;
}