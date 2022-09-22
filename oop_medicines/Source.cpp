#include<iostream>
#include<fstream>
#include<string>
using namespace std;
enum Form {
	PILLS,
	CAPSULES,
	SYRUP,
	INJECTIONS,
    UNKNOWN
};
istream& operator>> (istream& in, Form& form)
{
    string formx;
    in >> formx;
    if (formx == "pills")
        form = PILLS;
    else if (formx == "capsules")
        form = CAPSULES;
    else if (formx == "syrup")
        form = SYRUP;
    else if (formx == "injections")
        form = INJECTIONS;
    else if (formx == "unknown")
        form = UNKNOWN;
    return in;
 }
void printForm(Form form)
{
    if (form == PILLS)
        cout << "Pills";
    else if (form == CAPSULES)
        cout << "Capsules";
    else if (form == SYRUP)
        cout << "Syrup";
    else if (form == INJECTIONS)
        cout << "Injections";
    else if (form == UNKNOWN)
        cout << "Unknown";
}
string tolower(string x) {
    string y = x;
    for (int i = 0; i < x.length(); i++) {
        y[i] = tolower(x[i]);
    }
    return y;
}
class med {
private:
    string name;
    Form form;
    double price;
public:
    med(string a = "unknown", Form b = UNKNOWN, double c = 0) {
        name = a;
        form = b;
        price = c;
    }
    med(const med& x) {
        name = x.name;
        form = x.form;
        price = x.price;
    }
    double getprice() {
        return price;
    }
    Form getform() {
        return form;
    }
    string getName() {
        return name;
    }
    friend ostream& operator<<(ostream& is, med a) {
        is << a.name << "\t";
        printForm(a.form);
        is<< " " << a.price << endl;
        return is;
    }
    friend istream& operator>>(istream& is, med& x) {
        is >> x.name;
        is >> x.form;
        is >> x.price;
        is.ignore(256, '\n');
        return is;
    }
    friend bool operator<(med x, med y) {
        return x.name < y.name;
    }
};
void bubbleSort(med* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j+1] < arr[j])
                swap(arr[j], arr[j + 1]);
}

int main() {
    med arr[7];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    arr[4] = med();
    arr[5] = med(arr[2]);
    arr[6] = med("Nurophen", PILLS, 54);
    bubbleSort(arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i];
    }
    cout << endl;
    Form forms[5] = { CAPSULES,PILLS,INJECTIONS,SYRUP,UNKNOWN };
    int formcount[5] = { 0,0,0,0,0 };
    double pricecount[5] = { 0,0,0,0,0 };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (forms[i] == arr[j].getform()) {
                formcount[i]++;
                pricecount[i] += arr[j].getprice();
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printForm(forms[i]);
        cout << " " << "counts: " << formcount[i] << " totalprice: " << pricecount[i] << endl;
    }
    for (int i = 0; i < 7; i++) {
        if (tolower(arr[i].getName()).find("stop")!= string::npos) {
            cout << arr[i];
        }
    }
}