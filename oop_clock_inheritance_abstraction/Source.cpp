#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Clock {
protected:
	string model;
	string brand;
public:
	Clock(string model="", string brand="") :
	model(model),brand(brand){

	}
	virtual void input(istream& is) {
		is >> model >> brand;
	}
	virtual void print(ostream& os) {
		os << "model: " << model << endl;
		os << "brand: " << brand << endl;
	}
	virtual string get_brand() = 0;
	virtual string get_model() = 0;
};
class MechanicalClock: public Clock {
private:
	double duration;
	double garanty;
public:
	MechanicalClock(string model="", string brand="", double duration=0, double garanty=0) :
		Clock(model, brand), duration(duration), garanty(garanty) {
	}
	void input(istream& is) {
		Clock::input(is);
		is >> duration >> garanty;
	}
	void print(ostream& os) {
		Clock::print(os);
		os << "duration of work: " << duration << endl;
		os << "garanty: " << garanty << endl;
	}
	string get_brand() {
		return brand;
 }
	string get_model() {
		return model;
 }
	double get_garanty() {
		return garanty;
	}
};
class ElectronicClock: public Clock {
private:
	string battery;
	string screen;
public:
	ElectronicClock(string model="", string brand="", string battery="", string screen="") :
		Clock(model, brand), battery(battery),screen(screen){
	}
	void input(istream& is) {
		Clock::input(is);
		is >> battery >> screen;
	}
	void print(ostream& os) {
		Clock::print(os);
		os << "battery: " << battery << endl;
		os << "screen: " << screen << endl;
	}
	string get_brand() {
		return brand;
	}
	string get_model() {
		return model;
	}
};


// A function to implement bubble sort
void bubbleSort(Clock** arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j]->get_brand() > arr[j + 1]->get_brand())
				swap(arr[j], arr[j + 1]);
}

//void print_given_brand(Clock** arr, int n, string brand) {
//	cout << "clock with " << brand << " brand" << endl;
//	for (int i = 0; i < n; i++) {
//		if (arr[i]->get_brand() == brand) {
//			arr[i]->print(cout);
//			cout << endl;
//		}
//	}
//}
int print_given_brand(Clock** arr, int n, string brand) {
	int count=0;
	cout << "clock with " << brand << " brand" << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i]->get_brand() == brand) {
			//arr[i]->print(cout);
			//cout << endl;
			count++;
		}
	}
	return count;
}

MechanicalClock* longest_garanty_m(Clock** arr, int n) {
	cout << "longest garanty: " << endl;
	double garanty = 0;
	//int count = 0;
	MechanicalClock* to_return = nullptr;
	for (int i = 0; i < n; i++) {
		MechanicalClock* v = dynamic_cast<MechanicalClock*>(arr[i]);
		if (v != nullptr) {
			//count++;
			//if (count == 1) min = v->get_norm();
			if (v->get_garanty() > garanty)
			{
				to_return = v;
				garanty = v->get_garanty();
			}
		}
	}
		return to_return;
}

int main() {
	ifstream filem("Text1.txt");
	ifstream filee("Text2.txt");
	if (filem.is_open()&&filee.is_open())
	{
		cout << "Success" << endl;
		int nm;
		int ne;
		int temp_index;
		filem >> nm;
		filee >> ne;

		Clock** arr = new Clock * [nm+ne];
		MechanicalClock* arrm = new MechanicalClock[nm];
		ElectronicClock* arre = new ElectronicClock [ne];

		for (int i = 0; i < nm; i++)
		{
			arr[i] = new MechanicalClock;
			arrm[i].input(filem);
			arr[i] = &arrm[i];
		}
		for (int i = 0; i < ne; i++)
		{
			arr[i+nm] = new ElectronicClock;
			arre[i].input(filee);
			arr[i+nm] = &arre[i];
		}
	
		/*for (int i = 0; i < nm; i++)
		{
			arr[i] = new MechanicalClock;
			arr[i]->input(filem);
		}
		for (int i = nm; i < ne+nm; i++)
		{
			arr[i] = new ElectronicClock;
			arr[i]->input(filee);
		}*/


		ofstream file("fromtwo.txt");
		file << nm + ne << endl;
		for (int i = 0; i < nm; i++) {
			arrm[i].print(file);
			file << endl;
		}
		for (int i = 0; i < ne; i++) {
			arre[i].print(file);
			file << endl;
		}
		file.close();
		cout << "your clocks: " << endl;
		for (int i = 0; i < nm+ne; i++)
		{
			arr[i]->print(cout);
			cout << endl;
		}
		cout << endl;
		filem.close();
		filee.close();
		bubbleSort(arr, nm + ne);
		cout << "your sorted clocks: " << endl;
		for (int i = 0; i < nm + ne; i++)
		{
			arr[i]->print(cout);
			cout << endl;
		}
		ofstream filetwo("newtext.txt"); //кусочок для запису результату у файл
		filetwo << nm + ne << endl;
		for (int i = 0; i < nm + ne; i++) {
			arr[i]->print(filetwo);
			filetwo << endl;
		}
		filetwo.close();
		
		longest_garanty_m(arr, nm + ne)->print(cout);
		cout << endl;
		cout << "enter brand to find all clocks: " << endl;
		string brand;
		cin >> brand;
		//print_given_brand(arr, nm + ne, brand);
		cout<<print_given_brand(arr, nm + ne, brand) << endl;
	}
	else
	{
		cout << "Something went wrong." << endl;
	}
}