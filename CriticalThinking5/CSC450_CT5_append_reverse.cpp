#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

inline bool exists_file (const string& name);

string read_file(const string& filePath, const string& fileName);

void append_string(const string& filePath, const string& fileName);

void reverse_string_to_file(string stringToReverse, const string& filePath, const string& reverseFileName);

int main() {
    string filePath = "../"; // This relative path works with my IDE. Modify it if necessary.
    string fileName = "CSC450_CT5_mod5.txt";
    string reverseFileName = "CSC450-mod5-reverse.txt";
    append_string(filePath, fileName);
    cout << "Data appended successfully" << endl;
    string fileContents = read_file(filePath, fileName);
    reverse_string_to_file(fileContents, filePath, reverseFileName);
    cout << fileContents << endl;
    return 0;
}

inline bool exists_file (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

string read_file(const string& filePath, const string& fileName){
    ifstream t(filePath + fileName);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void append_string(const string& filePath, const string& fileName) {
    bool done = false;
    string userString;
    ofstream fileStream;
    if (!exists_file(filePath + fileName)){
        fprintf(stdout, "Could not open file for editing: %s%s.", filePath.c_str(), fileName.c_str());
        throw std::ios_base::failure("Could not open file for editing: " + filePath + fileName);
    }
    fileStream.open(filePath + fileName, ios::out | ios::app);
    cout << "Enter the data to append. Enter q to finish entering data: " << endl;
    while (!done) {
        getline(cin, userString);
        if(userString == "q"){
            done = true;
        } else {
            fileStream << endl << userString;
        }
    }
    fileStream.close();
}

void reverse_string_to_file(string stringToReverse, const string& filePath, const string& reverseFileName) {
    ofstream fileStream;
    reverse(stringToReverse.begin(), stringToReverse.end());
    fileStream.open(filePath + reverseFileName);
    fileStream << stringToReverse;
    fileStream.close();
}
