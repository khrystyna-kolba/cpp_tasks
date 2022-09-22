#include<iostream>
using namespace std;
double thesmallest(double* arr,int n) {
	double s = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < s) {
			s = arr[i];
		}
	}
	return s;
}
void change(double* arr, int in, double newn) {
	arr[in] = newn;
}
int main() {
	int n;
	cin >> n;
	n++;
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	double small = thesmallest(arr, n);
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (check) {
			change(arr, i, 0.5);
		}
		if (arr[i] == small) {
			check = true;
		}

	}
	for (int i = 0; i < n; i++) {
		cout<< arr[i]<<" ";
	}
	cout << endl;

	delete[]arr;
}