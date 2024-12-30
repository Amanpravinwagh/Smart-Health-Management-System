#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max
#include <string>    // For std::string

using namespace std;

struct Report {
    string patientName;
    float testResult;
};

void generateStatistics(const vector<Report>& reports) {
    if (reports.empty()) {
        cout << "No reports available." << endl;
        return;
    }

    float sum = 0;
    float minVal = reports[0].testResult;
    float maxVal = reports[0].testResult;

    for (const auto& report : reports) {
        sum += report.testResult;
        minVal = std::min(minVal, report.testResult); // Use std::min
        maxVal = std::max(maxVal, report.testResult); // Use std::max
    }

    cout << "\n--- Diagnostic Statistics ---\n";
    cout << "Average: " << sum / reports.size() << endl;
    cout << "Minimum: " << minVal << endl;
    cout << "Maximum: " << maxVal << endl;
}

int main() {
    vector<Report> reports = {{"John", 78.5}, {"Alice", 88.0}, {"Bob", 92.3}};
    generateStatistics(reports);
    return 0;
}

