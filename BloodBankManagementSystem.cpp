#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
using namespace std;
struct Donor
{
    string name;
    string bloodType;
    int age;
    string gender;
    string address;
    string contact;
};
vector<Donor> donors;

void addDonor()
{
    Donor newDonor;
    cout << "Enter donor name: ";
    getline(cin, newDonor.name);
    cout << "Enter donor blood type: ";
    getline(cin, newDonor.bloodType);
    cout << "Enter donor age: ";
    cin >> newDonor.age;
    cout << "Enter Your Contact Details : ";
    cin >> newDonor.contact;
    cout << "Enter donor address: ";
    cin >> newDonor.address;
    cout << "Enter your gender : ";
    cin.ignore();
    getline(cin, newDonor.gender);
    donors.push_back(newDonor);
    
    
    ofstream outFile("donors.txt", ios::app); 
    if (outFile.is_open()) 
    {
        outFile << newDonor.name << endl; 
        outFile << newDonor.bloodType << endl;
        outFile << newDonor.age << endl;
        outFile << newDonor.gender << endl;
        outFile << newDonor.address << endl;
        outFile << newDonor.contact << endl;
        outFile.close(); 
        cout << "Donor added successfully!\n\n";
    }
    else 
    {
        cout << "Error: cannot open the file!\n\n";
    }
}
void loadDonors()
{
    
    ifstream inFile("donors.txt"); 
    if (inFile.is_open()) 
    {
        Donor temp; 
        while (getline(inFile, temp.name)) 
        {
            getline(inFile, temp.bloodType);
            inFile >> temp.age;
            inFile.ignore();
            getline(inFile, temp.gender);
            getline(inFile, temp.address);
            getline(inFile, temp.contact);
            donors.push_back(temp);
        }
        inFile.close(); 
        cout << "Donors loaded successfully!\n\n";
    }
    else 
    {
        cout << "Error: cannot open the file!\n\n";
    }
}
void searchDonor()
{
    string bloodType;
    cout << "Enter the blood type you are looking for: ";
    getline(cin, bloodType);
    cout << "Donors with blood type " << bloodType << ":\n";
    bool foundDonor = false;
    for (Donor donor : donors)
    {
        if (donor.bloodType == bloodType)
        {
            cout << "Name: " << donor.name << endl;
            cout << "Blood Type: " << donor.bloodType << endl;
            cout << "Age: " << donor.age << endl;
            cout << "Gender: " << donor.gender << endl
                 << endl;
            cout << "Contact Details: " << donor.contact << endl
                 << endl;
            foundDonor = true;
        }
    }
    if (!foundDonor)
    {
        cout << "No donors found with blood type " << bloodType << endl
             << endl;
    }
}
void searchByaddress()
{
    string address;
    cout << "Enter the address in which you want blood: ";
    getline(cin, address);
    cout << "Donors with address " << address << ":\n";
    bool foundDonor = false;
    for (Donor donor : donors)
    {
        if (donor.address == address)
        {
            cout << "Name: " << donor.name << endl;
            cout << "Blood Type: " << donor.bloodType << endl;
            
            cout << "Age: " << donor.age << endl;
            cout << "Gender: " << donor.gender << endl
                 << endl;
            cout << "Contact Details: " << donor.contact << endl
                 << endl;
            foundDonor = true;
        }
    }
    if (!foundDonor)
    {
        cout << "No donors found with blood type " << address << endl
             << endl;
    }
}
void Receiver()
{
    int choice;
    do
    {
        cout << "Blood Bank Management System\n";
        cout << "1. Search By address\n";
        cout << "2. Search Blood Group\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            searchByaddress();
            break;
        case 2:
            searchDonor();
            break;
        case 3:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice!\n\n";
            break;
        }
    } while (choice != 3);
}
int main()
{
    int choice;
    do
    {
        cout << "Blood Bank Management System\n";
        cout << "1. Add Donor\n";
        cout << "2. Patient\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            addDonor();
            break;
        case 2:
            Receiver();
            break;
        case 3:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice!\n\n";
            break;
        }
    } while (choice != 3);
    return 0;
}
