#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct PullRequest {
    string name;
    string domain;
    string language;
    string date;

    PullRequest(const string& n, const string& d, const string& l)
        : name(n), domain(d), language(l) {
        time_t now = time(nullptr);
        date = asctime(localtime(&now));
    }
};

int main() {
    vector<PullRequest> pullRequests;
    char addAnother;

    do {
        string name, domain, language;

        cout << "Enter the name of the contributor: ";
        cin >> name;

        cout << "Enter the domain of the project: ";
        cin >> domain;

        cout << "Enter the programming language used: ";
        cin >> language;

        pullRequests.push_back(PullRequest(name, domain, language));

        cout << "Pull request added successfully.\n";
        cout << "Do you want to add another pull request? (y/n): ";
        cin >> addAnother;
    } while (addAnother == 'y' || addAnother == 'Y');

    cout << "\nPull Requests:\n";
    for (const PullRequest& pr : pullRequests) {
        cout << "Name: " << pr.name << "\n";
        cout << "Domain: " << pr.domain << "\n";
        cout << "Language: " << pr.language << "\n";
        cout << "Date: " << pr.date << "\n";
        cout << "------------------------\n";
    }

    return 0;
}
