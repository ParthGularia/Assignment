#include <iostream>
#include <string>
using namespace std;
class ATM
{
private:
    string userId;
    string password;
    double balance;
public:
    void welcomemessage()
    {
        cout << "Hi! Welcome to Mr.Zamar's ATM Machine!" << endl;
    }
    void mainmenu()
    {
        cout << " Select an option from the menu below:" << endl;
        cout << "1. Login (Login)" << endl;
        cout << "2. Create New Account" << endl;
        cout << "3. Quit" << endl;
    }
    void aftermainmenu()
    {
        cout << "1. Deposit Money (Deposit)" << endl;
        cout << "2. Withdraw Money (Withdraw)" << endl;
        cout << "3. Request Balance (Balance)" << endl;
        cout << "4. Quit" << endl;
    }
    void start()
    {
     welcomemessage();
    mainmenu();
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
            login();
            break;
        case '2':
            createNewAcc();
            break;
        case '3':
            cout << "Thanks for stopping by!" << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            start();
        }
    }
    void login()
    {
        string inputuid, inputpass;
        cout << "Please enter your user id: ";
        cin >> inputuid;
        cout << "Please enter your password: ";
        cin >> inputpass;
        if (inputuid == userId && inputpass == password)
        {
            cout << "SUCCESSFUL LOGIN!" << endl;
            aftermainmenu();
            choice();
        }
        else
        {
            cout << "******** LOGIN FAILED! ********" << endl;
            start();
        }
    }
    void createNewAcc()
    {
        string newuid, newpass;
        cout << "Please enter your user name: ";
        cin >> newuid;
        cout << "Please enter your password: ";
        cin >> newpass;
        userId = newuid;
        password = newpass;
        cout << "Thank You! Your account has been created!" << endl;
        start();
    }
   void choice()
{
    char subChoice;
    do
    {
        cin >> subChoice;
        switch (subChoice)
        {
        case '1':
        {
            int depositAmount;
            cout << "Amount of deposit: $";
            cin >> depositAmount;
            balance += depositAmount;
            cout << "Deposit successful." << endl;
            break;
        }
        case '2':
        {
            int withdrawalAmount;
            cout << "Amount of withdrawal: $";
            cin >> withdrawalAmount;
            if (balance >= withdrawalAmount)
            {
                balance -= withdrawalAmount;
                cout << "Withdrawal successful." << endl;
            }
            else
            {
                cout << "Withdrawal failed due to insufficient balance." << endl;
            }
            break;
        }
        case '3':
        {
            cout << "Your balance is $" << balance << "." << endl;
            break;
        }
        case '4':
        {
            cout << "Thanks for stopping!" << endl;
            return;
        }
        default:
            if (subChoice > '4') {
                cout << "Exiting due to invalid choice." << endl;
                return;
            }
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}

};
int main()
{
    ATM obj;
    obj.start();
    return 0;
}