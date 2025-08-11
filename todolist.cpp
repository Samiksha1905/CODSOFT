#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

void showMenu() {
    cout << "\n===== TO-DO LIST MANAGER =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

void addTask(string tasks[], int& taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!\n";
        return;
    }
    cout << "Enter task description: ";
    cin.ignore(); 
    getline(cin, tasks[taskCount]);
    taskCount++;
    cout << " Task added successfully!\n";
}

void viewTasks(string tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << " No tasks to show.\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

void deleteTask(string tasks[], int& taskCount) {
    if (taskCount == 0) {
        cout << " No tasks to delete.\n";
        return;
    }
    viewTasks(tasks, taskCount);
    cout << "Enter task number to delete: ";
    int index;
    cin >> index;
    if (index < 1 || index > taskCount) {
        cout << "Invalid task number.\n";
    } else {
        for (int i = index - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1]; 
        }
        taskCount--;
        cout << "Task deleted successfully!\n";
    }
}

int main() {
    string tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks, taskCount); break;
            case 2: viewTasks(tasks, taskCount); break;
            case 3: deleteTask(tasks, taskCount); break;
            case 4: cout << " Exiting... Stay organized!\n"; break;
            default: cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}