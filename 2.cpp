#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// User structure
struct User {
    string username;
    string password;
    string role;
    string phoneNumber;
    string staffRole;
    string prn;
};

// College Staff with admin privileges
class CollegeStaff {
public:
    vector<User> students;
    vector<User> teachers;
    vector<User> staff;
    vector<User> admins;
    map<string, string> credentials;
    
    CollegeStaff() {
        // Predefined admin credentials
        credentials["AkashAw4"] = "0147";
    }
    
    void registerUser(const string& username, const string& password, int roleChoice, const string& phoneNumber, const string& staffRole, const string& prn, const string& accessRole) {
        if (accessRole != "Admin") {
            cout << "Access Denied! Only admins can register users." << endl;
            return;
        }
        
        string role;
        switch (roleChoice) {
            case 1: role = "Student"; break;
            case 2: role = "Teacher"; break;
            case 3: role = "College Staff"; break;
            default: cout << "Invalid choice! Try again." << endl; return;
        }
        
        User newUser = {username, password, role, phoneNumber, staffRole, prn};
        credentials[username] = password;
        
        if (role == "Student") {
            students.push_back(newUser);
        } else if (role == "Teacher") {
            teachers.push_back(newUser);
        } else if (role == "College Staff") {
            staff.push_back(newUser);
        }
    }
    
    bool authenticateUser(const string& username, const string& password) {
        return credentials.find(username) != credentials.end() && credentials[username] == password;
    }
    
    void displayChoices(const string& role) {
        cout << "Select an option:\n";
        if (role == "Student") {
            cout << "1. Event\n2. Club\n3. Return to Role Selection\n";
        } else if (role == "Teacher") {
            cout << "1. Class\n2. Meeting\n3. Return to Role Selection\n";
        } else if (role == "College Staff") {
            cout << "1. Driver\n2. Peon\n3. Cleaner\n4. Security\n5. Lab Assistant\n6. Accountant\n7. Librarian\n8. Technician\n9. Clerk\n10. Return to Role Selection\n";
        }
    }
    
    void manageData() {
        cout << "\n--- Registered Users ---\n";
        cout << "Students: " << students.size() << "\nTeachers: " << teachers.size() << "\nCollege Staff: " << staff.size() << "\nAdmins: " << admins.size() << "\n";
    }
};

int main() {
    CollegeStaff admin;
    int choice;
    string role, username, password;
    
    while (true) {
        cout << "Choose your role by entering a number:\n1. Student\n2. Teacher\n3. College Staff\n4. Admin\n5. Exit\nEnter your choice: ";
        cin >> choice;
        
        if (choice == 5) break;
        
        switch (choice) {
            case 1: role = "Student"; break;
            case 2: role = "Teacher"; break;
            case 3: role = "College Staff"; break;
            case 4: role = "Admin"; break;
            default: cout << "Invalid choice! Try again.\n"; continue;
        }
        
        cout << "Enter Username or PRN: "; cin >> username;
        cout << "Enter Password: "; cin >> password;
        
        if (!admin.authenticateUser(username, password)) {
            cout << "Authentication failed! Try again.\n";
            continue;
        }
        
        cout << "Authentication successful! Role: " << role << "\n";
        
        if (role == "Admin") {
            while (true) {
                cout << "\nAdmin Options:\n1. Register User\n2. Manage Data\n3. Return to Role Selection\nEnter your choice: ";
                cin >> choice;
                
                if (choice == 3) break;
                if (choice == 2) {
                    admin.manageData();
                } else if (choice == 1) {
                    string newUser, newPass, phone, staffRole = "N/A", prn = "N/A";
                    int newRoleChoice;
                    cout << "Enter New Username: "; cin >> newUser;
                    cout << "Enter New Password: "; cin >> newPass;
                    cout << "Choose Role by Entering a Number:\n1. Student\n2. Teacher\n3. College Staff\nEnter your choice: ";
                    cin >> newRoleChoice;
                    cout << "Enter Phone Number: "; cin >> phone;
                    
                    if (newRoleChoice == 1) {
                        cout << "Enter PRN: "; cin >> prn;
                    } else if (newRoleChoice == 3) {
                        cout << "Choose College Staff Role:\n1. Driver\n2. Peon\n3. Cleaner\n4. Security\n5. Lab Assistant\n6. Accountant\n7. Librarian\n8. Technician\n9. Clerk\nEnter your choice: ";
                        int staffChoice;
                        cin >> staffChoice;
                        string staffRoles[] = {"Driver", "Peon", "Cleaner", "Security", "Lab Assistant", "Accountant", "Librarian", "Technician", "Clerk"};
                        if (staffChoice >= 1 && staffChoice <= 9) {
                            staffRole = staffRoles[staffChoice - 1];
                        } else {
                            cout << "Invalid choice! Assigning default role.\n";
                        }
                    }
                    
                    admin.registerUser(newUser, newPass, newRoleChoice, phone, staffRole, prn, "Admin");
                } else {
                    cout << "Invalid choice! Try again.\n";
                }
            }
        } else {
            while (true) {
                admin.displayChoices(role);
                cout << "Enter your choice: ";
                cin >> choice;
                
                if ((role == "Student" && choice == 3) || (role == "Teacher" && choice == 3) || (role == "College Staff" && choice == 10)) {
                    break; // Return to role selection
                }
                cout << "Action performed successfully!\n";
            }
        }
    }
    return 0;
}
