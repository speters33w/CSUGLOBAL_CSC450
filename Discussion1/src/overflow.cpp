/*
 * Modified from the Buffer Overflow example at Top 5 C++ Security Risks
 *   on the snyk blog https://snyk.io/blog/top-5-c-security-risks/
 */

#include <iostream>

using namespace std;

int main()

{

  volatile int important_data = 0;

  char user_input[10];

  cout << "Enter a string. Over 10 characters will result in an overflow." << endl;

  gets(user_input);


  if(important_data != 0) {

    cout << "Warning !!!, the 'important_data' was changed" << endl;
    cout << "The value of important_data is " << important_data << endl;

  } else {

    cout << "the 'important_data' was not changed" << endl;
    cout << "The value of important_data is " << important_data << endl;

  }

}
