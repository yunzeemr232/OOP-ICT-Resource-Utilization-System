#include <iostream>
#include <vector>
#include <cstdlib>
#include "R.h"
#include "RService.h"

using namespace std;

// ===============================
// USER STRUCT
// ===============================
struct User
{
    string fullname;
    string username;
    string contact;
    string email;
    string password;
};

vector<User> users;

// ===============================
// CLEAR SCREEN
// ===============================
void clearScreen()
{
    system("cls");
}

// ===============================
// SIGN UP
// ===============================
void signUp()
{
    User u;

    clearScreen();

    cout << "===================================\n";
    cout << "            SIGN UP\n";
    cout << "===================================\n";

    cout << "Full Name: ";
    cin.ignore();
    getline(cin, u.fullname);

    cout << "Username: ";
    cin >> u.username;

    for (const auto &user : users)
    {
        if (user.username == u.username)
        {
            cout << "\nUsername already exists!\n";
            return;
        }
    }

    cout << "Contact: ";
    cin >> u.contact;

    cout << "Email: ";
    cin >> u.email;

    cout << "Password: ";
    cin >> u.password;

    users.push_back(u);

    cout << "\nAccount Created Successfully!\n";
}

// ===============================
// LOGIN
// ===============================
bool login()
{
    string username, password;
    int choice;

    while (true)
    {
        clearScreen();

        cout << "===============================================\n";
        cout << " WELCOME TO ICT RESOURCE CENTER SYSTEM\n";
        cout << "===============================================\n";

        cout << "\n1. Login\n2. Sign Up\n3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            break;

        case 2:
            signUp();
            continue;

        case 3:
            exit(0);

        default:
            continue;
        }

        cout << "\nUsername: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        for (const auto &u : users)
        {
            if (u.username == username && u.password == password)
            {
                cout << "\nLogin Successful!\n";
                return true;
            }
        }

        cout << "\nInvalid Credentials!\n";
    }
}

// ===============================
// MENU
// ===============================
void showMenu()
{
    cout << "\n===================================\n";
    cout << " ICT RESOURCE CENTER SYSTEM\n";
    cout << "===================================\n";

    cout << "1. Add Resource\n";
    cout << "2. All Resources\n";
    cout << "3. Damaged Resources\n";
    cout << "4. Find Resource\n";
    cout << "5. Logout\n";
    cout << "6. Exit\n";

    cout << "Enter Choice: ";
}

// ===============================
// MAIN
// ===============================
int main()
{
    RService center;

    // DEFAULT DATA
    center.addR(R("Service1", "Lab PC 05", "Machine", "Available"));
    center.addR(R("Service2", "Server Rack A", "Machine", "In Use"));
    center.addR(R("Service3", "Main Switch", "Network", "Operational"));
    center.addR(R("Service4", "WiFi Access Point", "Network", "Damaged"));
    center.addR(R("Service5", "Projector Lab 2", "Facility", "Damaged"));

    while (true)
    {
        if (!login())
            continue;

        bool loggedIn = true;

        while (loggedIn)
        {
            clearScreen();
            showMenu();

            int choice;
            cin >> choice;

            bool stayInModule = true;

            while (stayInModule)
            {
                clearScreen();

                switch (choice)
                {
                case 1:
                {
                    center.inputR();

                    cout << "\n1. Go Back\n2. Main Menu\n";
                    int nav;
                    cin >> nav;

                    stayInModule = false;
                    break;
                }

                case 2:
                {
                    center.listAllR();

                    cout << "\n1. Go Back\n2. Main Menu\n";
                    int nav;
                    cin >> nav;

                    stayInModule = false;
                    break;
                }

                case 3:
                {
                    center.listDamagedR();

                    cout << "\n1. Go Back\n2. Main Menu\n";
                    int nav;
                    cin >> nav;

                    stayInModule = false;
                    break;
                }

                case 4:
                {
                    string id;
                    cout << "Enter Service ID: ";
                    cin >> id;

                    R *found = center.findR(id);

                    clearScreen();

                    if (found)
                        found->printDetails();
                    else
                        cout << "Resource NOT FOUND\n";

                    cout << "\n1. Go Back\n2. Main Menu\n";
                    int nav;
                    cin >> nav;

                    stayInModule = false;
                    break;
                }

                case 5:
                    loggedIn = false;
                    stayInModule = false;
                    break;

                case 6:
                    exit(0);

                default:
                    stayInModule = false;
                    break;
                }
            }
        }
    }

    return 0;
}
