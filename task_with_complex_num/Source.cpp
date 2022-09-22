#include<iostream>
#include<fstream>
using namespace std;

class Numerical_object {
protected:
public:
	Numerical_object(){}
	virtual void show(ostream& os) {};
	virtual void input(istream& is) {};
	virtual double get_norm() = 0;
};


class Complex_number: public Numerical_object {
private:
	double realpart;
	double imaginarypart;
public:
	Complex_number(double a = 0, double b = 0) {
		realpart = a;
		imaginarypart = b;
	}
	double get_norm() {
		return realpart * realpart + imaginarypart * imaginarypart;
	}
	void set(double a = 0, double b = 0) {
		realpart = a;
		imaginarypart = b;
	}
	void show(ostream& os) {
		if (imaginarypart > 0) {
			if (imaginarypart == 1 && realpart == 0) {
				os << "i" << endl;
				return;
			}
			else if (imaginarypart == 1) {
				os << realpart << "+" << "i" << endl;
				return;
			}
			else if (realpart == 0) {
				os << imaginarypart << "i" << endl;
				return;
			}
			os << realpart << "+" << imaginarypart << "i" << endl;
			return;
		}
		else if (imaginarypart == 0) {
			os << realpart << endl;
			return;
		}
		else {
			if (imaginarypart == -1 && realpart == 0) {
				os << "-" << "i" << endl;
				return;
			}
			else if (imaginarypart == -1) {
				os << realpart << "-" << "i" << endl;
				return;
			}
			else if (realpart == 0) {
				os << imaginarypart << "i" << endl;
				return;
			}
			os << realpart << imaginarypart << "i" << endl;
			return;
		}
	}
	void input(istream& is) {
		cout << "enter real part of your number" << endl;
		is >> realpart;
		cout << "enter imaginary part of your number" << endl;
		is >> imaginarypart;
	}
	Complex_number add(Complex_number a) {
		Complex_number b;
		b.realpart = realpart + a.realpart;
		b.imaginarypart = imaginarypart + a.imaginarypart;
		return b;
	}
	Complex_number operator +(const Complex_number& a) {
		Complex_number b;
		b.realpart = realpart + a.realpart;
		b.imaginarypart = imaginarypart + a.imaginarypart;
		return b;
	}
	Complex_number substract(Complex_number a) {
		Complex_number b;
		b.realpart = realpart - a.realpart;
		b.imaginarypart = imaginarypart - a.imaginarypart;
		return b;
	}
	Complex_number operator -(const Complex_number& a) {
		Complex_number b;
		b.realpart = realpart - a.realpart;
		b.imaginarypart = imaginarypart - a.imaginarypart;
		return b;
	}
	Complex_number mult(Complex_number a) {
		Complex_number b;
		b.realpart = (realpart * a.realpart) - (imaginarypart * a.imaginarypart);
		b.imaginarypart = (realpart * a.imaginarypart) + (imaginarypart * a.realpart);
		return b;
	}
	Complex_number operator *(const Complex_number& a) {
		Complex_number b;
		b.realpart = (realpart * a.realpart) - (imaginarypart * a.imaginarypart);
		b.imaginarypart = (realpart * a.imaginarypart) + (imaginarypart * a.realpart);
		return b;
	}
	Complex_number mult(double a) {
		Complex_number b;
		b.realpart = (realpart * a);
		b.imaginarypart = (imaginarypart * a);
		return b;
	}
	Complex_number operator *(const double& a) {
		Complex_number b;
		b.realpart = (realpart * a);
		b.imaginarypart = (imaginarypart * a);
		return b;
	}
	Complex_number div(Complex_number a) {
		Complex_number b, up, z;
		up.realpart = a.realpart;
		up.imaginarypart = -a.imaginarypart;
		z = a.mult(up);
		up = this->mult(up);
		if (z.realpart == 0) {
			cout << "dividing by ZEROOO!!!!!" << endl;
			return b;
		}
		b.realpart = (up.realpart / (z.realpart * 1.0));
		b.imaginarypart = (up.imaginarypart / (z.realpart * 1.0));
		return b;
	}
	Complex_number operator /(Complex_number a) {
		Complex_number b, up, z;
		up.realpart = a.realpart;
		up.imaginarypart = -a.imaginarypart;
		z = a * up;
		up = this->mult(up);
		if (z.realpart == 0) {
			cout << "dividing by ZEROOO!!!!!" << endl;
			return b;
		}
		b.realpart = (up.realpart / (z.realpart * 1.0));
		b.imaginarypart = (up.imaginarypart / (z.realpart * 1.0));
		return b;
	}
	Complex_number div(double a) {
		Complex_number b;
		b.realpart = (realpart / (a * 1.0));
		b.imaginarypart = (imaginarypart / (a * 1.0));
		return b;
	}
	Complex_number operator /(double a) {
		Complex_number b;
		b.realpart = (realpart / (a * 1.0));
		b.imaginarypart = (imaginarypart / (a * 1.0));
		return b;
	}
	double module() {
		return sqrt(realpart * realpart + imaginarypart * imaginarypart);
	}
	Complex_number intpower(int a) {
		Complex_number r, t, res;
		double fi = atan2(imaginarypart, (1.0 * realpart));
		double mod = this->module();
		r.realpart = pow(mod, a);
		t.realpart = cos(a * fi);
		t.imaginarypart = sin(a * fi);
		res = r.mult(t);
		return res;

	}

};


class Square_matrix : public Numerical_object {
private:
	size_t size_;
	double** matrix_;
public:
	Square_matrix() {
		matrix_ = nullptr;
	}
	~Square_matrix() {
		for (int i = 0; i < size_; i++) {
			if (matrix_[i] != 0)delete[] matrix_[i];
		}
		if (matrix_ != 0)delete[] matrix_;
	}
	void input(istream& is) {
		for (int i = 0; i < size_; i++) {
			if (matrix_[i] != 0)delete[] matrix_[i];
		}
		if (matrix_ != 0)delete[] matrix_;
		matrix_ = new double* [size_];
		is >> size_;
		matrix_ = new double* [size_];
		for (int i = 0; i < size_; i++) {
			matrix_[i] = new double[size_];
		}
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				is >> matrix_[i][j];
			}
		}
	}
	void show(ostream& os) {
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				os << matrix_[i][j]<<" ";
			}
			os << endl;
		}
	}
	double get_norm() {
		double norm = 0;
		for (int i = 0; i < size_; i++) {
			double temp_norm = 0;
			for (int j = 0; j < size_; j++) {
				temp_norm += abs(matrix_[i][j]);
			}
			if (temp_norm > norm) {
				norm = temp_norm;
			}
		}
		return norm;
	}
};

class Vector : public Numerical_object {
private:
	double* vector_;
	size_t size_;
public:
	Vector() {
		vector_ = nullptr;
	}
	~Vector() {
		delete[] vector_;
	}
	void input(istream& is) {
		is >> size_;
		delete[]vector_;
		vector_ = new double[size_];
		for (int i = 0; i < size_; i++) {
			is >> vector_[i];
		}
	}
	void show(ostream& os) {
		for (int i = 0; i < size_; i++) {
			os<< vector_[i]<<" ";
		}
		os << endl;
	}
	double get_norm() {
		double norm = abs(vector_[0]);
		for (int i = 0; i < size_; i++) {
			if (norm > abs(vector_[i])) {
				norm = abs(vector_[i]);
			}
		}
		return norm;
	}
};

Vector* min_norm(Numerical_object** arr, int size) {
	double min;
	int count = 0;
	Vector* to_return=nullptr;
	for (int i = 0; i < size; i++) {
		Vector* v= dynamic_cast<Vector*>(arr[i]);
		if (v != nullptr) {
			count++;
			if (count == 1) min = v->get_norm();
			if (min >= v->get_norm()) {
				min = v->get_norm();
				to_return = v;
			}
		}
	}
	return to_return;
}



int main() {
	ifstream fin("Text.txt");

	if (fin.is_open())
	{
		cout << "Succes" << endl;
		int n;
		int temp_index;
		fin >> n;

		Numerical_object** arr = new Numerical_object * [n];

		for (int i = 0; i < n; i++)
		{
			fin >> temp_index;

			switch (temp_index)
			{
			case 1:
				arr[i] = new Vector;
				break;
			case 2:
				arr[i] = new Complex_number;
				break;
			case 3:
				arr[i] = new Square_matrix;
				break;

			default:
				break;
			}

			arr[i]->input(fin);
		}
		double num;
		cout << "enter num to find objects with norm that is bigger: " << endl;
		cin >> num;
		for (int i = 0; i < n; i++)
		{
			if (arr[i]->get_norm() > num) {
				arr[i]->show(cout);
			}
		}
		cout << endl;
		cout << "vector with the minimum norm: " << endl;
		min_norm(arr, n)->show(cout);
	}
	else
	{
		cout << "Something went wrong." << endl;
	}
}
