#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// ─────────────────────────────────────────
//  ANSI Color Codes (macOS/Linux Terminal)
// ─────────────────────────────────────────
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"

#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define CYAN        "\033[36m"

#define BRED        "\033[91m"
#define BGREEN      "\033[92m"
#define BYELLOW     "\033[93m"
#define BBLUE       "\033[94m"
#define BMAGENTA    "\033[95m"
#define BCYAN       "\033[96m"
#define BWHITE      "\033[97m"

#define BG_BLUE     "\033[44m"
#define BG_CYAN     "\033[46m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_RED      "\033[41m"

// ─────────────────────────────────────────
//  Helper: Print a horizontal line
// ─────────────────────────────────────────
void printLine(char ch = '-', int len = 52, const string& color = BWHITE) {
    cout << color;
    for (int i = 0; i < len; i++) cout << ch;
    cout << RESET << "\n";
}

// ─────────────────────────────────────────
//  Helper: Center-print text
// ─────────────────────────────────────────
void printCentered(const string& txt, int width = 52, const string& color = BWHITE) {
    int pad = (width - (int)txt.size()) / 2;
    if (pad < 0) pad = 0;
    cout << color << BOLD;
    for (int i = 0; i < pad; i++) cout << ' ';
    cout << txt << RESET << "\n";
}

// ─────────────────────────────────────────
//  Welcome Banner (ASCII-safe)
// ─────────────────────────────────────────
void showBanner() {
    cout << "\n";
    printLine('=', 52, BCYAN);
    printCentered("* ONLINE FEEDBACK COLLECTION SYSTEM *", 52, BBLUE);
    printCentered("ITM Skills University | B.Tech CSE 2025-29", 52, CYAN);
    printLine('=', 52, BCYAN);
    cout << "\n";
}

// ─────────────────────────────────────────
//  Star Rating (ASCII stars)
// ─────────────────────────────────────────
void printStars(int rating) {
    cout << "  " << BYELLOW;
    for (int i = 1; i <= 5; i++)
        cout << (i <= rating ? "[*]" : "[ ]");
    cout << RESET << "\n";
}

// ─────────────────────────────────────────
//  Progress Bar (ASCII blocks)
// ─────────────────────────────────────────
void printProgressBar(double value, double maxVal = 5.0, int width = 30) {
    int filled = (int)round((value / maxVal) * width);
    cout << "  [" << BGREEN;
    for (int i = 0; i < width; i++)
        cout << (i < filled ? "#" : "-");
    cout << RESET << "] " << BYELLOW << fixed << setprecision(2) << value << " / " << maxVal << RESET << "\n";
}

// ─────────────────────────────────────────
//  Satisfaction Level Logic
// ─────────────────────────────────────────
string getSatisfactionLevel(double avg) {
    if (avg >= 4.5) return "Excellent";
    else if (avg >= 3.5) return "Good";
    else if (avg >= 2.5) return "Average";
    else if (avg >= 1.5) return "Poor";
    else return "Very Poor";
}

void printSatisfactionBadge(const string& level) {
    string color, label;
    if      (level == "Excellent") { color = BG_GREEN;  label = "  [[ EXCELLENT ]]  "; }
    else if (level == "Good")      { color = BG_CYAN;   label = "    [[  GOOD  ]]    "; }
    else if (level == "Average")   { color = BG_YELLOW; label = "  [[ AVERAGE  ]]  "; }
    else if (level == "Poor")      { color = BG_RED;    label = "    [[  POOR  ]]    "; }
    else                           { color = BG_RED;    label = " [[ VERY POOR ]]  "; }

    cout << "\n";
    printLine('-', 52, DIM);
    cout << "  Status  : " << BOLD << color << label << RESET << "\n";
    printLine('-', 52, DIM);
}

// ─────────────────────────────────────────
//  Main Menu
// ─────────────────────────────────────────
void displayMenu() {
    cout << "\n";
    printLine('-', 52, BLUE);
    cout << BOLD << BBLUE << "  MAIN MENU\n" << RESET;
    printLine('-', 52, BLUE);
    cout << "  " << BGREEN   << " [1] " << RESET << " Submit Feedback\n";
    cout << "  " << BYELLOW  << " [2] " << RESET << " View Summary\n";
    cout << "  " << BRED     << " [3] " << RESET << " Exit\n";
    printLine('-', 52, BLUE);
    cout << BCYAN << "  >> Enter your choice: " << RESET;
}

// ─────────────────────────────────────────
//  Submit Feedback
// ─────────────────────────────────────────
void submitFeedback(vector<int>& ratings) {
    cout << "\n";
    printLine('-', 52, BMAGENTA);
    cout << BOLD << BMAGENTA << "  SUBMIT FEEDBACK\n" << RESET;
    printLine('-', 52, BMAGENTA);

    string labels[] = {"", "Very Poor", "Poor", "Average", "Good", "Excellent"};
    string colors[] = {"", BRED, BRED, BYELLOW, BGREEN, BGREEN};

    cout << "\n  " << CYAN << "Rating Guide:\n\n" << RESET;
    for (int i = 1; i <= 5; i++) {
        cout << "  " << colors[i] << " [" << i << "] ";
        for (int j = 1; j <= 5; j++) cout << (j <= i ? "[*]" : "[ ]");
        cout << "  " << labels[i] << RESET << "\n";
    }

    int rating;
    cout << "\n" << BCYAN << "  >> Enter your rating (1-5): " << RESET;
    cin >> rating;

    if (rating < 1 || rating > 5) {
        cout << "\n  " << BRED << " [X] Invalid rating! Please enter a value between 1 and 5.\n" << RESET;
    } else {
        ratings.push_back(rating);
        cout << "\n  " << BGREEN << " [OK] Thank you! Rating [" << rating << "] has been recorded.\n" << RESET;
        cout << "  ";
        printStars(rating);
    }
    cout << "\n";
}

// ─────────────────────────────────────────
//  View Summary
// ─────────────────────────────────────────
void viewSummary(const vector<int>& ratings) {
    cout << "\n";
    printLine('=', 52, BCYAN);
    cout << BOLD << BCYAN << "  FEEDBACK SUMMARY\n" << RESET;
    printLine('=', 52, BCYAN);

    if (ratings.empty()) {
        cout << "\n  " << BYELLOW << " [!] No feedback submitted yet.\n" << RESET << "\n";
        return;
    }

    int total = 0, minR = 5, maxR = 1;
    int freq[6] = {0};
    for (int r : ratings) {
        total += r;
        if (r < minR) minR = r;
        if (r > maxR) maxR = r;
        freq[r]++;
    }

    double avg = (double)total / ratings.size();
    string level = getSatisfactionLevel(avg);

    cout << "\n";
    cout << "  " << BWHITE << "Total Responses : " << RESET << BYELLOW << ratings.size() << RESET << "\n";
    cout << "  " << BWHITE << "Highest Rating  : " << RESET << BGREEN  << maxR << " (stars)\n" << RESET;
    cout << "  " << BWHITE << "Lowest Rating   : " << RESET << BRED    << minR << " (stars)\n" << RESET;
    cout << "\n  " << BWHITE << "Average Rating:\n" << RESET;
    printProgressBar(avg);

    // Distribution chart
    cout << "\n";
    printLine('-', 52, DIM);
    cout << BOLD << BWHITE << "  Rating Distribution:\n\n" << RESET;

    string barColors[] = {"", BRED, BRED, BYELLOW, BGREEN, BGREEN};
    string starStr[]   = {"", "1 star ", "2 stars", "3 stars", "4 stars", "5 stars"};

    for (int i = 5; i >= 1; i--) {
        cout << "  " << barColors[i] << "[" << i << "] " << starStr[i] << " |" << RESET;
        cout << barColors[i];
        int barLen = freq[i] * 3;
        for (int j = 0; j < barLen; j++) cout << "#";
        if (freq[i] == 0) cout << DIM << "-" << RESET;
        cout << RESET << "  (" << freq[i] << ")\n";
    }

    printSatisfactionBadge(level);
    cout << "\n";
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    vector<int> ratings;
    int choice;

    showBanner();

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: submitFeedback(ratings); break;
            case 2: viewSummary(ratings);    break;
            case 3:
                cout << "\n";
                printLine('=', 52, BBLUE);
                printCentered("Thank you for using the Feedback System!", 52, BGREEN);
                printCentered("Goodbye! Have a great day.", 52, BCYAN);
                printLine('=', 52, BBLUE);
                cout << "\n";
                break;
            default:
                cout << "\n  " << BRED << " [X] Invalid choice! Please enter 1, 2, or 3.\n" << RESET;
        }
    } while (choice != 3);

    return 0;
}