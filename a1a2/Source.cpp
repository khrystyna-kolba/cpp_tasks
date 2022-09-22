#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
template<typename T>
vector<T> func(T a1, T a2, int N) {
	vector<T> res(N, a2);
	res[0] = a1;
	partial_sum(res.begin(), res.end(), res.begin());
	return res;
}

int main() {
	vector<int> vec = func(3, 2, 5);
	ostream_iterator<int> out(cout, " ");
	copy(vec.begin(), vec.end(), out);
}