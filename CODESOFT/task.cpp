#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Task {
    string description;
    bool isCompleted;
    Task(const string& desc) : description(desc), isCompleted(false) {}};
class TodoList {
private:
    vector<Task> tasks;
public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl; }
    void viewTasks() const {
        cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].isCompleted ? "Completed" : "Pending") << endl; } }
    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].isCompleted = true;
            cout << "Task marked as completed: " << tasks[taskIndex].description << endl;
        } else {
            cout << "Invalid task index.\n";  }}
    void removeTask(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex].description << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task index.\n"; }}};
int main() {
    TodoList todoList;
    string taskDescription;
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();  // Move the cin.ignore() outside of the loop
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                todoList.viewTasks();
                size_t completeIndex;
                cout << "Enter task number to mark as completed: ";
                cin >> completeIndex;
                todoList.markTaskCompleted(completeIndex - 1);
                break;
            case 4:
                todoList.viewTasks();
                size_t removeIndex;
                cout << "Enter task number to remove: ";
                cin >> removeIndex;
                todoList.removeTask(removeIndex - 1);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; }
    } while (choice != 0);
    return 0;}
