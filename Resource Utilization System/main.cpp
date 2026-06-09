#include <iostream>
#include <string>
#include <cstdlib>

#include "R.h"
#include "RService.h"

using namespace std;

void clearScreen()
{
    system("cls");
}

void backToMenu()
{
    int option;

    cout << "\n=================================\n";
    cout << "1. Return to Main Menu\n";
    cout << "2. Exit System\n";
    cout << "Enter Option: ";
    cin >> option;

    if(option == 2)
    {
        clearScreen();

        cout << "Thank you for using the system.\n";

        exit(0);
    }

    clearScreen();
}


void addNewService(RService& center)
{
    string id, name, type, status;

    cout << "=== ADD NEW SERVICE ===\n\n";

    cout << "Enter Service ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Service Name: ";
    getline(cin, name);

    cout << "Enter Service Type: ";
    getline(cin, type);

    cout << "Enter Status (Available/In Use/Damaged/Operational): ";
    getline(cin, status);

    center.addR(R(id, name, type, status));

    cout << "\nService added successfully!\n";
}

int main()
{
    RService center;

    center.addR(R("service1", "Lab PC 05", "Machine", "Available"));
    center.addR(R("service2", "Server Rack A", "Machine", "In Use"));
    center.addR(R("service3", "Main Switch", "Network", "Operational"));
    center.addR(R("service4", "Library Wi-Fi", "Network", "Damaged"));
    center.addR(R("service5", "Projector Lab 2", "Facility", "Available"));

    int choice;

    do
    {
        clearScreen();

        cout << "=========================================\n";
        cout << " NJALA ICT UTILIZATION RESOURCE CENTER SYSTEM\n";
        cout << "=========================================\n\n";

        cout << "=========== MAIN MENU ===========\n";
        cout << "1. View All Services\n";
        cout << "2. Service Condition\n";
        cout << "3. Access a Service\n";
        cout << "4. View Damaged Services\n";
        cout << "5. Add New Service\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        clearScreen();

        switch(choice)
        {
        case 1:

            cout << "=== ALL SERVICES ===\n\n";

            center.listServiceNames();

            backToMenu();

            break;

        case 2:

            cout << "=== SERVICE CONDITIONS ===\n\n";

            center.listAllR();

            backToMenu();

            break;

        case 3:
        {
            string id;

            cout << "=== ACCESS A SERVICE ===\n\n";

            cout << "Enter Service ID: ";
            cin >> id;

            clearScreen();

            R* service = center.findR(id);

            if(service != nullptr)
            {
                cout << "=== SERVICE FEEDBACK ===\n\n";

                cout << "Service Name : "
                     << service->getRName() << endl;

                cout << "Current State: "
                     << service->getStatus() << endl;

                if(service->getStatus() == "Available")
                {
                    cout << "\nFeedback: Service is available.\n";
                    cout << "Access Granted Successfully!\n";

                    service->updateStatus("In Use");
                }
                else if(service->getStatus() == "In Use")
                {
                    cout << "\nFeedback: Service currently in use.\n";
                }
                else if(service->getStatus() == "Damaged")
                {
                    cout << "\nFeedback: Service is damaged.\n";
                    cout << "Maintenance Required.\n";
                }
                else if(service->getStatus() == "Operational")
                {
                    cout << "\nFeedback: Service operational.\n";
                }
            }
            else
            {
                cout << "Error: Service ID not found!\n";
            }

            backToMenu();

            break;
        }

        case 4:

            cout << "=== DAMAGED SERVICES ===\n";

            center.listDamagedR();

            backToMenu();

            break;

        case 5:

            addNewService(center);

            backToMenu();

            break;

        case 6:

            clearScreen();

            cout << "Thank you for using the ICT Resource Center System.\n";

            break;

        default:

            cout << "Invalid choice! Try again.\n";

            backToMenu();
        }

    } while(choice != 6);

    return 0;
}
