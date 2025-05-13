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

// Utility function to pause screen
void pause() {
    cout << "\n🔃 Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

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

// Function to delete a task
void deleteTask() {
    int id;
    cout << "🗑️ Enter Task ID to delete: ";
    cin >> id;
    cin.ignore();

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            char confirm;
            cout << "⚠️ Are you sure you want to delete this task? (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                tasks.erase(it);
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
    cout << "        🗂️ TASK MANAGER 3000 🗂️      \n";
    cout << "=====================================\n";
    cout << "Manage your tasks with confidence! 💼\n";
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
        cout << "4️⃣  Delete Task\n";
        cout << "5️⃣  Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createTask();
                pause();
                break;
            case 2:
                displayTasks();
                pause();
                break;
            case 3:
                updateTask();
                pause();
                break;
            case 4:
                deleteTask();
                pause();
                break;
            case 5:
                cout << "👋 Exiting Task Manager. Have a great day!\n";
                break;
            default:
                cout << "⚠️ Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

