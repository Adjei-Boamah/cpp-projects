#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    double balance = 0;
    bool accountCreated = false;
public:
    string UserNames;
    string accountNumber;


    void createAccount() {
        cout<<"CREATE AN ACCOUNT AT KINEMS BANK"<<endl;

            cout<<"Enter your User name: "<<endl;
            getline(cin,UserNames);
            do {
                cout<<"Enter your account number: "<<endl;
                cin>>accountNumber;
            }while (accountNumber.length() != 6);
            cin.ignore();
            do {
                cout<<"Enter the initial balance: "<<endl;
                cin>>balance;
            }while (balance < 0);
            cin.ignore();
            accountCreated = true;
            cout<<"Your Account Has been created successfully!"<<endl;
            accountDisplay();

    }
    void bankServices() {
        int x;
        do {
            cout<<"Choose the  Bank service you want"<<endl;
            cout<<"1.Create account"<<endl;
            cout<<"2.Display account"<<endl;
            cout<<"3.Deposit account"<<endl;
            cout<<"4.Withdraw Money"<<endl;
            cout<<"5.Check account Balance"<<endl;
            cout<<"6. Search account"<<endl;
            cout<<"0.Exit"<<endl;
            cin>>x;
            cin.ignore();
            if (x == 1) {
                createAccount();
            }else {
               if (!accountCreated) {
                   cout<<"You need to create an account first"<<endl;
               }else if (x == 2) {
                   accountDisplay();
               }else if (x == 3) {
                   depositMoney();
               } else if (x == 4) {
                   withdrawMoney();
               } else if (x == 5) {
                   checkBalance();
               }else if (x == 6) {
                   searchAccount();
               }else {
                   cout<<"EXIT"<<endl;
               }
            }


        }while (x != 0);
    }

     void  checkBalance () const {

        cout<<"Your Remaining Balance is "<<balance<<endl;
    }
    void withdrawMoney() {
        int amount;
        cout<<"Enter the amount of money you want to withdraw "<<endl;
        cin>>amount;
        if (amount < 0) {
            cout<<"Invalid amount of money"<<endl;
        }else {
            if (amount > balance) {
                cout<<"Insufficient Balance!!!!"<<endl;
            }else if (amount <= balance){
                balance = balance - amount;
                cout<<"You withdrawn "<<amount<<endl;
                cout<<"Your remaining balance is "<<balance<<endl;
            }
        }

    }


    void depositMoney() {
        double amount;
        do {
            cout<<"Enter the amount you want to deposit "<<endl;
            cin>>amount;
        }while (amount <= 0);
       balance = balance + amount;
        cout<<"Your new Balance is "<<balance<<endl;
    }

    void accountDisplay() const {
        cout<<"GHANKINEMS BANK MANAGEMENT "<<endl;
        cout<<"The account name is : "<<UserNames<<endl;
        cout<<"The account number: "<<accountNumber<<endl;
        cout<<"The Account  balance: "<<balance<<endl;
    }
    void searchAccount() const {
        string x;
        do {
            cout<<"Enter Your account number: "<<endl;
            cin>>x;
        }while (x.length() != 6);
        if (x == accountNumber) {
            cout<<"Account Holder's name "<<UserNames<<endl;
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Account Balance: "<<balance<<endl;
        }else {
            cout<<"Invalid account number"<<endl;
        }
    }
    string getAccountNumber() {
        return accountNumber;
    }

};

int main() {
    cout << "GHANA KINEMS BANK MANAGEMENT" << endl;

    BankAccount accounts[10];
    int accountCount = 0;

    int choice;
    string accNumber;
    bool found;

    do {

        cout << "\n===== KINEMS BANK =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Search Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Check Balance" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: "<<endl;
        cin >> choice;
        cin.ignore();

        switch(choice) {

        case 1:

            if(accountCount < 10)
            {
                accounts[accountCount].createAccount();
                accountCount++;
            }
            else
            {
                cout << "Maximum number of accounts reached." << endl;
            }

            break;

        case 2:

            if(accountCount == 0)
            {
                cout << "No accounts found." << endl;
            }
            else
            {
                for(int i = 0; i < accountCount; i++)
                {
                    cout << "\nAccount " << i + 1 << endl;
                    accounts[i].accountDisplay();
                }
            }

            break;

        case 3:

            found = false;

                do {
                    cout << "Enter account number: "<<endl;
                    getline(cin, accNumber);
                }while (accNumber.length() != 6);
            for(int i = 0; i < accountCount; i++)
            {
                if(accounts[i].getAccountNumber() == accNumber)
                {
                    accounts[i].accountDisplay();
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "Account not found." << endl;
            }

            break;

        case 4:

            found = false;
           do {
               cout << "Enter account number: "<<endl;
               getline(cin, accNumber);
           }while (accNumber.length() != 6);
            for(int i = 0; i < accountCount; i++)
            {
                if(accounts[i].getAccountNumber() == accNumber)
                {
                    accounts[i].depositMoney();
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "Account not found." << endl;
            }

            break;

        case 5:

            found = false;
            do {
                cout << "Enter account number: "<<endl;
                getline(cin, accNumber);
            }while (accNumber.length() != 6);
            for(int i = 0; i < accountCount; i++)
            {
                if(accounts[i].getAccountNumber() == accNumber)
                {
                    accounts[i].withdrawMoney();
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "Account not found." << endl;
            }

            break;

        case 6:

            found = false;
            do {
                cout << "Enter account number: "<<endl;
                getline(cin, accNumber);
            }while (accNumber.length() != 6);
            for(int i = 0; i < accountCount; i++)
            {
                if(accounts[i].getAccountNumber() == accNumber)
                {
                    accounts[i].checkBalance();
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "Account not found." << endl;
            }

            break;

        case 0:

            cout << "Thank you for banking with KINEMS!" << endl;
            break;

        default:

            cout << "Invalid option." << endl;
        }

    } while(choice != 0);

    return 0;
}