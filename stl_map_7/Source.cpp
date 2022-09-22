#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
class Student {
private:
	string first_name;
	size_t course;
	string group;
public:
	Student(string f="", size_t c=0, string g="") :
	first_name(f), course(c), group(g){}
	Student(const Student& x) {
		first_name = x.first_name;
		course = x.course;
		group = x.group;
	}
	friend ostream& operator<<(ostream& os, const Student& x) {
		os << x.first_name << " " << x.course << " " << x.group << endl;
		return os;
	}
	string get_first_name() {
		return first_name;
	}
	string get_group() {
		return group;
	}
	bool operator<(const Student& x)const {
		return first_name < x.first_name;
	}
	friend istream& operator>>(istream& is, Student& x) {
		is >> x.first_name;
		is >> x.course;
		is >> x.group;
		return is;
	}
};

bool compare_pair(pair<string, Student> x1, pair<string, Student> x2) {
	return x1.second.get_first_name() < x2.second.get_first_name();
}
void print_by_group(map<string, Student> s, string g) {
	vector<pair<string, Student>> sor;
	for (auto x : s) {
		if (x.second.get_group() == g) {
			sor.push_back(x);
		}
	}
	sort(sor.begin(), sor.end(), compare_pair);
	for (auto x : sor) {
		cout << x.first << " " << x.second;
	}
	
}
void print_by_first_name(map<string, Student> s, string f) {
	for (auto& x : s) {
		if (x.second.get_first_name() == f) {
			cout << x.first << " " << x.second;
		}
	}
}
int main() {
	map<string, Student> students;
	ifstream fin("students.txt");//читання з файлу
	if (fin.is_open()) {
		string student_id;
		Student stud;
		while (!fin.eof()) {
			fin >> student_id;
			fin >> stud;
			students.insert(pair<string, Student>(student_id, stud));
		}
		fin.close();
		for (auto x : students) {
			cout << x.first << " " << x.second;
		}

		//пошук за прізвищем
		string first_name;
		cout << "enter first name to find info: " << endl;
		cin >> first_name;
		print_by_first_name(students,first_name);
		//виведення за групою в алфавітному порядку
		string group;
		cout << "enter group to find and sort info: " << endl;
		cin >> group;
		print_by_group(students, group);
		//вставка нових елементів
		cout << "enter student id and student(first name, course, group): " << endl;
		cin >> group;
		Student new_stud;
		cin >> new_stud;
		students.insert(pair<string, Student>(group, new_stud));
		//видалення за ключем(номер студентського)
		cout << "enter student id to delete: " << endl;
		cin >> group;
		students.erase(group);

		cout << "what we got: " << endl;
		for (auto x : students) {
			cout << x.first << " " << x.second;
		}

	}
	



}