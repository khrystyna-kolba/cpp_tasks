#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<fstream>
#include<map>
#include<set>
using namespace std;

class Feed {
	string time;
	string product;
public:
	string get_product() {
		return product;
	}
	friend istream& operator>>(istream& is, Feed& x) {
		is >> x.time >> x.product;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Feed& x) {
		os << "time: " << x.time << " product: " << x.product;
		return os;
	}
	bool operator<(const Feed& x) {
		if (stoi(time.substr(0, 2)) == stoi(x.time.substr(0, 2))) {
			return time.substr(3, 2) < x.time.substr(3, 2);
		}
		return stoi(time.substr(0, 2)) < stoi(x.time.substr(0, 2));
	}
};

class Animal {
	string name;
	vector<Feed> food;
public:
	vector<Feed>& get_food() {
		return food;
	}
	string get_name() {
		return name;
	}
	friend istream& operator>>(istream& is, Animal& x) {
		x.food.clear();
		is >> x.name;
		Feed temp;
		int num;
		is >> num;
		for (int i = 0; i < num; i++) {
			is >> temp;
			x.food.push_back(temp);
		}
		//istream_iterator<Diya> it(is);
		////ostream_iterator<ExperimentalTopic> out(cout, "\n");
		//copy_n(it, num, back_inserter(x.actions));
		////copy(topics.begin(), topics.end(), out);
		return is;
	}
	friend ostream& operator<<(ostream& os, const Animal& x) {
		os << "name: " << x.name << endl;
		for (const auto& y : x.food) {
			os << y << endl;
		}
		/*ostream_iterator<Diya> out(os, "\n");
		copy(x.actions.begin(), x.actions.end(), out);*/
		os << endl;
		return os;
	}
};



int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	vector<Animal> animals;
	istream_iterator<Animal> it(input), it_end;
	ostream_iterator<Animal> out(output, "\n");
	copy(it, it_end, back_inserter(animals));
	copy(animals.begin(), animals.end(), out);

	sort(animals.begin(), animals.end(), [](Animal x, Animal y) {
		return x.get_name() < y.get_name();
		});
	for (auto& x : animals) {
		auto& y = x.get_food();
		sort(y.begin(), y.end());
	}
	copy(animals.begin(), animals.end(), ostream_iterator<Animal>(cout, "\n"));


	set<string> products;
	for (auto& x : animals) {
		auto y = x.get_food();
		for (auto food : y) {
			products.insert(food.get_product());
		}
	}
	output << "products: " << endl;
	for (auto& x : products) {
		output << x << endl;
	}

	input.close();
	output.close();
}