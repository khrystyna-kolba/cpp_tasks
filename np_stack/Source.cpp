#include<iostream>
#include<fstream>
#include<string>
using namespace std;


template <typename T>
class StackOnLinkedList {
private:
    class Node {
    public:
        T data_;
        Node* prev_;
        Node(T new_data, Node* new_prev = nullptr) {
            data_ = new_data;
            prev_ = new_prev;
        }
        ~Node() {
            delete prev_;
        }
    };
    unsigned int size_;
    Node* top_;

public:
    StackOnLinkedList() {
        top_ = nullptr;
        size_ = 0;
    }
    ~StackOnLinkedList() {
        delete top_;
    }
    void push(T new_element) {
        Node* new_node = new Node(new_element, top_);
        top_ = new_node;
        size_++;
    }
    T pop() {
        if (this->is_empty()) {
            cout << "impossible to pop, stack is empty!" << endl;
            return NULL;
        }
        if (size_ == 1) {
            T to_ret = top_->data_;
            size_--;
            return to_ret;
        }
        T to_ret = top_->data_;
        Node* new_top = top_->prev_;
        top_->prev_ = nullptr;
        delete top_;
        top_ = new_top;
        size_--;
        return to_ret;
    }
    bool is_empty() {
        return size_ == 0;
    }
    unsigned int getSize() {
        return size_;
    }


};

//стек на базі однозв'язного списку
//1. обертання слів у тексті
//2. переписування елементів цілочисельного масиву у зворотньому порядку
int main() {
    //1.
    ifstream fin("Text.txt");
    ofstream file("newtext.txt");
    if (fin.is_open()){
        string temp_word;
        StackOnLinkedList<char> reversed;
        cout << "Succes" << endl;
        while (fin >> temp_word) {
            for (auto x : temp_word) {
                reversed.push(x);
            }
            char temp;
            char delim = '0';
            while (!reversed.is_empty()) {
                temp = reversed.pop();
                if (temp == ',' || temp == '.' || temp == '?' || temp == '!' || temp == ':' || temp == ';') {
                    delim = temp;
                    continue;
                }
                file << temp;
            }
            if (delim != '0'){
                file<<delim<<" ";
            }
            else {
                file << " ";
            }
        }

    }
    else
    {
        cout << "Something went wrong." << endl;
    }

    //2
    int n;
    cout << "enter number of ints" << endl;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    StackOnLinkedList<int> integers;
    for (int i = 0; i < n; i++) {
        integers.push(arr[i]);
    }
    file << endl << "second task: " << endl;
    while (!integers.is_empty()) {
        file << integers.pop()<<" ";
    }


    fin.close();
    file.close();
    delete[] arr;
}