#include <iostream>
#include <map>
using namespace std;

struct PatientNode {
    string name;
    int age;
    string disease;
};

void displayPatients(const map<int, PatientNode>& patients) {
    cout << "\n--- Patient Records ---\n";
    for (const auto& entry : patients) {
        cout << "ID: " << entry.first << "\nName: " << entry.second.name << ", Age: " << entry.second.age << ", Disease: " << entry.second.disease << "\n";
    }
}

int main() {
    map<int, PatientNode> patients;
    patients[1] = {"John", 30, "Flu"};
    patients[2] = {"Alice", 25, "Cold"};
    patients[3] = {"Bob", 40, "Diabetes"};

    displayPatients(patients);
    return 0;
}

