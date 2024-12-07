//Amanda Beiglman 
// Diaby Halimatou 
//HW 3 Part One 2 and 3



#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // File names
    const string inputFileName = "transactions.txt";
    const string outputFileName = "bank_statement.txt";

    // File streams
    ifstream infile(inputFileName);
    ofstream outfile(outputFileName);

    if (!infile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!outfile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    // Variables
    double startingBalance, balance;
    char transactionType;
    double transactionAmount;
    int withdrawalCount = 0, depositCount = 0;
    double totalWithdrawals = 0.0, totalDeposits = 0.0;

    // Read starting balance
    infile >> startingBalance;
    balance = startingBalance;

    // Output headers to file
    outfile << fixed << setprecision(2);
    outfile << "STARTING BALANCE: $" << startingBalance << endl << endl;
    outfile << "TYPE......AMOUNT....................BALANCE" << endl;

    // Read and process transactions
    while (infile >> transactionType >> transactionAmount) {
        if (transactionType == 'W' || transactionType == 'w') {
            balance -= transactionAmount;
            totalWithdrawals += transactionAmount;
            withdrawalCount++;
        } else if (transactionType == 'D' || transactionType == 'd') {
            balance += transactionAmount;
            totalDeposits += transactionAmount;
            depositCount++;
        }

        // Write transaction details to output file
        outfile << transactionType << "........." << setw(8) << transactionAmount
                << "........................" << setw(8) << balance << endl;
    }

    // Final summary
    outfile << endl;
    outfile << "ENDING BALANCE: $" << balance << endl;
    outfile << "TOTAL WITHDRAWALS: $" << totalWithdrawals << endl;
    outfile << "TOTAL DEPOSITS: $" << totalDeposits << endl;
    outfile << "NUMBER OF WITHDRAWALS: " << withdrawalCount << endl;
    outfile << "NUMBER OF DEPOSITS: " << depositCount << endl;

    // Close files
    infile.close();
    outfile.close();

    // Print completion message
    cout << "Bank statement has been written to " << outputFileName << endl;

    return 0;
}

/* Sample Output 
STARTING BALANCE: $5000.00

TYPE......AMOUNT....................BALANCE
W.........  200.00........................ 4800.00
W.........  800.00........................ 4000.00
W.........   40.00........................ 3960.00
D.........   90.00........................ 4050.00
D.........  100.00........................ 4150.00
D......... 1000.00........................ 5150.00
W.........   20.00........................ 5130.00

ENDING BALANCE: $5130.00
TOTAL WITHDRAWALS: $1060.00
TOTAL DEPOSITS: $1190.00
NUMBER OF WITHDRAWALS: 4
NUMBER OF DEPOSITS: 3

*/
