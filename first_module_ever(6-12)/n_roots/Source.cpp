#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n;
	double a, res, d;
	cin >> n;
	a = sqrt(1.0 / 2);
	res= a;
	d = a;
	for (int i = 1; i < n; i++) {
		d = sqrt((1.0 / 2) + a*(1.0 / 2));
		a = d;
		res *= d;
	}
	cout << res << endl;
}