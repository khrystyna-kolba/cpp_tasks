#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void print(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
double* input(int n) {
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return arr;
}
int minuscounter(double* arr, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			count++;
		}
	}
	return count;
}
void cubes(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] * arr[i] * arr[i];
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	double* x = input(n);
	double* y = input(m);
	if (minuscounter(x, n) > minuscounter(y, m)) {
		cubes(x,n);
	}
	else {
		cubes(y, m);
	}
	print(x, n);
	print(y, m);


	delete[]x;
	delete[]y;
}