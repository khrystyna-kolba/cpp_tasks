#include <fstream>
#include <iostream> 
#include <string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


class FlyingMachine abstract
{
protected:
	string type;
	double maxHeight;
public:
	FlyingMachine()
	{
		this->type = "Plane";
		this->maxHeight = 10;
	}
	FlyingMachine(string type, double maxHeight)
	{
		this->type = type;
		this->maxHeight = maxHeight;
	}
	friend ifstream& operator>>(ifstream& in, FlyingMachine& flm)
	{
		flm.input(in);
		return in;
	}
	friend ofstream& operator<<(ofstream& out, FlyingMachine& flm)
	{
		flm.print(out);
		return out;
	}
	virtual void input(ifstream& f)
	{
		f >> type >> maxHeight;
	}
	virtual void print(ofstream& f)
	{
		f << type << " " << maxHeight << " ";
	}

	void set_type(string type)
	{
		this->type = type;
	}
	string get_type()
	{
		return type;
	}
	void set_maxHeight(double maxHeight)
	{
		this->maxHeight = maxHeight;
	}
	double get_maxHeight()
	{
		return maxHeight;
	}

	virtual int getSpeed() = 0;
};

class Plane : public FlyingMachine
{
protected:
	int speed;
public:

	virtual void input(ifstream& f)
	{
		FlyingMachine::input(f);
		f >> speed;
	}
	virtual void print(ofstream& f)
	{
		FlyingMachine::print(f);
		f << speed << endl;
	}

	int getSpeed()
	{
		return speed;
	}
};


class Baloon : public FlyingMachine
{
protected:
	double maxFlyingTime;
public:

	virtual void input(ifstream& f)
	{
		FlyingMachine::input(f);
		f >> maxFlyingTime;
	}
	virtual void print(ofstream& f)
	{
		FlyingMachine::print(f);
		f << maxFlyingTime << endl;
	}

	virtual int getSpeed()
	{
		return 0;
	}

};

int main()
{
	ifstream f1("input.txt");
	ofstream f2("output.txt");

	int type;

	vector<FlyingMachine*> machines;
	while (f1 >> type)
	{
		if (type == 1)
		{
			machines.push_back(new Plane);
		}
		else
		{
			machines.push_back(new Baloon);
		}
		machines.back()->input(f1);
	}
	for_each(machines.begin(), machines.end(), [&](FlyingMachine* x) {
			x->print(f2);
		});
	int setHeight;
	cout << "Enter height: ";
	cin >> setHeight;


	f2 << "Flying machines that fly " << setHeight << " km high: " << endl;
	for_each(machines.begin(), machines.end(), [&](FlyingMachine* x) {
		if (x->get_maxHeight() >= setHeight) {
			x->print(f2);
		}
      });

	f2 << endl;
	f2 << "Flying time from Kyiv to Lviv (for planes): " << endl;
	for_each(machines.begin(), machines.end(), [&](FlyingMachine* x) {
		if (dynamic_cast<Plane*>(x)!=nullptr) {
			x->print(f2);
			f2 << 600.0 / (double)x->getSpeed() << endl;
		}
		});






	/*map<FlyingMachine, int> count;
	for (auto& x : machines) {
		auto it= count.emplace(x, 1);
	}*/


	f1.close();
	f2.close();
}