#include<iostream>
using namespace std;
bool F1(int* arr, int n, int t) {
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] == t) {
			check = true;
		}
	}
	return check;
}
void F2(int* arr, int n, int a, int b) {
	for (int i = 0; i < n; i++) {
		if (arr[i] < a) {
			arr[i] = b;
		}
	}
}
int* input(int& n) {
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return arr;
}
void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int m, n;
	int* x = input(n);
	int* y = input(m);
	if (F1(x, n, -5)) {
		F2(x, n, 0, 10);
		print(x, n);

	}
	if (F1(y, m, -5)) {
		F2(y, m, 0, 10);
		print(y, m);
	}
}