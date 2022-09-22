#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<fstream>
#include<map>
using namespace std;


class Diya {
protected:
	string name;
	double duration;
public:
	Diya() {
		name = "";
		duration = 0;
	}
	string get_action() {
		return name;
	}
	double get_duration() {
		return duration;
	}
	friend istream& operator>>(istream& is, Diya& x) {
		is >> x.name >> x.duration;
		return is;
	}
	friend ostream& operator<<(ostream& os,const Diya& x) {
		os <<"name: "<< x.name<<" duration: "<< x.duration;
		return os;
	}
};
class Day {
protected:
	string date;
	vector<Diya> actions;
public:
	Day() {
		date = "";

	}
	vector<Diya> get_actions() {
		return actions;
	}
	friend istream& operator>>(istream& is, Day& x) {
		x.actions.clear();
		is >> x.date;
		Diya temp;
		int num;
		is >> num;
		for (int i = 0; i < num; i++) {
			is >> temp;
			x.actions.push_back(temp);
		}
		//istream_iterator<Diya> it(is);
		////ostream_iterator<ExperimentalTopic> out(cout, "\n");
		//copy_n(it, num, back_inserter(x.actions));
		////copy(topics.begin(), topics.end(), out);
		return is;
	}
	friend ostream& operator<<(ostream& os, const Day& x) {
		os << "date: " << x.date << endl;
		ostream_iterator<Diya> out(os, "\n");
		copy(x.actions.begin(), x.actions.end(), out);
		os << endl;
		return os;
	}
};
class Week {
protected:
	string name;
	vector<Day> days;//{ 7 };
public:
	Week() {
		name = "";
	}
	vector<Day>& get_days() {
		return days;
	}
	string get_person() {
		return name;
	}
	friend istream& operator>>(istream& is, Week& x) {
		x.days.clear();
		x.name = "";
		is >> x.name;
		Day temp;
		for (int i = 0; i < 7; i++) {
			is >> temp;
			x.days.push_back(temp);
		}
		//istream_iterator<Day> it(is);
		//copy_n(it, 7, back_inserter(x.days));
		return is;
	}
	friend ostream& operator<<(ostream& os, const Week& x) {
		os << "name: " << x.name << endl;
		ostream_iterator<Day> out(os, "\n");
		copy(x.days.begin(), x.days.end(), out);
		os << endl;
		return os;
	}
};



int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	/*Week test;
	input >> test;*/
	vector<Week> people;
	istream_iterator<Week> it(input), it_end;
	ostream_iterator<Week> out(cout, "\n");
	copy(it, it_end, back_inserter(people));
	copy(people.begin(), people.end(), out);
	input.close();

	//B
	string person="";
	Day day;
	for (auto x : people) {
		Day t;
		t = *max_element(x.get_days().begin(), x.get_days().end(), [=](Day m, Day y) {
			return m.get_actions().size() < y.get_actions().size();
			});
		if (person == "" || t.get_actions().size() > day.get_actions().size()) {
			day = t;
			person = x.get_person();
		}
	}
	output << person << " " << day << endl;

	//C
	map<string, double> walks;
	for (auto& x : people) {
		for (auto y:x.get_days()) {
			for (auto z : y.get_actions()) {
				if (z.get_action() == "walk") {
					auto t = walks.emplace(x.get_person(), z.get_duration());
					if (!t.second) {
						walks[x.get_person()] += z.get_duration();
					}
				}
			}
		}
	}
	for(auto x: walks) {
		output << x.first << " " << x.second << endl;
	}

	//input.close();
	output.close();
}