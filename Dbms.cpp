//Writing Dbms backend

//Note i am working with Csv files
//So dont try to modifying the code
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Global User
string USER;

class Student
{
private:
    long Roll_number, Contact;
    string Name, Fathers_name, Email, Section;
    double Marks;

    //String simplifier
    char *simplifier(string character_set)
    {
        char *orignal;
        for (int i = 0; i < character_set.length(); i++)
        {
            orignal[i] = character_set[i];
        }
    }
    //Simple login function
    void Login()
    {
        string user, password, reader;
        ifstream login;
        login.open("pass.txt", ios::in);
        bool check = false;
        cout << "Enter user name:";
        cout << "Enter password:";
        cin >> user >> password;
        while (login >> reader)
        {
            if (user == reader)
            {
                check = true;
            }
        }
        if (check)
        {
            USER = user + ".csv";
            return;
        }
        else
        {
            //ethe ik sign up function call hovega jehra mai define krga
            cout << "u are not a member want to sign or exit";
            //sign_up()
            //exit()
        }
        login.close();
    }

    //Sign up function
    void Sign_up()
    {
        string user, password;
        ofstream signup;
        signup.open("pass.txt", ios::app);
        cout << "Enter new user name";
        cout << "Enter New password";
        cin >> user >> password;
        signup << user << " " << password;
        signup.close();
        cout << "U are a new user";

        // File initializing of new user
        signup.open(user + ".csv", ios::out);
        signup.close();
    }

public:
    //Default constructor
    //Pritapal Apna front end ethe likhi jehra subto pehle Show hovega
    Student()
    {
        system("cls");
        int option;
        cout << "1.sign up and 2.login;";
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
    //This function is Takes agrument and add to file simple
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

        //Add method
        ofstream add;
        add.open(USER, ios::app);
        //Writing into csv
        add << Name << "," << Roll_number << "," << Section << "," << Marks << "," << Fathers_name << "," << Contact << "," << Email << endl;
        add.close();
    }
    void Display()
    {
        //Defining varibale for Reading
        string name, fathers_name, section, email, roll, contact, marks;
        // Reading method
        fstream File(USER);
        //Exception
        if (!File.is_open())
        {
            cout << "Unable to open";
        }
        while (File.good())
        {
            //Using getline
            getline(File, name, ',');
            getline(File, roll, ',');
            getline(File, section, ',');
            getline(File, marks, ',');
            getline(File, fathers_name, ',');
            getline(File, contact, ',');
            getline(File, email, '\n');
            // Writing to console
            cout << name << " " << roll << " " << section << " " << marks << " " << fathers_name << " " << contact << " " << email << endl;
        }
        //closing file
        File.close();
    }
};

int main()
{
    return 0;
}