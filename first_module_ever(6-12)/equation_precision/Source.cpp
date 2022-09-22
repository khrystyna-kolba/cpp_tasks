#include<iostream>
#include<windows.h>
#include<math.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	double e, a, b, h, x, sum, obj;
	int n, k=1;
	cout << "¬вед≥ть e, a, b, n: (a<b)" << endl;
	cin >> e >> a >> b >> n;
	h = (b - a) / n;
	x = a;
	obj = -0.5;
	sum = -0.5;
	cout << sum;
	for(x;x<=b+e;x+=h){
	while (abs(obj) > e) {
		obj *= -(pow((x/3),4))/((2*k+2)*(2*k+1));
		sum += obj;
		k++;
	}
	cout << x << " " << sum << endl;
	k = 1;
	sum =obj= -0.5;
    }
}