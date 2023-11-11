#include <bits/stdc++.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <map>
#include "colors.h"
using namespace std;
string globalName;
string globalbus;
int globalcount;
void login();
void registration();
void createUserFile(const std::string &username);
void forgot();
void selection();
void display_info();
void delete_info();
void service();
void dhakainner();
void outerdistrict();
void timeselection();
void busselection();
void busseat();
void payment();

int main()
{
    int t;
    int ascii = 178;
    char ch = ascii;
    int c; // c for choice
    cout << "\n\n\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << cyan << ch << reset;
    }
    cout << blue << bold << " Welcome to the Login page " << reset;

    for (int i = 0; i < 26; i++)
    {
        cout << cyan << ch << reset;
    }
    cout << "\n\n";
   
    cout << yellow << "\t\t\t____________________         MENU        ______________________" << reset << "\n\n";

    cout << "                                                                                \n\n";
    cout << red << "\t|  Press 1 to LOGIN                    |" << reset << endl;
    cout << magenta << "\t|  Press 2 to REGISTER                 |" << reset << endl;
    cout << blue << "\t|  Press 3 if you forgot your PASSWORD |" << reset << endl;
    cout << cyan << "\t|  Press 4 to Exit                     |" << reset << endl;
    cout << green << bold << "\n\t\t\tPlease Enter your choice :" << reset;
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:

        cout << "\t\t\tThankyou!\n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\tPlease select from the options given above , Try again..\n"
             << endl;
        main();
    }
}

void login()
{

    int count;
    string userId, password, id, pass;
    system("cls");
    cout << red << "\t| LOGIN: Please enter the username & password            " << reset << endl;
    cout << magenta << "\t| USERNAME : " << reset;
    cin >> userId;
    cout << blue << "\t| PASSWORD : " << reset;
    cin >> password;
    // cout<<endl;
    system("cls");

    ifstream input("records.txt");
    while (input >> id >> pass) // here reading is taking place
    {
        if (id == userId && pass == password)

        {
            globalName = id;
            count = 1;
            system("cls");
        }
    }
    input.close(); // this is for closing the file
    if (count == 1)
    {
        cout << yellow << "User Name:" << reset << blue << userId << reset << green << bold << "\n\n                  Your Login is Successful\n                    Thanks for logging in!\n\n"
             << reset;

        selection();

        // main();
    }
    else
    {
        cout << red << "\nLOGIN ERROR\nPlease check your username and password\n"
             << reset;

        main();
    }
}

void registration()
{

    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\tEnter the username :";
    cin >> ruserId;
    cout << "\n\t\t\tEnter the password :";
    cin >> rpassword;
    createUserFile(ruserId);
    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl; // here we are writing the information in the file.
    system("cls");
    cout << "\n\t\t\tRegistration is Successful\n";
    main();
}

void createUserFile(const string &username)
{
    string filename = username + ".txt";
    ofstream file(filename);

    if (file.is_open())
    {
        file.close();
        cout << "User file created: " << filename << std::endl;
    }
    else
    {
        cerr << "Error creating user file." << std::endl;
    }
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\tYou forgot your password? No worries\n";
    cout << "Press 1 to Search your id by username" << endl;
    // cout<<"2.Search your id by password"<<endl;
    cout << "Press 2 to go Back to the Main menu" << endl;
    cout << "\t\t\tEnter your choice :";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\tEnter the username which you remembered :";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n\tYour account is found\n";
            cout << "\n\tYour password is " << spass;
            main();
        }
        else
        {
            cout << "\n\tSorry, Account not found! \n";
            main();
        }

        break;
    }

    case 2:
    {
        // cin.get();
        main();
    }
    default:
        cout << "\t\t\tWrong choice! Please try again" << endl;
        forgot();
    }
}

    void selection()
    {
        cout << "1. Display my travel information" << endl;
        cout << red << "2. Delete my travel information" << reset << endl;
        cout << "3. Lead me to the travel booking page." << endl;
        cout << "Enter code: ";
        int code;
        cin >> code;

        if (code == 1)
        {
            display_info();
        }
        else if (code == 2)
        {
            delete_info();
        }
        else if (code == 3)
        {
            service();
        }
        else
        {
            cout << "You entered wrong code" << endl;
            selection();
        }
    }

    void display_info()
    {

        cout << "Your all information below given:" << endl;

        ifstream file(globalName + ".txt");

        string line;
        // Read and display each line of the file
        while (getline(file, line))
        {
            cout << green << line << reset << endl;
        }

        // Close the file when done
        file.close();
    }


    void delete_info()
    {
        cout << "Use " << red << "Y" << reset << " to delete your travel information or " << green << "N" << reset << " to keep it." << endl;
        string check;
        cin >> check;
        if (check == "N")
        {
            cout << "Information not deleted" << endl;
        }
        else if (check == "Y")
        {
            ofstream file(globalName + ".txt", ios::out);
            file.close();
            cout << "Your all information deleted." << endl;
        }
        else
        {
            cout << red << "Wrong code" << reset << endl;
            selection();
        }
    }


void service()
{


    cout << yellow << bold << "Choose Your Service Number:" << reset << endl
         << blue << "1.Dhaka Division " << red << "(Ticket not available)" << reset << endl
         << cyan << "2.Outer District" << reset << endl
         << red << "3.Exit" << reset << endl;
    cout << "Enter code: ";

    int choose;
    cin >> choose;
    if(choose==1){
        dhakainner();
    }
    else if(choose==2){
        outerdistrict();
    }
}

void dhakainner()
{

    cout << "                                 The information is identical to BRTA Bangladesh" << endl;
    cout << "                           This computation is exclusively applicable to diesel Buses \n\n"
         << endl;

    vector<string> v;
    v = {"kalshi", "Mirpur-12", "Mirpur-10", "kazipara", "Shewrapara", "Farmgate", "Shahbag", "Polton", "Gulistan",
         "Tikatuli", "Saidabad", "Jatrabari", "Signboard", "Kachpur Bridge"};

    float kilo[14] = {0.0, 2.2, 4.7, 6.1, 6.8, 11.4, 13.7, 15.6, 16.6, 17.8, 18.9, 19.9, 24.8, 28.8};

    for (int i = 0; i < 14; i++)
    {
        cout << i + 1 << "." << v[i] << "\t ";
    }
    cout << "\n\n";
    int from, destination;
    cout << "Enter the Deperture code: ";
    cin >> from;
    cout << "Enter the Destination code: ";
    cin >> destination;
    float vara = (abs(kilo[destination - 1] - kilo[from - 1])) * 2.45;

    cout << "\n"
         << v[from - 1] << " to " << v[destination - 1] << " Bus vara is = BDT ";

    if (int(vara) == vara)
    {
        if (vara < 10)
            cout << 10;
        else
            cout << vara;
    }
    else
    {
        if (vara < 10)
            cout << 10;
        else
        {
            if (vara + 0.50 > (int)vara + 1)
                cout << (int)vara + 1;
            else
                cout << (int)vara;
        }
    }

    cout << " Taka" << endl;
    cout << "\n\n  ";
}

void outerdistrict()
{
    system("cls");
    map<int, string> locationMap;
    map<int, double> fareMap;
    map<int, string> timeMap;

    // Read data from the updated "bus_fares.txt" file
    ifstream file("bus_fares.txt");
    int code;
    string location;
    double fare;
    string estimatedTime;

    while (file >> code >> location >> fare >> estimatedTime)
    {
        locationMap[code] = location;
        fareMap[code] = fare;
        timeMap[code] = estimatedTime;
    }

    file.close();

    int to;
    cout << "Kindly indicate departure Dhaka(Gabtoli) to destination locations from below; this is vice versa fare and estimated time." << endl
         << endl;
    cout << "1. " << red << "Barishal"
         << "\t2. " << green << "Bogura"
         << "\t3. " << blue << "Chapai Nawabganj"
         << "\n"
            "4. "
         << magenta << "Dinapur"
         << "\t5. " << cyan << "Jessore"
         << "\t6. " << yellow << "Joypurhat"
         << "\n"
            "7. "
         << white << "Khulna"
         << "\t8. " << white << "Kushtia"
         << "\t9. " << green << "Mymensingh"
         << "\n"
            "10. "
         << red << "Pabna"
         << "\t11. " << red << "Rangpur"
         << "\t12. " << green << "Rajshahi"
         << "\n"
            "13. "
         << yellow << "Sylhet" << reset << endl;
    cout << "Enter Code: ";
    cin >> to;

    if (to >= 1 && to <= 13)
    {
        timeselection();
        // Display the destination code, location, fare, and estimated time
        string userLocation = locationMap[to];
        double userFare = fareMap[to];
        string userTime = timeMap[to];

        // cout << "Destination Code: " << to << endl;
        cout << "Your selected Bus name: " << yellow << code << "." << globalbus << reset << endl;
        cout << "Location: Dhaka to " << userLocation << endl;
        cout << "The Fare: " << (globalcount - 1) * userFare << " Taka" << endl;
        cout << "Estimated Journey Time: " << userTime << endl;

        fstream file(globalName + ".txt", ios::in | ios::out | ios::ate);
        /////////////

        if (file.is_open())
        {
            file << "      Location: Dhaka to " << userLocation << endl;
            file << "      The Fare: " << (globalcount - 1) * userFare << " Taka" << endl;
            file << "      Estimated Journey Time: " << userTime << endl;

            file.close();
            payment();
            cout << "Your information has been saved to " << globalName << ".txt" << endl;
        }
    }

    else
    {
        cout << "Invalid destination code." << endl;
    }

    // busselection();
}

void timeselection()
{
    system("cls");
    int t;
    int code = 1;
    ifstream inputFile("bus_times.txt");
    cout << "Available bus Times:" << endl;
    string time;

    while (getline(inputFile, time))
    {
        cout << code << ". " << time << endl;
        code++;
    }
    cout << "Enter code: ";
    inputFile.close();
    cin >> t;
    if (t < 13)
    {
        busselection();
    }
    else
    {
        for (;;)
        {
            cout << "You entered wrong code" << endl;
            cout << "Enter again ";
            cin >> t;
            if (t < 13)
            {
                busselection();
                break;
            }
        }
    }

    inputFile.open("bus_times.txt"); // Reopen the file
    code = 1;
    while (getline(inputFile, time))
    {
        if (code == t)
        {
            cout << "Your selected Bus time: " << yellow << time << reset << endl;
            break;
        }
        code++;
    }

    inputFile.close();

    //save bus time in user file
    fstream file(globalName + ".txt", ios::in | ios::out | ios::ate);
    

    if (file.is_open())
    {
        file << "      Your selected Bus time: " << time << endl;
        file.close();
    }
}

void busselection()
{
    system("cls");
    int code = 1;
    int selection;
    ifstream inputFile("bus_selection.txt");
    cout << "Available bus:" << endl;
    string bus;
    while (getline(inputFile, bus))
    {
        cout << magenta << code << ". " << bus << reset << endl;
        code++;
    }
    cout << "Enter code: ";
    inputFile.close();
    cin >> selection;

    if (selection < 1 || selection > 7)
    {
        for (;;)
        {
            cout << "You entered the wrong code. Please enter a valid code." << endl;
            cin >> selection;
            if (selection != 0 && selection < 7)
                break;
        }
    }

    else
    {
        inputFile.open("bus_selection.txt"); // Reopen the file
        code = 1;
        while (getline(inputFile, bus))
        {
            if (code == selection)
            {
                globalbus = bus;
                break;
            }
            code++;
        }

        inputFile.close();
    }

    ////////////////////
//using userfile to store bus name 
    fstream file(globalName + ".txt", ios::in | ios::out | ios::ate);

    if (file.is_open())
    {
        file << "Journey:" << endl
             << endl;
        file << "      Your selected Bus name: " << bus << endl;
        file.close();
    }

    busseat();
}

void busseat()
{
    map<string, bool> seatingArrangement;
    ifstream file("available_seats.txt");
    if (file.is_open())
    {
        string seat;
        while (getline(file, seat))
        {
            seatingArrangement[seat] = true;
        }
        file.close();
    }

    cout << "\nSeating Arrangement:" << endl;
    for (char row = 'A'; row <= 'J'; ++row)
    {
        for (int col = 1; col <= 4; ++col)
        {
            string seat = string(1, row) + to_string(col);
            string status;
            if (seatingArrangement[seat])
            {
                cout << underline << red << seat << reset << ":" << red << " xxx" << reset << "   ";
            }
            else
            {
                cout << underline << green << seat << reset << ":" << green << " Avl" << reset << "   ";
            }
        }
        cout << endl;
    }
    vector<string> seatsToBook;
    string seatToBook;
    cout << "\nEnter the seat numbers you want to book separated by spaces (e.g., A1 B2 C3), or enter '0' to quit: ";
    cout << endl
         << "Choose Carefully!! " << endl;
    int count = 0;
    while (true)
    {

        string input;
        getline(cin, input);

        if (input == "0")
        {
            break;
        }
        count++;
        istringstream iss(input);

        while (iss >> seatToBook)
        {
            if (seatingArrangement.find(seatToBook) != seatingArrangement.end())
            {
                if (seatingArrangement[seatToBook])
                {
                    cout << "Sorry, seat " << seatToBook << " is already booked." << endl;
                }
                else
                {
                    seatingArrangement[seatToBook] = true;
                    seatsToBook.push_back(seatToBook);
                }
            }
            else
            {
                cout << "Invalid seat " << seatToBook << ". It does not exist." << endl;
            }
        }

        if (!seatsToBook.empty())
        {

            cout << endl;
            // Save booked seats to file
            ofstream outputFile("available_seats.txt");
            if (outputFile.is_open())
            {
                for (const auto &seatStatus : seatingArrangement)
                {
                    if (seatStatus.second)
                    {
                        outputFile << seatStatus.first << endl;
                    }
                }
                outputFile.close();
            }

            // Append booked seats to user_info.txt
            ofstream userInfoFile(globalName + ".txt", ios::app); // Open in append mode
            if (userInfoFile.is_open())
            {
                userInfoFile << "      Your selected seats are: ";
                for (const string &seat : seatsToBook)
                {
                    userInfoFile << seat << " ";
                }
                userInfoFile << endl;
                userInfoFile.close();
            }
        }

        cout << yellow << "Enter seat number or " << red << "0" << reset << yellow << " to quit: " << reset;
    }
    globalcount = count;

    if(!seatsToBook.empty())
    {
        cout << yellow << "You have booked the following seats: " << reset;
        for (const string &seat : seatsToBook)
        {
            cout << blue << seat << " " << reset;
        }
        cout << endl;
    }
}

void payment()
{

    cout << "Please select payment option: " << endl;
    cout << "1.Bkash" << endl
         << "2.DBBl" << endl
         << "3.Rocket" << endl
         << "4.Nagad" << endl;
    cout << "Enter code: ";
    int code;
    cin >> code;

        while(1)
        {
            if (code < 5)
                break;
            cout << "Please Enter right code: ";
            cin >> code;
        }

    cout << "Please send money to 017XXXXXXXXX and Wait for your confirmation." << endl;
}
