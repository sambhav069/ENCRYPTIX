#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string title;      // Title of the task
    bool completed;    // Completion status of the task
};

// Vector to store the list of tasks
vector<Task> tasks;

// Function to add a task to the list
void addTask() {
    string title;
    cout << "Enter the title of the new task: ";
    getline(cin, title);
    tasks.push_back({title, false});
    cout << "Task added successfully!" << endl;
}

// Function to display all tasks in the list
void displayTasks() {
    cout << "Task List:" << endl;
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].title << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskComplete() {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed." << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskIndex;
    cin.ignore(); // Ignore the newline character
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number. Please enter a number between 1 and " << tasks.size() << "." << endl;
    }
}

// Function to delete a task from the list
void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks available to remove." << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the task number to remove: ";
    cin >> taskIndex;
    cin.ignore(); // Ignore the newline character
    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number. Please enter a number between 1 and " << tasks.size() << "." << endl;
    }
}

// Main function to manage the program flow
int main() {
    int choice;
    while (true) {
        cout << "\n=== Task Manager ===" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark a task as completed" << endl;
        cout << "4. Remove a task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskComplete();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting the Task Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    }
}
