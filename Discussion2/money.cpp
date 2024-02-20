#include <iomanip>
#include <iostream>

void output(char input[10], volatile float balance);

using namespace std;

int main()

{
    volatile float bank_account_balance = 100000.00;
    char user_input[10];

    cout << "Over 10 characters will result in an overflow." << endl;
    cout << "Your bank account balance  is $" << bank_account_balance << endl;

    gets(user_input);

    //cin.getline(user_input, 10);

    if(bank_account_balance < 100000.00) {
        cout << "Warning !!!, Your balance is getting low." << endl;
    } else if(bank_account_balance > 100000.00) {
        cout << "You're in the money!!!" << endl;
    } else {
        cout << "Your balance has not changed" << endl;
    }
    output(user_input, bank_account_balance);

}

void output(const char input[10], volatile float balance) {
    cout << "You entered \"" << input << "\"" << endl;
    cout << fixed << setprecision(2);
    cout << "Your bank account balance is now $" << balance << endl;
}

