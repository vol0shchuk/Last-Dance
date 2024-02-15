// Last Dance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

class FileHandler {
public:
    virtual void Display(const char* path) const = 0;
    virtual ~FileHandler() {}
};

class FileContentPrinter : public FileHandler {
public:
    void Display(const char* path) const override {
        ifstream file(path);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                cout << ch;
            }
            file.close();
        }
        else {
            cerr << "Unable to open file: " << path << endl;
        }
    }
};

class FileAsciiPrinter : public FileHandler {
public:
    void Display(const char* path) const override {
        ifstream file(path);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                cout << static_cast<int>(ch) << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cerr << "Unable to open file: " << path << endl;
        }
    }
};

class FileBinaryPrinter : public FileHandler {
public:
    void Display(const char* path) const override {
        ifstream file(path, ios::binary);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                for (int i = 7; i >= 0; --i) {
                    cout << ((ch >> i) & 1);
                }
                cout << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cerr << "Unable to open file: " << path << endl;
        }
    }
};

int main() {
    const char* filePath = "example.txt";

    FileContentPrinter contentPrinter;
    cout << "File content: " << endl;
    contentPrinter.Display(filePath);

    FileAsciiPrinter asciiPrinter;
    cout << "File content in ASCII: " << endl;
    asciiPrinter.Display(filePath);

    FileBinaryPrinter binaryPrinter;
    cout << "File content in binary: " << endl;
    binaryPrinter.Display(filePath);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
