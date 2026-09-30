#include<bits/stdc++.h>
using namespace std;

//This isn with violating Liskov Substitution Principle (LSP) because all derived classes (SavingsAccount, CurrentAccount, FixedDepositAccount) can be used interchangeably through the base class pointer (Account*). The BankClient class can process transactions on any type of account without needing to know the specific type of account.

// class Account
// {
//   public:
//     virtual void withdraw(double amount) = 0;
//     virtual void deposit(double amount) = 0;
// };

// class SavingsAccount : public Account
// {
//   private:
//     double balance; 
//   public: 
//     SavingsAccount()
//     {
//       balance = 0.0;
//     }

//     void deposit(double amount) override
//     {
//         balance += amount;
//         cout << "Deposited Rs " << amount << " to Savings Account. New balance: Rs " << balance << endl;
//     }

//     void withdraw(double amount) override
//     {
//         if (amount <= balance)
//         {
//             balance -= amount;
//             cout << "Withdrew Rs " << amount << " from Savings Account. New balance: Rs " << balance << endl;
//         }
//         else
//         {
//             cout << "Insufficient funds in Savings Account." << endl;
//         }
//     }

// };

// class CurrentAccount : public Account
// {
//   private:
//     double balance; 
//   public: 
//     CurrentAccount()
//     {
//       balance = 0.0;
//     }

//     void deposit(double amount) override
//     {
//         balance += amount;
//         cout << "Deposited Rs " << amount << " to Current Account. New balance: Rs " << balance << endl;
//     }

//     void withdraw(double amount) override
//     {
//         if (amount <= balance)
//         {
//             balance -= amount;
//             cout << "Withdrew Rs " << amount << " from Current Account. New balance: Rs " << balance << endl;
//         }
//         else
//         {
//             cout << "Insufficient funds in Current Account." << endl;
//         }
//     }

// };

// class FixedDepositAccount : public Account
// {
//   private:
//     double balance; 
//   public: 
//     FixedDepositAccount()
//     {
//       balance = 0.0;
//     }

//     void deposit(double amount) override
//     {
//         balance += amount;
//         cout << "Deposited Rs " << amount << " to Fixed Deposit Account. New balance: Rs " << balance << endl;
//     }

//     void withdraw(double amount) override
//     {
//         throw logic_error("Withdrawals are not allowed from Fixed Deposit Account before maturity.");
//     }

// };

// class BankClient
// {
//   private:
//     vector<Account*> accounts;

//   public:
//     BankClient(vector<Account*> accs){
//       this->accounts = accs;
//     }

//     void processTransactions()
//     {
//         for (Account* account : accounts)
//         {
//             account->deposit(1000.0);
//             try
//             {
//                 account->withdraw(500.0);
//             }
//             catch (const logic_error& e)
//             {
//                 cout << e.what() << endl;
//             }
//         }
//     }

// };

//? Following LSP

class DepositAccount
{
  public:
    virtual void deposit(double amount) = 0;
};

class WithdrawAccount : public DepositAccount
{
  public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawAccount
{
  private:
    double balance;

  public:
    SavingsAccount() : balance(0.0) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Rs " << amount << " to Savings Account. New balance: Rs " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew Rs " << amount << " from Savings Account. New balance: Rs " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Savings Account." << endl;
        }
    }
};


class CurrentAccount : public WithdrawAccount
{
  private:
    double balance;

  public:
    CurrentAccount() : balance(0.0) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Rs " << amount << " to Current Account. New balance: Rs " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew Rs " << amount << " from Current Account. New balance: Rs " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Current Account." << endl;
        }
    }
};

class FixedDepositAccount : public DepositAccount
{
  private:
    double balance;

  public:
    FixedDepositAccount() : balance(0.0) {}

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited Rs " << amount << " to Fixed Deposit Account. New balance: Rs " << balance << endl;
    }

    // Withdrawals are not allowed from Fixed Deposit Account before maturity.
};

class BankClient
{
  private:
    vector<DepositAccount*> accounts;
    vector<WithdrawAccount*> withdrawableAccounts;

  public:
    BankClient(vector<WithdrawAccount*> withdrawableAccs, vector<DepositAccount*> depositAccs)
    {
        this->withdrawableAccounts = withdrawableAccs;
        this->accounts = depositAccs;
    }

    void processTransactions()
    {
        for (WithdrawAccount* account : withdrawableAccounts)
        {
            account->deposit(1000.0);
            account->withdraw(500.0);
        }

        for (DepositAccount* account : accounts)
        {
            account->deposit(1000.0);
        }
    }
};


int main()
{
  vector<WithdrawAccount*> withdrawableAccounts;
  withdrawableAccounts.push_back(new SavingsAccount());
  withdrawableAccounts.push_back(new CurrentAccount());

  vector<DepositAccount*> depositAccounts;  
  depositAccounts.push_back(new FixedDepositAccount());

  BankClient* client = new BankClient(withdrawableAccounts, depositAccounts);
  client->processTransactions();

  return 0;
}

