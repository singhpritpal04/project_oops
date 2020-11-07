//Agc cse student database
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student
{
private:
    string name, section, father_name, email;
    long roll_number, contact;
    double marks;
    string User;
    //Vere eh show function hai user vaste nahi sirf backend vaste hai
    void show()
    {
        cout << name << " " << roll_number << " " << section << " " << father_name << " " << email << " " << contact << endl;
    }

public:
    // vere contructor vich design krdi jo pehle ave jive login function
    // fer tenu main vicho krvan di lor nahi hovegi
    // mai kr reha login design krdi apne hisab naal okay??
    Student()
    {
        login();
    }
    void login()
    {
        string user, password, user1;
        fstream Login, File;
        User = user;
        Login.open("Pass.txt", ios::in | ios::app);
        //Pritpal mai simple likh reha tu apne hisab naal likhdi
        if (!Login)
        {
            //es jagah te initial stage hai jado koi user na hove
            cout << "Intialally no user" << endl;
            cout << "become a user" << endl;
            cout << "Enter user:";
            cin >> user;
            cout << "Enter password:";
            cin >> password;
            cout << "U are user now";
            //veere ethe nave user di file be gi
            File.open(user + ".txt", ios::out);
            Login.write((char *)this, sizeof(*this));
            Login.close();
        }
        else
        {
        x:
            cout << "Enter user:";
            cin >> user;
            cout << "Enter password:";
            cin >> password;
            int k = 0;
            while (Login >> user1)
            {
                if (user == user1)
                {
                    k = 1;
                    cout << "Now u can continue->";
                    return;
                }
            }
            if (!k)
            {
                //tu ethe exit wala option v padi bhave
                //Nale ethe nve user bnana da option v padi
                //sign up and sign in da
                goto x;
            }
        }
    }
    void Add(string Name, long Roll, string Section, string Father, string Email, long Contact, double Marks)
    {
        //Eh add operation function da ui design vekli
        //Asi main function vich design krni hai te eh bas argument reciever hovega
        ofstream File;
        File.open(User + ".txt", ios::app);
        name = Name;
        roll_number = Roll;
        marks = Marks;
        section = Section;
        father_name = Father;
        email = Email;
        contact = Contact;
        File.write((char *)this, sizeof(*this));
        File.close();
    }
    void View()
    {
        ifstream File;
        File.open(User + ".txt", ios::in);
        while (File.read((char *)this, sizeof(*this)))
        {
            show();
        }
        File.close();
    }
    //veere eh func argument wala hai eh v design krli main funct teri zimewari hai Ui main
    //Veere delete te update dono verified honge bool type hage dono
    bool Delete(long roll)
    {
        bool check = false;
        fstream File, Del;
        File.open(User + ".txt", ios::in | ios::ate);
        Del.open("Temp.txt", ios::out);
        while (File.read((char *)this, sizeof(*this)))
        {
            if (roll != roll_number)
            {
                Del.write((char *)this, sizeof(*this));
            }
            else
            {
                check = true;
            }
        }
        File.close();
        Del.close();
        char *user;
        for (int i = 0; i < User.length(); i++)
        {
            user[i] = User[i];
        }
        std::remove(user);
        std::rename("Temp.txt", user);
        return check;
    }
    bool Update(long roll, double Marks)
    {
        bool check = false;
        fstream File;
        File.open(User, ios::ate | ios::in);
        File.seekg(0);
        while (File.read((char *)this, sizeof(*this)))
        {
            if (roll == roll_number)
            {
                check = true;
                File.seekg(File.tellp() - sizeof(*this));
                marks = Marks;
                File.write((char *)this, sizeof(*this));
            }
        }
        return check;
    }
    ~Student()
    {
        cout << "Good bye.....";
    }
};
int main()
{
    Student info;
    return 0;
}