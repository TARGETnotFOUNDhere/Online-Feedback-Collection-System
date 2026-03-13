# Online-Feedback-Collection-System
⭐ Online Feedback Collection System (C++)

A console-based feedback collection system developed using C++ that allows users to submit ratings and view statistical summaries of collected feedback.

This project demonstrates the use of core C++ programming concepts such as vectors, functions, loops, conditional statements, and formatted terminal output to create an interactive feedback analysis system.

📌 Project Overview

The Online Feedback Collection System is designed to collect and analyze user feedback through a simple terminal interface.

Users can submit ratings between 1 and 5, and the system calculates useful statistics such as:

Total responses

Average rating

Highest rating

Lowest rating

Rating distribution

Satisfaction level

The program also includes visual terminal elements like:

⭐ Star-based ratings
📊 Progress bar for average rating
📈 Rating distribution chart
🎨 Colored terminal UI using ANSI escape codes

🎯 Features

• Interactive menu-driven interface
• Star rating system (1–5 scale)
• Dynamic storage of feedback using vectors
• Average rating progress bar visualization
• Rating distribution chart
• Satisfaction level classification
• Colorful terminal UI using ANSI codes

🧠 Concepts Used

This project demonstrates the following C++ programming concepts:

Vectors (std::vector)

Functions and modular programming

Loops (for, do-while)

Conditional statements (if-else, switch)

Arrays

Input/Output handling

ANSI terminal color formatting

Basic statistical calculations

⚙️ How It Works

1️⃣ Program starts with a welcome banner

2️⃣ A main menu is displayed:

1. Submit Feedback
2. View Summary
3. Exit

3️⃣ User submits a rating between 1 and 5

4️⃣ Ratings are stored in a vector

5️⃣ The system calculates:

Average rating

Highest rating

Lowest rating

Rating distribution

6️⃣ The program displays a visual summary of the collected feedback.

📊 Example Output
Rating Input
Enter your rating (1-5): 4

[*][*][*][*][ ]
Feedback Summary
Total Responses : 6
Highest Rating  : 5
Lowest Rating   : 2

Average Rating
[###########-------------] 3.75 / 5
Rating Distribution
5 stars | ######
4 stars | ####
3 stars | ##
2 stars | #
1 star  | -
Satisfaction Level
Status : [[ GOOD ]]
🗂 Project Structure
online-feedback-system/
│
├── feedback_system.cpp
├── README.md
└── screenshots (optional)
🚀 How to Run
Compile the Program
g++ feedback_system.cpp -o feedback
Run the Program
./feedback
🧩 Future Improvements

This project can be expanded with:

• Database integration (MySQL / SQLite)
• Web interface (HTML + CSS + JavaScript)
• GUI using Qt or C++ frameworks
• User authentication system
• Advanced analytics dashboard

👨‍💻 Author

Lakshya Purohit
