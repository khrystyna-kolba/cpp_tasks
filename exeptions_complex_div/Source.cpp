#include<iostream>
using namespace std;

struct complex {
	int real;
	int imaginary;
	complex(int r=0,int i=0):real(r),imaginary(i){}
};

complex mult(complex t, double a) {
	complex b;
	b.real = (t.real * a);
	b.imaginary = (t.imaginary * a);
	return b;
}
complex mult(complex t, complex a) {
	complex b;
	b.real = (t.real * a.real) - (t.imaginary * a.imaginary);
	b.imaginary = (t.real * a.imaginary) + (t.imaginary * a.real);
	return b;
}
complex div(complex t, complex a) {
	complex b, up, z;
	up.real = a.real;
	up.imaginary = -a.imaginary;
	z = mult(a, up);
	up = mult(t,up);
	if (z.real == 0) {
		throw invalid_argument("dividing by zero");
	}
	b.real = (up.real / (z.real * 1.0));
	b.imaginary = (up.imaginary / (z.real * 1.0));
	return b;
}
int main() {
	try {
		complex a(1, -3);
		complex b(1, 2);
		complex c = div(a, b);
		cout << c.real << " " << c.imaginary << "i" << endl;

		b.real = 0;
		b.imaginary = 0;
		c = div(a, b);
		cout << c.real << " " << c.imaginary << "i" << endl;
	}
	catch(exception& x){
		cout << x.what() << endl;
	}

}