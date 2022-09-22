#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

template<typename T>
vector<T> func(vector<T> vec, size_t n) {
    int num = 0; //num of numbers whose right neighbor is num^x
    vector<T> vec_copy=vec; //because unique is going to change the vec
    unique(vec.begin(), vec.end(), [&](T& x, T y) {
        int temp = pow(x, n);
        if (y == temp) {
            num++;
            x = y;
        }
        return y == temp;
        });
    if (num > 2) {
        return vec_copy;
    }
    else {
        transform(vec_copy.begin(), vec_copy.end(),vec_copy.begin(), [=](T x) {
            return pow(x, n);
            });
        return vec_copy;
    }
}


int main() {
	vector<double> vec = {2.0,4,16,256,2};//>2
    size_t n = 2;
    vec = func(vec, n);
    ostream_iterator<double> out(cout, " ");
    copy(vec.begin(), vec.end(), out);

    cout << endl;

    vec = { 1,3.3,16,256.1,2 };//<2
    vec = func(vec, n);
    copy(vec.begin(), vec.end(), out);
}