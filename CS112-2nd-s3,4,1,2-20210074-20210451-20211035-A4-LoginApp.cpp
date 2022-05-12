#include <iostream>
#include <fstream>
#include <regex>
using namespace std;
struct Users_Accounts
{
    string username;
    string email;
    string password;
    string phoneNumber;
    string fullName;
};

Users_Accounts arr[40];

bool Check_userName(const string& UN);
bool Check_Email(const string& email);
bool Check_fullNameValidation();
bool Check_PhoneNumberValidation();
bool Check_emailValidation();
bool Check_UserNameValidation();

void Registration();
void userName();
void Email();
void PhoneNumber();
void password();
void loadAccount();
void Load_IN_File(string UN,string eMail,string phone, string pass,string name);
void fullName();

string UN,eMail,pass,phone,name;
fstream File;
int k;

int main()
{
    while(true)
    {
        string choice;
        cout << "\nWelcome To Login Application :) !\n";
        cout<<"(1) Register\n(2) Login\n(3) Change Password\n(4) Exit\n";
        cout<<"________________________\nplease enter your choice:\n";
        cin>>choice;
        if(choice == "1")
        {
            cin.ignore();
            Registration();
            Load_IN_File(UN,eMail,phone,pass,name);

        }
        if(choice =="2")
        {
            cout<<"in progress";
        }
        if(choice =="3")
        {
            cout<<"in progress";
        }
        if(choice =="4")
        {
            return 0;
        }

    }
}

void Registration()
{
    loadAccount();
    userName();
    Check_userName(UN);
    Check_UserNameValidation();
    Email();
    Check_Email(eMail);
    Check_emailValidation();
    PhoneNumber();
    Check_PhoneNumberValidation();
    fullName();
    Check_fullNameValidation();
    password();
    cout<<"__Successfully Registered!__\n_________________________________";

}

void userName()
{
    cout<<"Please Enter your UserName: \n";
    getline(cin, UN,'\n');
    while(!Check_userName(UN))
    {
        cout<<"Please Enter another UserName: \n";
        cin.clear(),cin.sync();
        getline(cin, UN,'\n');
    }
    while(!Check_UserNameValidation())
    {
        cout<<"Please Enter a valid username: \n";
        cin.clear(),cin.sync();
        getline(cin, UN,'\n');
    }
}

bool Check_userName(const string& UN)
{
    int count =0;
    for(int i =0; i<40 ;++i)
    {
        if(UN == arr[i].username)
        {
            cout << "this username already exists!\n";
            count++;
        }
    }
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Check_UserNameValidation()
{
    string regexPa = "[a-zA-Z0-9_]+";
    regex regexVa(regexPa);
    bool isValid = regex_match(UN, regexVa);
    if(!isValid)
    {
        cout<<"invalid!!\n";
        return false;
    }
    else
    {
        return true;
    }
}

void Email()
{
    cout<<"Please Enter your Email:";
    getline(cin, eMail,'\n');

    while(!Check_Email(eMail))
    {
        cout<<"Please enter another email: ";
        getline(cin, eMail,'\n');
    }
}

//checks if registered Email already exists.
bool Check_Email(const string& email)
{
    int count = 0;
    for(int i =0;i<40;++i)
    {
        if(eMail == arr[i].email)
        {
            cout << "this Email already exists, please enter a new one.\n";
            count++;
        }
    }
    if (count == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Checks if the email is in valid form
bool Check_emailValidation()
{
    string regexPattern = "[a-zA-Z0-9]+\\.?[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.?[a-zA-Z0-9]*";
    regex regexValidate(regexPattern);
    bool isValid = regex_match(eMail, regexValidate);
    while(!isValid)
    {
        cout<<"Invalid email format!!\nPlease enter a proper email:\n";
        getline(cin, eMail,'\n');
        while(!Check_Email(eMail))
        {
            cout<<"Please enter another email: ";
            getline(cin, eMail,'\n');
        }
        isValid = regex_match(eMail, regexValidate);
    }

}

void PhoneNumber()
{
    cout<<"\nPlease enter your phone number: \n";
    getline(cin, phone,'\n');

    while(!Check_PhoneNumberValidation())
    {
        cout<<"Please enter a valid Phone Number:\n ";
        getline(cin, phone,'\n');
    }
}

// checks if the phone number is in valid format
bool Check_PhoneNumberValidation()
{
    string regexP = "01[0125][0-9]{8}";
    regex regexVal(regexP);
    bool isValid = regex_match(phone, regexVal);
    if (!isValid)
    {
        cout<<"\nInvalid Phone Number format!\n";
        return false;
    }
    else
    {
        return true;
    }

}

void password()
{
    cout<<"Please enter your password: \n";
    cin>>pass;
}

void fullName()
{
    cout<<"\nPlease enter your fullname: \n";
    cin.ignore();
    getline(cin, name);
    while(!Check_fullNameValidation())
    {
        cout<<"\nPlease enter a valid fullname: \n";
        cin.clear(),cin.sync();
        getline(cin, name);
    }
}

// checks if fullname is in valid form
bool Check_fullNameValidation()
{
    string regexP = "[a-zA-Z_]+";
    regex regexV(regexP);
    bool isValid = regex_match(name, regexV);
    if(!isValid)
    {
        cout<<"invalid!!\n";
        return false;
    }
    else
    {
        return true;
    }
}

// loads users data into a file
void Load_IN_File(string UN,string eMail,string phone, string pass,string name)
{
    File.open("Registered_Accounts.txt",ios::app);
    File<<"1."<<UN<<"\n"<<"2."<<eMail<<"\n"<<"3."<<phone<<"\n"<<"4."<<pass<<"\n"<<"5."<<name<<"\n";
    File<<"\n\n";
    File.close();
}

// loads the file into the array
void loadAccount()
{
    k =0;
    File.open("Registered_Accounts.txt",ios::in);
    string line,st;
    while(getline (File,line))
    {
        st = line;
        if (line != "\n")
        {
            if(st[0] == '1')
            {
                st.erase(0,2);
                arr[k].username =st;
            }
            else if (st[0] =='2')
            {
                st.erase(0,2);
                arr[k].email =st;

            }
            else if (st[0]=='3')
            {
                st.erase(0,2);
                arr[k].password=st;
            }
            else if (st[0] == '4')
            {
                st.erase(0,2);
                arr[k].phoneNumber =st;
            }
            else if (st[0] == '5')
            {
                st.erase(0,2);
                arr[k].fullName =st;
            }
        }
        k++;
    }
    File.close();
}

