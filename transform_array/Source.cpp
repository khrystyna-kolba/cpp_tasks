#include<iostream>
using namespace std;
double * transform(double* arr, int n) {
	double current = 1;
	double minus_one = 1;
	double* result = new double[n];
	for (int i = 0; i < n; i++) {
		current = current * arr[i];
		if (i % 2 == 0) {
			minus_one = 1;
		}
		else {
			minus_one = -1;
		}
		result[i] = current * minus_one;
	}
	return result;
}
double iel(int ie, double* arr) {
	double element=1;
	if (ie % 2 == 0) {
		for (int i=0; i <= ie; i++) {
			element = element* arr[i];
		}
		return element;
	}
	else {
		for (int i=0; i <= ie; i++) {
			element = element *arr[i];
		}
	    return -1*element;	
	}
}
int main() {
    //arr[0] = arr[0] , arr[1] = -arr[0]*arr[1], arr[2] = arr[0]*arr[1]*arr[2], . , arr[n] = (-1)**n *1*2*3...*(n+1)
	int n;
	cin >> n;
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	double* arrnew = new double[n];
	for (int i = 0; i < n; i++) {
		arrnew[i] = iel(i, arr);
	}
	for (int i = 0; i < n; i++) {
		cout << arrnew[i]<<" ";
	}
	cout << endl;
	double* res = transform(arr, n);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}

	delete[]arr;
	delete[]arrnew;
	delete[]res;
}