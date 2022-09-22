#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
template<typename T>
int counter(const vector<T> v, int i) {
	return count_if(v.begin(), v.end(), [=](T x) {
		return x != v[i];
		});
}

int main() {
	vector<int> vec = { 2,5,3,8,4,2,3,1,3 };
	cout << counter(vec, 2)<<endl;
}