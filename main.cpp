#include <iostream>
#include <vector>

using namespace std;

struct Task {
    int id;
    char title[100];
    bool completed;
};

int main() {
    vector<Task> tasks;
    int choice = 0;

    while (choice != 5) {
        cout << "\n=== TASK TRACKER ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Task t;
            t.id = tasks.size() + 1;
            t.completed = false;

            cout << "Enter task title: ";
            cin.get(); 
            cin.get(t.title, 100);

            tasks.push_back(t);
            cout << "Task added successfully!\n";

        } else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks found.\n";
            } else {
                cout << "\n--- YOUR TASKS ---\n";
                for (size_t i = 0; i < tasks.size(); i++) {
                    cout << tasks[i].id << ". " << tasks[i].title;
                    if (tasks[i].completed) {
                        cout << " [DONE]\n";
                    } else {
                        cout << " [PENDING]\n";
                    }
                }
            }

        } else if (choice == 3) {
            if (tasks.empty()) {
                cout << "No tasks available to complete.\n";
            } else {
                int id;
                cout << "Enter task ID to mark complete: ";
                cin >> id;

                bool found = false;
                for (size_t i = 0; i < tasks.size(); i++) {
                    if (tasks[i].id == id) {
                        tasks[i].completed = true;
                        found = true;
                        cout << "Task marked as completed!\n";
                        break;
                    }
                }
                if (!found) {
                    cout << "Invalid Task ID!\n";
                }
            }

        } else if (choice == 4) {
            if (tasks.empty()) {
                cout << "No tasks available to delete.\n";
            } else {
                int id;
                cout << "Enter task ID to delete: ";
                cin >> id;

                bool found = false;
                for (size_t i = 0; i < tasks.size(); i++) {
                    if (tasks[i].id == id) {
                        tasks.erase(tasks.begin() + i);
                        found = true;
                        cout << "Task deleted successfully!\n";

                        for (size_t j = 0; j < tasks.size(); j++) {
                            tasks[j].id = j + 1;
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "Invalid Task ID!\n";
                }
            }

        } else if (choice == 5) {
            cout << "Exiting program. Goodbye!\n";
        } else {
            cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
