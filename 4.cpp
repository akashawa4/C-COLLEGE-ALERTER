#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// User structure
struct User {
    string username;
    string email;
    string password;
    string role;
};

// Election system
struct Candidate {
    string name;
    int votes;
};

// Simulating the email system (Basic implementation for health and leave notifications)
void sendEmailNotification(string recipient, string message) {
    cout << "Email sent to " << recipient << ": " << message << endl;
}

// Class to represent the entire college system
class CollegeSystem {
private:
    map<string, User> users;
    vector<Candidate> electionCandidates;
    map<string, string> applications;
    vector<string> cheatingRecords;
    vector<string> complaints;

public:
    // Simulate user authentication
    bool authenticateUser(const string& username, const string& password) {
        if (users.find(username) != users.end() && users[username].password == password) {
            return true;
        }
        return false;
    }

    // Student Election System
    void electionSystem() {
        cout << "\n--- Election System ---\n";
        cout << "Candidates:\n";
        for (int i = 0; i < electionCandidates.size(); ++i) {
            cout << i + 1 << ". " << electionCandidates[i].name << " - Votes: " << electionCandidates[i].votes << endl;
        }

        int voteChoice;
        cout << "Enter the candidate number to vote: ";
        cin >> voteChoice;
        if (voteChoice > 0 && voteChoice <= electionCandidates.size()) {
            electionCandidates[voteChoice - 1].votes++;
            cout << "Vote casted successfully!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    }

    // Automated Health & Leave Notification
    void healthAndLeaveNotification(string studentName, bool isSick) {
        string message = isSick ? "Student is reported sick. Please notify the class coordinator."
                                : "Student has left campus. Notify parents for safety tracking.";
        sendEmailNotification(studentName + "@college.edu", message);
    }

    // Campus Facility Booking System
    void campusBookingSystem() {
        cout << "\n--- Campus Facility Booking ---\n";
        cout << "1. Tennis Court\n2. Auditorium\n";
        int choice;
        cout << "Choose facility to book (1 or 2): ";
        cin >> choice;
        if (choice == 1) {
            cout << "Booking Tennis Court...\n";
        } else if (choice == 2) {
            cout << "Booking Auditorium...\n";
        } else {
            cout << "Invalid choice.\n";
        }
    }

    // Transparent Application & Approval System
    void applicationSystem() {
        cout << "\n--- Application System ---\n";
        string applicationName;
        cout << "Enter application name: ";
        cin >> applicationName;
        applications[applicationName] = "Pending";
        cout << "Application '" << applicationName << "' submitted successfully.\n";
    }

    void manageApplications() {
        cout << "\n--- Managing Applications ---\n";
        for (const auto& app : applications) {
            cout << app.first << " - Status: " << app.second << endl;
        }
    }

    // Academic Integrity & Cheating Record System
    void recordCheating(string studentName, string reason) {
        cheatingRecords.push_back("Student: " + studentName + " - Reason: " + reason);
    }

    void viewCheatingRecords() {
        cout << "\n--- Cheating Records ---\n";
        for (const string& record : cheatingRecords) {
            cout << record << endl;
        }
    }

    // Anonymous Complaint System
    void complaintSystem() {
        string complaint;
        cout << "Enter your complaint: ";
        cin.ignore();
        getline(cin, complaint);
        complaints.push_back(complaint);
        cout << "Complaint submitted successfully (Anonymous).\n";
    }

    void viewComplaints() {
        cout << "\n--- Complaints ---\n";
        for (const string& complaint : complaints) {
            cout << complaint << endl;
        }
    }

    // Transparent College Budget & Sponsorship Tracking
    void budgetTrackingSystem() {
        string sponsorship;
        cout << "\n--- Budget Tracking System ---\n";
        cout << "Enter sponsorship details: ";
        cin >> sponsorship;
        cout << "Sponsorship '" << sponsorship << "' added.\n";
    }

    // Restricted Access for College Members Only
    void restrictedAccess(string email, string password) {
        if (email.substr(email.find("@") + 1) == "college.edu" && authenticateUser(email, password)) {
            cout << "Access granted.\n";
        } else {
            cout << "Access denied. Please use a valid college email ID.\n";
        }
    }

    // Register a new user
    void registerUser(string username, string email, string password, string role) {
        User newUser = {username, email, password, role};
        users[username] = newUser;
        cout << "User registered successfully!\n";
    }

    // Admin actions to manage the system
    void adminActions() {
        int action;
        do {
            cout << "\nAdmin Actions:\n";
            cout << "1. Manage Election\n2. Manage Applications\n3. View Cheating Records\n4. View Complaints\n5. Track Budget\n6. Exit\n";
            cout << "Choose an action: ";
            cin >> action;
            switch (action) {
                case 1:
                    electionSystem();
                    break;
                case 2:
                    applicationSystem();
                    break;
                case 3:
                    viewCheatingRecords();
                    break;
                case 4:
                    viewComplaints();
                    break;
                case 5:
                    budgetTrackingSystem();
                    break;
                case 6:
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (action != 6);
    }

    // Initialize election candidates
    void initElection() {
        electionCandidates.push_back({"John Doe", 0});
        electionCandidates.push_back({"Jane Smith", 0});
    }
};

int main() {
    CollegeSystem system;

    // Register an admin user
    system.registerUser("admin", "admin@college.edu", "admin123", "Admin");

    // Simulate restricted access
    string email, password;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;
    system.restrictedAccess(email, password);

    // Initialize election
    system.initElection();

    // Simulate admin actions
    system.adminActions();

    return 0;
}
