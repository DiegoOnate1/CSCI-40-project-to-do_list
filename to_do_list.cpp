#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string desc; // description for task
    bool done; //if task is done true or false
};

int main() {
    vector<Task> tasks; // used to hold the tasks
    int choice; // menu choice
    char ch; // temp character to wipe input

    while (true) { //main loop til user exits
        cout << "\nTo-Do List\n"
                "1) Add Task\n"
                "2) Mark Task Completed\n"
                "3) Show Pending\n"
                "4) Show Completed\n"
                "5) Show All\n"
                "0) Exit\n"
                "Choice: ";
                //reads choice, if not number, rids error and starts again
        if (!(cin >> choice)) {
            // clear bad input
            cin.clear(); // cears error
            while (cin.get(ch) && ch != '\n'); // deletes line
            cout << "Please enter a number (0–5).\n";
            continue; // restarts loop
        }
        // removed the newline so next line works
        while (cin.get(ch) && ch != '\n');
        // deals wit choice
        if (choice == 0) {
            cout << "Goodbye!\n";// exit message
            break;// exit loop and prog
        }
        else if (choice == 1) {// adds task
            cout << "New task: ";
            string desc;
            getline(cin, desc); // reads whole line
            if (!desc.empty()) // check if empty
                tasks.push_back({desc, false}); 
        }
        else if (choice == 2) { // to mark task as done
            cout << "\nPending Tasks:\n"; 
            for (size_t i = 0; i < tasks.size(); ++i) // shows only tasks not done
                if (!tasks[i].done)
                    cout << i+1 << ") " << tasks[i].desc << "\n"; // shows task number and description

            cout << "Task # to mark done: ";
            size_t n;
            if (!(cin >> n)) {
                cin.clear(); // clear error
                while (cin.get(ch) && ch != '\n'); // delete line
                cout << "Invalid number.\n";
                continue; // restarts loop
            }
            while (cin.get(ch) && ch != '\n'); // delete line

            if (n >= 1 && n <= tasks.size())// between 1 and size of tasks
                tasks[n-1].done = true; // mark task as done
            else
                cout << "No such task.\n"; // not in range
        }
        else if (choice >= 3 && choice <= 5) { //shows tasks on users fiter: pending,compete, or all
            bool showPending   = (choice == 3);
            bool showCompleted = (choice == 4);
            bool showAll       = (choice == 5);
            cout << "\n"
                 << (showAll       ? "All Tasks:\n"
                    : showPending   ? "Pending Tasks:\n"
                                    : "Completed Tasks:\n");
            for (size_t i = 0; i < tasks.size(); ++i) {// loop through tasks shows to choice
                bool done = tasks[i].done;
                if (showAll
                 || (showPending   && !done)
                 || (showCompleted &&  done))
                {
                    cout << i+1 << ") ["
                         << (done ? 'X' : ' ')
                         << "] " << tasks[i].desc << "\n";
                }
            }
        }
        else {
            cout << "Please choose 0–5.\n"; // if choice not in range
        }
    }

    return 0;
}