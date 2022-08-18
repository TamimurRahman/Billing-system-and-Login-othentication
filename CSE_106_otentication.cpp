#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct othentication
{
    int count;
};
struct othentication ot;
void login();
void registration();
int main()
{
    int operation;
    do
    {
        cout << "\n1.LOGIN";
        cout << "\n2.REGISTATION";
        cout << "\n3.Exit";
        cout << "\n\nSlect your choise : ";
        cin >> operation;
        fgetc(stdin);
        switch (operation)
        {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        default:
            system("cls");
            cout << "\nExit system :)\n\n";
            exit(0);
            break;
        }
    } while (exit);
}

void login()
{
    ot.count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\tPlease enter the username and password : ";
    cout << "\nUser name : ";
    cin >> userId;
    cout << "\nPassword : ";
    cin >> password;
    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            ot.count = 1;
            system("cls");
        }
    }
    input.close();
    if (ot.count == 1)
    {
        cout << userId << " Your login is successfull\n";
        main();
    }
    else
    {
        cout << "\nLOGIN ERROR!!Please input valid user id and password\n\n";
    }
}
void registration()
{
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "Enter the user name : ";
    cin >> ruserId;
    cout << "Enter the password : ";
    cin >> rpassword;
    ofstream f1("records.txt");
    f1 << ruserId << ' ' << rpassword;
    system("cls");
    cout << "\nRegistation Ok\n";
}