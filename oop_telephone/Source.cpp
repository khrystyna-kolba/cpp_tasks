#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
#include<queue>
#include<string>
#include<deque>
#include<list>
#include<stack>
#include<map>
using namespace std;

class Phone {
protected:
	string name;
	string brand;
	double price;
public:
	void set_name(string name_) {
		name = name_;
	}
	void set_brand(string x_) {
		brand = x_;
	}
	void set_price(double x_) {
		price = x_;
	}
	string get_brand() {
		return brand;
	}
	string get_name() {
		return name;
	}
	double get_price() {
		return price;
	}
	virtual void input(istream& is)
	{
		is >> name >> brand>> price;
	}
	virtual void print(ostream& os)
	{
		os << "name: " << name << " brand: " << brand << " price: " << price<<" dollars";
	}
};

class MobilePhone : public Phone {
protected:
	string color;
	double storage;
public:
	void set_color(string x_) {
		color = x_;
	}
	void set_storage(double x_) {
		storage = x_;
	}
	virtual void input(istream& is)
	{
		Phone::input(is);
		is >> color >> storage;
	}
	virtual void print(ostream& os)
	{
		Phone::print(os);
		os << " color: " << color << " storage: " << storage<<" gb";
	}
};
class RadioPhone : public Phone {
protected:
	double action_radius;
	bool is_auto_resp;
public:
	void set_color(bool x_) {
		is_auto_resp = x_;
	}
	void set_action_radius(double x_) {
		action_radius = x_;
	}
	double get_action_radius() {
		return action_radius;
	}
	bool is_auto_respondent() {
		return is_auto_resp;
	}
	virtual void input(istream& is)
	{
		Phone::input(is);
		is >> action_radius >> is_auto_resp;
	}
	virtual void print(ostream& os)
	{
		Phone::print(os);
		os << " action radius: " << action_radius << " meters   auto respondent: ";
		if (is_auto_resp) {
			os << "yes";
		}
		else {
			os << "no";
		}

	}

};

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	char type;
	vector<Phone*> phones;
	while (input >> type)
	{
		if (type == 'm')
		{
			phones.push_back(new MobilePhone);
		}
		else if (type=='r')
		{
			phones.push_back(new RadioPhone);
		}
		else {
			phones.push_back(new Phone);
		}
		phones.back()->input(input);
	}
	sort(phones.begin(), phones.end(), [=](Phone* x, Phone* y) {
		return x->get_price() < y->get_price();
		});

	double total_price = 0;
	output << "All phones sorted by price(from the low)" << endl;
	for_each(phones.begin(), phones.end(), [&](Phone* x) {
		x->print(output);
		output << endl;
		total_price += x->get_price();
		});
	output << endl;
	output << "Total price: " << total_price << " dollars" << endl;
	map<string, int> counter;
	for_each(phones.begin(), phones.end(), [&](Phone* x) {
		if (dynamic_cast<MobilePhone*>(x)!=nullptr) {
			auto it = counter.emplace("Mobile Phone", 1);
			if(!it.second) {
				counter["Mobile Phone"]+=1;
			}
		}
		else if (dynamic_cast<RadioPhone*>(x) != nullptr) {
			auto it = counter.emplace("Radio Phone", 1);
			if (!it.second) {
				counter["Radio Phone"] += 1;
			}
		}
		else {
			auto it = counter.emplace("Phone", 1);
			if (!it.second) {
				counter["Phone"] += 1;
			}
		}
		});

	output << endl;
	output << "Total count of all phones: " << phones.size() << endl;
	for (auto x : counter) {
		output <<"count: "<< x.first << " " << x.second << endl;
	}
	//output for radio phones with auto respondent
	output << endl;
	output << "Radio Phones with auto respondent" << endl;
	for_each(phones.begin(), phones.end(), [&](Phone* x) {
		auto m = dynamic_cast<RadioPhone*>(x);
		if (m != nullptr) {
			if (m->is_auto_respondent()) {
				m->print(output);
				output << endl;
			}
		}
		});

	output.close();
	input.close();
}