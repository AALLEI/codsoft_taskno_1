#include<iostream>
#include<random>  
using namespace std;

int random_number() {
    random_device rd; // Create a random device
    mt19937 gen(rd()); // Create a Mersenne Twister pseudo-random number generator

    uniform_int_distribution<int> distribution(1, 500); // Create a uniform distribution from 1 to 500

    int r_number = distribution(gen); // Generate a random number within the specified range
    return r_number;
}

void guess(int number) {
    int guess_number;
    cout << "PLZ ENTER YOUR GUESS ";  // Taking guess from player
    cin >> guess_number;
    int count = 0;
    int flag = 0;                     // Flag gives option to user for number show after every five turns
    while (true) {
        cout << endl;
        cout << "                                     # OF GUESSES " << count << endl;
        cout << endl;

        if (flag > 5) {
            cout << " TO SEE NUMBER PLZ ENTER ' X ' AND ' F ' FOR CONTINUE  ";
            char option;
            cin >> option;

            if (option == 'X') {
                cout << " OOPS ! YOU LOST " << endl;
                cout << "NUMBER IS " << number;
                break;
            }
            else {
                cout << "KEEP IT UP " << endl;
                flag = 0;
                continue;
            }
        }

        if (guess_number == number) {
            cout << " AWESOME! YOU DID IT " << endl;                      // Conditions for the check of player input
            break;
        }
        else if (guess_number > number) {
            if (guess_number - number <= 10) {
                cout << "YOUR NUMBER IS SLIGHTLY HIGH ENTER AGAIN " << endl;
            }
            else if (guess_number - number <= 50) {
                cout << "YOUR NUMBER IS MODERATE HIGH ENTER AGAIN " << endl;  // Conditions  check whether the guess nuber is Higher Or not
            }
            else {
                cout << "YOUR NUMBER IS TOO HIGH ENTER AGAIN " << endl;
            }
            cin >> guess_number;
            count++;
            flag++;
        }
        else if (guess_number < number) {
            if (number - guess_number <= 10) {
                cout << "YOUR NUMBER IS SLIGHTLY LOW ENTER AGAIN " << endl;
            }
            else if (number - guess_number <= 50) {                              // Conditions  check whether the guess nuber is Lower Or not
                cout << "YOUR NUMBER IS MODERATE LOW ENTER AGAIN  ";
            }
            else {
                cout << "YOUR NUMBER IS TOO LOW ENTER AGAIN " << endl;
            }
            cin >> guess_number;
            count++;
            flag++;
        }
        system("cls"); // Clear the console screen
    }
}

int main() {
    int no = random_number();
    guess(no);

    return 0;
}
