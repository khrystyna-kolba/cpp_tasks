#include<iostream>
#include<list>
using namespace std;
//pos of the minimum of list
template<typename T>
int pos_of_minimum(list<T> y) {
	if (y.size() == 0) {
		return 0;
	}
	T min = y.front();
	int min_pos = 1;
	int pos = 1;
	for (auto x : y) {
		if (x < min) {
			min = x;
			min_pos = pos;
		}
		pos++;
	}
	return min_pos;
}

//insert e1 before first e
template<typename T>
void insert(list<T>& y, T e, T e1) {
	for (auto it = y.begin(); it != y.end();it++) {
		if (*it == e1) {
			y.insert(it, e);
			return;
		}
	}
}
//add l2 to l1
template<typename T>
void add_list(list<T>& y, list<T> to_add) {
	for (auto x: to_add) {
		y.insert(y.end(), x);
	}
}
int main() {
	list<int> x = { 3,5,3,2,1,0,-5,4,7 };
	list<int> k = { 54,87,46,21233,66 };
	cout << "minimun element is on pos(from 1 to n): "<<pos_of_minimum(x) << endl;
	cout << "69 before 2 inserted: " << endl;
	insert(x, 69, 2);
	for (auto& y : x) {
		cout << y << " ";
	}
	cout << endl;
	cout << "list k in the end of list x added: " << endl;
	add_list(x, k);
	for (auto& y : x) {
		cout << y << " ";
	}
}