#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Task structure
struct Task {
    int id;
    string title;
    string description;
};

// Global variables
vector<Task> tasks;
int nextId = 1;


// Function to create a task
void createTask() {
    Task newTask;
    newTask.id = nextId++;

    cin.ignore(); // Clear input buffer
    cout << "📝 Enter Task Title: ";
    getline(cin, newTask.title);

    cout << "📄 Enter Task Description: ";
    getline(cin, newTask.description);

    tasks.push_back(newTask);
    cout << "✅ Task created successfully!\n";
}

// Function to display all tasks
void displayTasks() {
    if (tasks.empty()) {
        cout << "⚠️  No tasks found.\n";
        return;
    }

    cout << "\n📋 Your Tasks:\n";
    for (const auto& task : tasks) {
        cout << "-----------------------------\n";
        cout << "🔢 ID: " << task.id << "\n";
        cout << "📝 Title: " << task.title << "\n";
        cout << "📄 Description: " << task.description << "\n";
    }
    cout << "-----------------------------\n";
}

// Function to update a task
void updateTask() {
    int id;
    cout << "✏️ Enter Task ID to update: ";
    cin >> id;
    cin.ignore();

    for (auto& task : tasks) {
        if (task.id == id) {
            char confirm;
            cout << "⚠️ Are you sure you want to update this task? (y/n): ";
            cin >> confirm;
            cin.ignore();

            if (confirm == 'y' || confirm == 'Y') {
                cout << "📝 New Title: ";
                getline(cin, task.title);
                cout << "📄 New Description: ";
                getline(cin, task.description);
                cout << "✅ Task updated successfully!\n";
            } else {
                cout << "❌ Update cancelled.\n";
            }
            return;
        }
    }

    cout << "❌ Task with ID " << id << " not found.\n";
}

// Function to search a task
void searchTask() {
    string title;
    cout << "📰 Enter the title of task to be searched: ";
    cin >> title;
    cin.ignore();

    bool found = false;
    for (auto& task : tasks) {
        if (task.title == title) {
            cout << "-----------------------------\n";
            cout << "🔢 ID: " << task.id << "\n";
            cout << "📝 Title: " << task.title << "\n";
            cout << "📄 Description: " << task.description << "\n";
            cout << "-----------------------------\n";
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "❌ Task titled \"" << title << "\" not found.\n";
    }
}

// Function to delete a task
void deleteTask() {
    int id;
    cout << "🗑️ Enter Task ID to delete: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            char confirm;
            cout << "⚠️ Are you sure you want to delete this task? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                tasks.erase(tasks.begin() + i);  
                cout << "🗑️ Task deleted successfully!\n";
            } else {
                cout << "❌ Deletion cancelled.\n";
            }
            return;
        }
    }

    cout << "❌ Task with ID " << id << " not found.\n";
}


// Welcome banner
void showWelcome() {
    cout << "=====================================\n";
    cout << "        📚️ TASK MANAGER 📚️      \n";
    cout << "=====================================\n";
    cout << "Efficiently manage your tasks and streamline your workflow.\n This Task Manager allows you to create, view, update, and delete tasks with ease. Designed to support productivity and clarity in task tracking. 💼\n";
}

// Main function
int main() {
    int choice;
    showWelcome();

    do {
        cout << "\n🔸 MENU 🔸\n";
        cout << "1️⃣  Create Task\n";
        cout << "2️⃣  View Tasks\n";
        cout << "3️⃣  Update Task\n";
        cout << "4️⃣  Search Task\n";
        cout << "5️⃣  Delete Task\n";
        cout << "6️⃣ Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                searchTask();
                break;
            case 5:
                deleteTask();
                break;
            case 6:
                cout << "👋 Exiting Task Manager. Have a great day!\n";
                break;
            default:
                cout << "⚠️ Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
