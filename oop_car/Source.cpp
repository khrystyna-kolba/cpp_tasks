#include <fstream>
#include <iostream> 
#include <string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Car {
protected:
	string brand;
	string type;
	string fuel;
	double volume;
public:
	string get_fuel() {
		return fuel;
	}
	string get_brand() {
		return brand;
	}
	string get_type() {
		return type;
	}
	double get_volume() {
		return volume;
	}
	virtual void input(istream& f)
	{
		f >> brand >> type>>fuel>>volume;
	}
	virtual void print(ostream& f)
	{
		f << "brand: " << brand;
		f << " type: " << type;
		f << " fuel: "<<fuel;
		f << " volume: " << volume;
	}

};
class HybridCar : public Car {
protected:
	double charging_time;
public:
	double get_charging_time() {
		return charging_time;
	}
	virtual void input(istream& f)
	{
		Car::input(f);
		f >> charging_time;
	}
	virtual void print(ostream& f)
	{
		Car::print(f);
		f << "charging time: " << charging_time<<" minutes";
	}
};




int main()
{
	ifstream f1("input.txt");
	ofstream f2("output.txt");

	char type;

	vector<Car*> cars;
	while (f1 >> type)
	{
		if (type == 'c')
		{
			cars.push_back(new Car);
		}
		else if(type=='h')
		{
			cars.push_back(new HybridCar);
		}
		cars.back()->input(f1);
	}
	map<string, double> fuel;
	for_each(cars.begin(), cars.end(), [&](Car* x) {
		auto it = fuel.emplace(x->get_fuel(), x->get_volume());
		if (!it.second) {
			fuel[x->get_fuel()] += x->get_volume();
		}
		});

	for (auto x : fuel) {
		f2 << x.first << " " << x.second << endl;
	}

	//час зарядки всіх гібридних автомобілів
	double time=0;
	for_each(cars.begin(), cars.end(), [&](Car* x) {
		auto m = dynamic_cast<HybridCar*>(x);
		if (m != nullptr) {
			time += m->get_charging_time();
		}
		});

	f2 << "total time: " << time << endl;

	f1.close();
	f2.close();
}
