#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool StrongPassword(const string& password) {
    bool Lowercase = false;
    bool Uppercase = false;
    bool Numbers = false;
    bool Specialchar = false;

    for (char c : password) {
        if (islower(c)) {
            Lowercase = true;
        }
        else if (isupper(c)) {
            Uppercase = true;
        }
        else if (isdigit(c)) {
            Numbers = true;
        }
        else {
            Specialchar = true;
        }
    }

    return password.length() >= 8 && Lowercase && Uppercase && Numbers && Specialchar;
}

bool LessStrongPassword(const string& password) {
    bool Lowercase = false;
    bool Uppercase = false;
    bool Numbers = false;

    for (char c : password) {
        if (islower(c)) {
            Lowercase = true;
        }
        else if (isupper(c)) {
            Uppercase = true;
        }
        else if (isdigit(c)) {
            Numbers = true;
        }
    }

    return password.length() >= 6 && Lowercase && Uppercase && Numbers;
}

bool WeakPassword(const string& password) {
    bool Lowercase = false;
    bool Uppercase = false;

    for (char c : password) {
        if (islower(c)) {
            Lowercase = true;
        }
        else if (isupper(c)) {
            Uppercase = true;
        }
    }

    return password.length() >= 4 && Lowercase && Uppercase;
}

int main() {
    string password;
    char choice;

    do {
        cout << "Enter your password: ";
        cin >> password;

        if (StrongPassword(password)) {
            cout << "Congratulations! Your password is very strong." << endl;
        }
        else if (LessStrongPassword(password)) {
            cout << "Your password is less strong." << endl;
        }
        else if (WeakPassword(password)) {
            cout << "Your password is weak." << endl;
        }
        else {
            cout << "Your password does not meet the minimum requirements for a strong password." << endl;
        }

        cout << "Do you want to check another password? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    cout << "Goodbye!" << endl;

    return 0;
}
