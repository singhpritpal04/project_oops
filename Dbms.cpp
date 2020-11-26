            //AGC Student Database Management System
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <process.h>
#include <stdio.h>
using namespace std;

//Global User
string USER;

class Student
{
private:
    long Roll_number, Contact;
    string Name, Fathers_name, Email, Section;
    double Marks;
    void show()
    {

        cout <<left<< setw(15) <<Name << setw(15) << Fathers_name << setw(25)<< Email<< setw(8)<< Marks << setw(20)<< Roll_number << setw(12)<< Contact << endl;
    }
    
    //Simple login function
    void Login()
    {
        system("cls");
        string user, password, reader;
        ifstream login;
        login.open("pass.txt", ios::in);
        bool check = false;
        cout<<"\t\t___________________________________________\n\n";
        cout << "\t\tEnter User Name : ";
        cin >> user;
        cout << "\n\t\tEnter Password : ";
        cin >> password;
        cout<<"\t\t___________________________________________\n";
        while (login >> reader)
        {
            if (user == reader)
            {
                check = true;
            }
        }
        if (check)
        {
            USER = user + ".txt";
            return;
        }
        else
        {
            cout << "u are not a member want to sign or exit";
        }
        login.close();
    }

    //Sign up function
    void Sign_up()
    {
        system("cls");
        string user, password;
        ofstream signup;
        signup.open("pass.txt", ios::app);
        cout<<"\t\tCreating New User :)\n";
        cout<<"\t\t________________________________________________________________\n";
        cout << "\n\t\tEnter New User Name : ";
        cin >> user;
        cout << "\n\t\tEnter your Password : ";
        cin >> password;
        signup << user << " " << password;
        signup.close();
        cout << "\t\tYou are a New User :)"<<endl;

        // File initializing of new user
        signup.open(user + ".txt", ios::out);
        signup.close();
    }

public:
    
    //Default constructor
    Student()
    {
        system("cls");
        int option;
        cout<<"\t\t____________________________________________"<<endl;
        cout << "\n\t\t  Welcome to Agc Student Management System" << endl;
        cout<<"\t\t____________________________________________"<<endl;
        cout << "\n\t\t  1. Sign Up\n\n\t\t  2. Login"<<endl;
        cout<<"\t\t____________________________________________"<<endl;
        cout<<"\n\t\t  Enter your Choice here : ";
        cin >> option;
        switch (option)
        {
        case 1:
            Sign_up();
            break;

        case 2:
            Login();
            break;
        }
    }

    //Writing Add function
    //This function Takes agrument and add to file simple
    void Add(string name, long roll, string section, double marks, string fathers_name, long contact, string email = "No id")
    {
        //Main variable assigning
        Name = name;
        Roll_number = roll;
        Section = section;
        Marks = marks;
        Fathers_name = fathers_name;
        Contact = contact;
        Email = email;
        //Adding data in files
        ofstream Add;
        Add.open(USER, ios::app);
        Add.write((char *)this, sizeof(*this));
        Add.close();
    }
    void Search(long roll)
    {
        bool flag = false;
        ifstream search;
        search.open(USER, ios::in);
        if (!search)
        {
            cout << "Unable to open :(";
        }
        else
        {
            while (search.read((char *)this, sizeof(*this)))
            {
                if (roll == Roll_number)
                {
                    flag = true;
                    show();
                    break;
                }
            }
            search.clear();
            if (!flag)
            {
                cout << "Record not found :(";
            }
            search.close();
        }
    }
    void Delete(long roll)
    {
        int count = 0;
        ofstream Temp;
        Temp.open("Temp.txt", ios::out);
        ifstream Read;
        Read.open(USER, ios::in);
        while (Read.read((char *)this, sizeof(*this)))
        {
            if (roll != Roll_number)
            {
                count++;
                Temp.write((char *)this, sizeof(*this));
            }
        }
        if (count != CountRecords())
        {
            Temp.close();
            Read.close();
            std::remove(USER.c_str());
            std::rename("Temp.txt", USER.c_str());
        }
        else
        {
            Temp.close();
            Read.close();
        }
    }
    void Update(long roll, double marks)
    {
        bool check = false;
        fstream update;
        update.open(USER, ios::ate | ios::in | ios::out);
        update.seekg(0);
        while (update.read((char *)this, sizeof(*this)))
        {
            if (roll == Roll_number)
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            update.seekp(update.tellp() - sizeof(*this));
            this->Marks = marks;
            update.write((char *)this, sizeof(*this));
            update.close();
        }
        else
        {
            update.close(); 
        }
    }
    int CountRecords()
    {
        int Count = 0;
        ifstream File;
        File.open(USER, ios::in);
        while (File.read((char *)this, sizeof(*this)))
        {
            Count++;
        }
        File.close();
        return Count;
    }

    //Display function

    void Display()
    {
        system("cls");
        ifstream Read;
        Read.open(USER, ios::in);
        if (!Read)
        {
            cout << "Unable to open file...";
            return;
        }
        else
        {
            cout <<left<< setw(15) <<"Student Name" << setw(15) << "Father Name" << setw(25)<< "Email" << setw(8)<< "Marks" << setw(20)<< "Roll Number" << setw(12)<< "Contact" << endl;
            cout<<"_______________________________________________________________________________________________\n";
            while (Read.read((char *)this, sizeof(*this)))
            {
                
                show();
            }
            Read.clear();
            Read.close();
        }
        getch();
    }
};

//Main function

int main()
{
    Student info;
    string name, section, email, father_name;
    double marks;

    long contact, roll;
    char choice;
    do
    {
        system("cls");
        cout << "\t\t   Welcome to the CSE Student Management\n";
        cout<<"\t\t___________________________________________\n\n";
        cout << "\t\t   1. Add Student Data\n\n\t\t   2. Display Students Data\n\n\t\t   3. Search Student Data\n\n\t\t   4. Update Student Data\n\n\t\t   5. Delete Student Data\n\n\t\t   6.Exit\n";
        cout<<"\t\t___________________________________________\n\n";
        cout << "\t\t\t Enter your Choice here : ";
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            system("cls");
            cout << "Enter Name of the Student : ";
            cin >> name;
            cout << "Enter the Father Name : ";
            cin >> father_name;
            cout << "Enter the Roll Number of the Student : ";
            cin >> roll;
            cout << "Enter the Section : ";
            cin >> section;
            cout << "Enter the E-mail : ";
            cin >> email;
            cout << "Enter the Contact Number : ";
            cin >> contact;
            cout << "Enter the Marks of the Student : ";
            cin >> marks;
            info.Add(name, roll, section, marks, father_name, contact, email);
            break;
        }

        case '2':
        {
            info.Display();
            break;
        }
        case '3':
        {
            cout << "Enter Roll number to Search : ";
            cin >> roll;
            info.Search(roll);
            getch(); 
            break;
        }
        case '4':
        {
            cout << "Enter Roll Number : ";
            cin >> roll;
            cout<<"Enter Marks : ";
            cin>>marks;
            info.Update(roll, marks);
            break;
        }
        case '5':
        {
            cout << "Enter Roll Number : ";
            cin >> roll;
            info.Delete(roll);
            break;
        }
        case '6':
        {
            break;
        }
        default:
        {
            cout << "Invalid option :(\n";
        }
        }
    } while (choice != '6');
    return 0;
}