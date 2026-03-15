#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Print horizontal line
void printLine(char ch = '-', int len = 52) {
    for (int i = 0; i < len; i++) cout << ch;
    cout << endl;
}

// Center text
void printCentered(string text, int width = 52) {
    int padding = (width - text.length()) / 2;
    if (padding < 0) padding = 0;

    for (int i = 0; i < padding; i++) cout << " ";
    cout << text << endl;
}

// Banner
void showBanner() {
    cout << endl;
    printLine('=');
    printCentered("ONLINE FEEDBACK COLLECTION SYSTEM");
    printCentered("ITM Skills University | B.Tech CSE");
    printLine('=');
    cout << endl;
}

// Star display
void printStars(int rating) {
    cout << "  ";
    for (int i = 1; i <= 5; i++) {
        if (i <= rating)
            cout << "[*]";
        else
            cout << "[ ]";
    }
    cout << endl;
}

// Progress bar
void printProgressBar(double value, double maxVal = 5.0, int width = 30) {

    int filled = round((value / maxVal) * width);

    cout << "  [";

    for (int i = 0; i < width; i++) {
        if (i < filled)
            cout << "#";
        else
            cout << "-";
    }

    cout << "] " << fixed << setprecision(2) << value << " / " << maxVal << endl;
}

// Satisfaction level
string getSatisfactionLevel(double avg) {

    if (avg >= 4.5)
        return "Excellent";
    else if (avg >= 3.5)
        return "Good";
    else if (avg >= 2.5)
        return "Average";
    else if (avg >= 1.5)
        return "Poor";
    else
        return "Very Poor";
}

// Print satisfaction
void printSatisfactionBadge(string level) {
    cout << endl;
    printLine();
    cout << "Status : " << level << endl;
    printLine();
}

// Menu
void displayMenu() {

    cout << endl;
    printLine();

    cout << "MAIN MENU" << endl;

    printLine();

    cout << "1. Submit Feedback" << endl;
    cout << "2. View Summary" << endl;
    cout << "3. Exit" << endl;

    printLine();

    cout << "Enter your choice: ";
}

// Submit feedback
void submitFeedback(vector<int>& ratings) {

    cout << endl;
    printLine();
    cout << "SUBMIT FEEDBACK" << endl;
    printLine();

    cout << endl;
    cout << "Rating Guide:" << endl << endl;

    string labels[] = {"", "Very Poor", "Poor", "Average", "Good", "Excellent"};

    for (int i = 1; i <= 5; i++) {

        cout << i << " ";

        for (int j = 1; j <= 5; j++) {

            if (j <= i)
                cout << "[*]";
            else
                cout << "[ ]";
        }

        cout << " " << labels[i] << endl;
    }

    int rating;

    cout << endl << "Enter your rating (1-5): ";
    cin >> rating;

    if (rating < 1 || rating > 5) {
        cout << "Invalid rating. Enter between 1 and 5." << endl;
    }
    else {

        ratings.push_back(rating);

        cout << "Thank you! Rating recorded." << endl;

        printStars(rating);
    }

    cout << endl;
}

// View summary
void viewSummary(vector<int> ratings) {

    cout << endl;

    printLine('=');
    cout << "FEEDBACK SUMMARY" << endl;
    printLine('=');

    if (ratings.empty()) {
        cout << endl << "No feedback submitted yet." << endl;
        return;
    }

    int total = 0;
    int minR = 5;
    int maxR = 1;

    int freq[6] = {0};

    for (int r : ratings) {

        total += r;

        if (r < minR)
            minR = r;

        if (r > maxR)
            maxR = r;

        freq[r]++;
    }

    double avg = (double) total / ratings.size();

    cout << endl;
    cout << "Total Responses : " << ratings.size() << endl;
    cout << "Highest Rating  : " << maxR << endl;
    cout << "Lowest Rating   : " << minR << endl;

    cout << endl << "Average Rating:" << endl;

    printProgressBar(avg);

    cout << endl;
    cout << "Rating Distribution:" << endl << endl;

    for (int i = 5; i >= 1; i--) {

        cout << i << " star | ";

        int bar = freq[i] * 3;

        for (int j = 0; j < bar; j++)
            cout << "#";

        if (freq[i] == 0)
            cout << "-";

        cout << " (" << freq[i] << ")" << endl;
    }

    string level = getSatisfactionLevel(avg);

    printSatisfactionBadge(level);
}

// Main
int main() {

    vector<int> ratings;

    int choice;

    showBanner();

    do {

        displayMenu();

        cin >> choice;

        switch (choice) {

            case 1:
                submitFeedback(ratings);
                break;

            case 2:
                viewSummary(ratings);
                break;

            case 3:
                cout << endl;
                printLine('=');
                printCentered("Thank you for using the Feedback System!");
                printCentered("Goodbye!");
                printLine('=');
                cout << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
