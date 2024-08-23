#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>

using namespace std;

class Login {
private:
    string loginID, password;

public:
    Login() : loginID(""), password("") {}

    void setID(const string& id) {
        loginID = id;
    }

    void setPW(const string& pw) {
        password = pw;
    }

    string getID() const {
        return loginID;
    }

    string getPW() const {
        return password;
    }
};

void registerUser(Login& log) {
    system("cls");
    string id, pw;

    cout << "\tEnter Login ID: ";
    cin >> id;
    log.setID(id);

    while (true) {
        cout << "\tEnter A Strong Password: ";
        cin >> pw;

        if (pw.length() >= 8) {
            log.setPW(pw);
            break;
        } else {
            cout << "\tEnter Minimum 8 Characters!" << endl;
        }
    }

    ofstream outfile("D:/Login.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    outfile << "\t" << log.getID() << " : " << log.getPW() << endl << endl;
    cout << "\tUser Registered Successfully!" << endl;

    outfile.close();
    Sleep(3000);
}

void loginUser() {
    system("cls");
    string id, pw;

    cout << "\tEnter Login ID: ";
    cin >> id;

    cout << "\tEnter Password: ";
    cin >> pw;

    ifstream infile("D:/Login.txt");
    if (!infile) {
        cout << "\tError: File Can't Open!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        stringstream ss(line);
        string userID, userPW;
        char delimiter;

        ss >> userID >> delimiter >> userPW;

        if (id == userID && pw == userPW) {
            found = true;

            cout << "\tPlease Wait";
            for (int i = 0; i < 3; i++) {
                cout << ".";
                Sleep(800);
            }

            system("cls");
            cout << "\tWelcome To This Page!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "\tError: Incorrect Login ID Or Password!" << endl;
    }

    infile.close();
    Sleep(5000);
}

int main() {
    Login log;
    bool exitProgram = false;

    while (!exitProgram) {
        system("cls");
        int choice;

        cout << "\tWelcome To Registration & Login Form" << endl;
        cout << "\t************************************" << endl;
        cout << "\t1. Register." << endl;
        cout << "\t2. Login." << endl;
        cout << "\t3. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(log);
                break;
            case 2:
                loginUser();
                break;
            case 3:
                system("cls");
                exitProgram = true;
                cout << "\tGood Luck!" << endl;
                Sleep(3000);
                break;
            default:
                cout << "\tInvalid Choice! Please Try Again." << endl;
                Sleep(2000);
                break;
        }

        Sleep(3000);
    }

    return 0;
}
