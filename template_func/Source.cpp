#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void two_min_change(T** matrix, size_t n, size_t m) {
	size_t min1_r_index=0;
	size_t min2_r_index=0;
	size_t min1_c_index = 0;
	size_t min2_c_index = 0;
	T min1 = matrix[0][0];
	T min2 = matrix[0][0];
	T temp_val;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if (matrix[i][j] < min1) {
				min1 = matrix[i][j];
				min1_r_index = i;
				min1_c_index = j;
			}
			if ((min2 == min1 && (min1_r_index == min2_r_index && min1_c_index == min2_c_index))||(matrix[i][j] < min2&&matrix[i][j]>min1)|| (matrix[i][j] == min1&&(min1_r_index!= i || min1_c_index != j))) {
				min2 = matrix[i][j];
				min2_r_index = i;
				min2_c_index = j;
			}
		}
	}
	if (min1_r_index != min2_r_index) {
		for (size_t j = 0; j < m; j++) {
			temp_val = matrix[min1_r_index][j];
			matrix[min1_r_index][j] = matrix[min2_r_index][j];
			matrix[min2_r_index][j] = temp_val;
		}
	}

}


int main() {
	ifstream fin("sample.txt");//читання з файлу
	int n, m;


	//first ints
	fin >> n >> m;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			fin >> arr[i][j];
		}
	}
	two_min_change(arr,n,m);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	cout << endl;
	//second ints
	fin >> n >> m;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			fin >> arr[i][j];
		}
	}
	two_min_change(arr, n, m);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	//third chars
	fin >> n >> m;
	char** ar = new char* [n];
	for (int i = 0; i < n; i++) {
		ar[i] = new char[m];
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			fin >> ar[i][j];
		}
	}
	two_min_change(ar, n, m);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] ar[i];
	}
	delete[] ar;

	cout << endl;
	//forth char
	fin >> n >> m;
	ar = new char* [n];
	for (int i = 0; i < n; i++) {
		ar[i] = new char[m];
	}
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			fin >> ar[i][j];
		}
	}
	two_min_change(ar, n, m);
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] ar[i];
	}
	delete[] ar;

	fin.close();
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

}