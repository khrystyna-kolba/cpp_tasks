#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size "; cin >> n;

    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];
    cout << "Enter a: "<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << "Enter b: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i])
        {
            c[i] = a[i] * a[i];
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                c[i] = a[i] + b[i];
     
            }
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "c" << i << " : " << c[i] << endl;
    }

    delete[]a;
    delete[]b;
    delete[]c;
}