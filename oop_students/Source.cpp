#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student {
private:
    string lastname;
    string firstname;
    string group;
    int* marks;
public:
    student(string a = "", string b = "", string c = "",int f=0,int s=0,int t=0,int fo=0) :lastname(a), firstname(b), group(c), marks(new int[4]) {
        marks[0] = f;
        marks[1] = s;
        marks[2] = t;
        marks[3] = fo;
    }
   ~student() {
        delete[] marks;
        //cout << "dectructor!!!";
   }
    student(const student& a):marks(new int[4]) {
        lastname = a.lastname;
        firstname = a.firstname;
        group = a.group;
        for (int i = 0; i < 4; i++) {
            marks[i] = a.marks[i];
        }
    }
    int ratesum() {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += marks[i];
        }
        return sum;
    }
    int getmarkf() {
        return marks[0];
    }
    int getmarks() {
        return marks[1];

    }
    int getmarkt() {
        return marks[2];

    }
    int getmarkfo() {
        return marks[3];

    }
    string getgroup() {
        return group;
    }
    student& operator=(const student& other)
    {
        firstname = other.firstname;
        group = other.group;
        lastname = other.lastname;

        for (int i = 0; i < 4; i++) {
            marks[i] = other.marks[i];
       }
        return *this;
    }
    friend ostream& operator<<(ostream& is, student a) {
        is << a.lastname << "\t" << a.firstname << "\t" << a.group << " ";
        for (int i = 0; i < 4; i++) {
            is << a.marks[i] << " ";
        }
        is << endl;
        return is;
    }
    friend istream& operator>>(istream& is, student& x) {
        is >> x.lastname >> x.firstname >> x.group;
        for (int i = 0; i < 4; i++) {
            is >> x.marks[i];
        }
        return is;
    }
    friend bool operator<(student x, student y) {
        if (x.ratesum() == y.ratesum()) {
            if (x.lastname == y.lastname) {
                return x.firstname < y.firstname;
            }
            return x.lastname < y.lastname;
        }
        return x.ratesum() < y.ratesum();
    }

};
void swap(student* xp, student* yp)
{
    student temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(student* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j + 1]);
            }
 
}
void rate(student* arr, int n) {
    int k = n;
    for (int i = 0; i < n; i++) {
        if (arr[i].getmarkf()<51 || arr[i].getmarks()<51 || arr[i].getmarkt()<51 || arr[i].getmarkfo()<51) {
            k--;
        }
    }
    student* proved = new student[k];
    int in = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].getmarkf()<51 || arr[i].getmarks() < 51 || arr[i].getmarkt() < 51 || arr[i].getmarkfo() < 51) {
            continue;
        }
        proved[in++] = arr[i];
    }
    cout << "-------------" << endl;
    bubbleSort(proved, k);
    for (int i = 0; i < k; i++) {
        cout << proved[i];
    }
    delete[]proved;

}
int howmanythebest(student* arr, int n) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].getmarkf()>=90 && arr[i].getmarks()>=90 && arr[i].getmarkt()>=90 && arr[i].getmarkfo()>=90) {
            num++;
        }
    }
    return num;
}



double averagebygroup(student* arr, int n, string g) {
    int countg = 0;
    double average = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].getgroup() == g) {
            countg++;
            average += arr[i].ratesum();
        }
    }
    average /= countg;
    return average;
}

int main() {
    ifstream fin("data.txt");//читання з файлу
    int sum;
    fin >> sum;
    student klym("Klym", "Sofia", "PMI-13", 56, 90, 67, 69);
    //cout << klym;
    student* arr = new student[sum];
    for (int i = 0; i < sum; i++) {
        fin >> arr[i];
    }
    rate(arr, sum);
    cout << "average in group" << averagebygroup(arr, sum, "PMI-13") << endl;;
    cout<<"best: "<<howmanythebest(arr, sum) << endl;
    for (int i = 0; i < sum; i++) {
        cout << arr[i] << endl;
    }




    delete[]arr;
}