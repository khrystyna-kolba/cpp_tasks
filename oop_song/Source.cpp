#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Song {
private:
	string name;
	string artist;
	double duration;
public:
	Song(string a="unknown", string b="unknown",double c=0) {
		name = a;
		artist = b;
		duration = c;
	}
	Song(const Song& x) {
		name = x.name;
		artist = x.artist;
		duration = x.duration;
	}
	string getartist() {
		return artist;
	}
	double getduration() {
		return duration;
	}
	friend ostream& operator<<(ostream& is, Song a) {
		is << a.name << "  " << a.artist << "  " << a.duration << " minutes";
		return is;
	}
	bool operator<(Song y) {
		return name < y.name;
	}
	friend istream& operator>>(istream& is, Song& x) {
		getline(is, x.name, ';');
		getline(is, x.artist, ';');
		is >> x.duration;
		is.ignore(256, '\n');
		return is;
	}
};
int main() {
	int n;
	cout << "enter the size of array: " << "\n";
	cin >> n;
	cin.ignore(256, '\n');
	Song* arr = new Song[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	string artist;
	double sumofartist = 0;
	cout << "enter artist to calculate full duration of his songs: " << endl;
	getline(cin, artist);
	for (int i = 0; i < n; i++) {
		if (arr[i].getartist() == artist) {
			sumofartist += arr[i].getduration();
		}
	}
	cout << "Duration of " << artist << " is " << sumofartist << " minutes" << endl;
	Song shortest = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i].getduration() < shortest.getduration()) {
			shortest = arr[i];
		}
	}
	cout << "the shortest song is: " << shortest << endl;
	cout << endl << "list pop: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i].getartist() == arr[j].getartist()&& i!=j) {
				cout << arr[i] << endl;
				break;
			}
		}

	}
	cout << endl;
	int countart = 0;
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int j = 0; j < n; j++) {
			if (arr[i].getartist() == arr[j].getartist() && i != j) {
				check = false;
			}
		}
		if (check) {
			countart++;
		}
	}
	string* artists = new string[countart];
	int index = 0;
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int j = 0; j < n; j++) {
			if (arr[i].getartist() == arr[j].getartist() && i != j) {
				check = false;
			}
		}
		if (check) {
			artists[index++] = arr[i].getartist();
		}
	}
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int j = 0; j <countart ; j++) {
			if (arr[i].getartist() == artists[j]) {
				check = false;
			}
		}
		if (check) {
			cout << arr[i] << endl;
		}
	}
	cout << endl;


	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}


	delete[]arr;
	delete[]artists;
}