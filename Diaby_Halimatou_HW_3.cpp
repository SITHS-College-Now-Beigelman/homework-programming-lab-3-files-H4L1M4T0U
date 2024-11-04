// Halimatou Diaby_
// Title: Bank Transactions Program (5 Iterations)
// Date: 10/20/2024


// Halimatou Diaby_
// Title: Bank Transactions Program (5 Iterations)
// Date: 10/1/2024




#include <iostream>
using namespace std;

int main() {


    //MY VARIABLESS
        double starting_balance, transaction_amount;
        int num_transactions;
        double total_debits = 0, total_credits = 0;
        string transaction_type;




    // Loop for 5 different runs
    for (int day = 1; day <= 5; ++day) {
        // Declare variables

        
        // fancy header so that my code looks cool 
        cout << "\n----- Day " << day << " Transactions -----\n";
        
        // Get user input for starting balance and number of transactions
        cout << "Enter the starting balance in your account: $";
        cin >> starting_balance;
        cout << "Enter the number of transactions for the day: ";
        cin >> num_transactions;
        
        // Process each transaction
        for (int i = 0; i < num_transactions; ++i) {
            bool valid_input = false; // Track whether the input is valid
            
            // Keep asking for input until it's valid
            while (!valid_input) {
                cout << "Transaction " << i + 1 << " - Enter 'debit' or 'credit': ";
                cin >> transaction_type;
                cout << "Enter the amount: $";
                cin >> transaction_amount;

                if (transaction_type == "debit") {
                    starting_balance -= transaction_amount;
                    total_debits += transaction_amount;
                    valid_input = true; // Input is valid, exit the loop
                } else if (transaction_type == "credit") {
                    starting_balance += transaction_amount;
                    total_credits += transaction_amount;
                    valid_input = true; // Input is valid, exit the loop
                } else {
                    // Invalid input message
                    cout << "Invalid transaction type. Please enter 'debit' or 'credit'.\n";
                }
            }
            
            // Print the balance after each transaction
            cout << "Balance after transaction: $" << starting_balance << endl;
        }
        
        // Final output for each day: total balance, total debits, and total credits
        cout << "Final balance at the end of the day: $" << starting_balance << endl;
        cout << "Total debits: $" << total_debits << endl;
        cout << "Total credits: $" << total_credits << endl;
    }

    return 0;
}

/* 
Sample output for one loop:
Enter the starting balance in your account: $1000
Enter the number of transactions for the day: 3
Transaction 1 - Enter 'debit' or 'credit': debit
Enter the amount: $200
Balance after transaction: $800
Transaction 2 - Enter 'debit' or 'credit': credit
Enter the amount: $150
Balance after transaction: $950
Transaction 3 - Enter 'debit */
