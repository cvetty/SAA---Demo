#include <iostream>
using namespace std;
#define N 2
#define M 3


// Helper functions
unsigned int factorial(unsigned int n) 
{ 
    if (n == 0 || n == 1) 
        return 1; 

    return n * factorial(n - 1); 
} 

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}


int calculateGCD(int a, int b) {
    int gcd;
    
    // swapping variables if needed
    if (b > a) {   
        int temp = b;
        b = a;
        a = temp;
    }
    
    for (int i = 1; i <=  a; ++i) {
        if (a % i == 0 && b % i ==0) {
          gcd = i;
        }
    }
    
    return gcd;
}


int main()
{
	int i, j, arr[N][M];

	cout << "Enter the elements of two-dimensional array\n";
	for (i = 0; i < N; i++) {
	    for (j = 0; j < M; j++) {
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}    
	}

    // Following the combinations formula (nCr = n!/(r! * (n - r)!))
    int elementsCount = N * M;
    int combinationsCount = factorial(elementsCount) / (factorial(2) * factorial(elementsCount - 2));
    
    // Flatten array
    int flattenArr[elementsCount];
    int elementIndex = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            flattenArr[elementIndex] = arr[i][j];
            elementIndex++;
        }
	}

	
    // Creating the final divisors array
    int divisors[combinationsCount];
    int divisorIndex = 0;
    for (int i = 0; i < elementsCount; i++) {
        for (int i2 = 0; i2 < elementsCount; i2++) {
            divisors[divisorIndex] = calculateGCD(flattenArr[i], flattenArr[i2]);
            divisorIndex++;
        }
	}

    bubbleSort(divisors, combinationsCount);

	return 0;
}
