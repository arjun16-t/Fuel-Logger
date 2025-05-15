#include "FuelLog.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<FuelLog> logs = loadLogsFromFile("data/logs.txt");

    int choice;
    do {
        std::cout << "\n--- Fuel Logger Menu ---\n";
        std::cout << "1. Add New Entry\n2. View Summary\n3. View Logs\n4. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addNewEntry(logs);
                break;
            case 2:
                showSummary(logs);
                break;
            case 3:
                displayLogs(logs);
                break;
        }

    } while (choice != 4);

    saveLogsToFile(logs, "data/logs.txt");
    return 0;
}
