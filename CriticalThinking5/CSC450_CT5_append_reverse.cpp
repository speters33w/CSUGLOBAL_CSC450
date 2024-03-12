/*
 * A simple C++ program that obtains input from a user
 * and appends the user input into a file
 * Then reads the contents of the file,
 * reverses the contents,
 * then stores them in another file.
 * (CSC450_CT5_append_reverse.cpp)
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

inline bool exists_file(const string &filePath);

string read_file(const string &filePath);

void append_string(const string &filePath);

void reverse_string_to_file(string stringToReverse, const string &filePath);

/*
 * This is the main runner engine for the program.
 */
int main() {
    string directoryPath = "../"; // Change the directory path here if necessary. I use "../" for my IDE.
    string fileName = "CSC450_CT5_mod5.txt";
    string reverseFileName = "CSC450-mod5-reverse.txt";
    append_string(directoryPath + fileName);
    fprintf(stdout,"Data appended to %s successfully. \n", fileName.c_str());
    string fileContents = read_file(directoryPath + fileName);
//    cout << fileContents << endl;
    reverse_string_to_file(fileContents, directoryPath + reverseFileName);
    fprintf(stdout,
            "Contents of %s successfully reversed and stored in %s. \n",
            fileName.c_str(),
            reverseFileName.c_str());
//    string reverseFileContents = read_file(filePath, reverseFileName);
//    cout << reverseFileContents << endl;
    return 0;
}


/*
 * Checks to see if a file exists.
 */
inline bool exists_file(const string &filePath) {
    ifstream fileExistStream(filePath.c_str());
    bool good = fileExistStream.good();
    fileExistStream.close();
    return good;
}

/*
 * Reads contents of a text file and returns the entire contents as a string.
 */
string read_file(const string &filePath) {
    ifstream t(filePath);
    stringstream buffer;
    buffer << t.rdbuf();
    t.close();
    string returnString = buffer.str();
    buffer.clear();
    return returnString;
}

/*
 * Appends user input from the console to a file.
 * Allows multiple lines.
 * The user indicates the input is complete by typing q.
 */
void append_string(const string &filePath) {
    bool done = false;
    string userString;
    ofstream fileStream;
    if (!exists_file(filePath)) {
        fprintf(stdout, "Could not open file for editing: %s.", filePath.c_str());
        throw std::ios_base::failure("Could not open file for editing: " + filePath);
    }
    fileStream.open(filePath, ios::out | ios::app);
    cout << "Enter the data to append. Enter q to finish entry: " << endl;
    while (!done) {
        getline(cin, userString);
        if (userString == "q") {
            done = true;
        } else {
            fileStream << endl << userString;
        }
    }
    fileStream.close();
}

/*
 * Reverses a string and saves it to a file.
 * The string may include line breaks.
 */
void reverse_string_to_file(string stringToReverse, const string &filePath) {
    ofstream fileStream;
    reverse(stringToReverse.begin(), stringToReverse.end());
    fileStream.open(filePath);
    fileStream << stringToReverse;
    fileStream.close();
}
