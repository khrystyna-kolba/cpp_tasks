#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ad {
private:
	string text;
	double price;
	int numofrepeats;
public:
	ad(string a="",double b=0,int c=0) {
		text = a;
		price = b;
		numofrepeats = c;
	}
	ad(const ad& x) {
		text = x.text;
		price = x.price;
		numofrepeats = x.numofrepeats;
	}
	string gettext() {
		return text;
	}
	int getnumofrepeats() {
		return numofrepeats;
	}
	double getprice() {
		return price;
	}
	friend ostream& operator<<(ostream& is, ad a) {
		is << a.text << "\t" << a.price << " " << a.numofrepeats << endl;
		return is;
	}
	friend istream& operator>>(istream& is, ad& x) {
		getline(is, x.text,';');
		is >> x.price;
		is >> x.numofrepeats;
		is.ignore(256, '\n');
		return is;
	}
	friend bool operator<(ad x, ad y) {
		return x.price < y.price;
	}
	double fullprice() {
		return numofrepeats * price;
	}
};
void bubbleSort(ad* arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j+1] < arr[j])
				swap(arr[j], arr[j + 1]);
}
int main() {
	ad arr[6];
	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];
	arr[3] = ad("the best chips", 34.5, 3);
	arr[4] = ad();
	arr[5] = ad(arr[3]);
	for (int i = 0; i < 6; i++) {
		cout << arr[i];
	}
	cout << endl;
	bubbleSort(arr, 6);
	for (int i = 0; i < 6; i++) {
		cout << arr[i];
	}
	ad max=arr[0];
	for (int i = 0; i < 6; i++) {
		if (arr[i].fullprice() > max.fullprice()) {
			max = arr[i];
		}
	}
	for (int i = 0; i < max.getnumofrepeats(); i++) {
		cout << max.gettext() << " ";
	}
	cout << endl;
	ad shortt=arr[0];
	ad longt;
	for (int i = 0; i < 6; i++) {
		if (arr[i].gettext().length() < shortt.gettext().length()) {
			shortt = arr[i];
		}
		if (arr[i].gettext().length() > longt.gettext().length()) {
			longt = arr[i];
		}
	}
	cout << longt;
	cout << shortt;
}