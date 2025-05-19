#include "../include/Logger.h"
#include "../include/Utils.h"
#include <iostream>
#include <limits>

void showMenu() {
    clearConsole();
    std::cout << "==== ALL IN ONE FUEL LOGGER ====\n";
    std::cout << "1| Add New Log\n";
    std::cout << "2| View All Logs\n";
    std::cout << "3| Show Total Stats\n";
    std::cout << "4| Best/Worst Mileage\n";
    std::cout << "0| Exit\n";
    std::cout << "================================\n";
    std::cout << "Enter your choice: ";
}

void handleAddLog() {
    clearConsole();
    float fuel;
    long odometer;

    int choice;
    std::cout << "1| Add using Rupees\n";
    std::cout << "2| Add using Fuel_Litres\n";
    std::cin >> choice;

    if (choice == 1) {
        float rupees;
        std::cout << "Enter using Rupees (INR): ";
        std::cin >> rupees;
        fuel = convertToLiters(rupees);

        std::cout << "Enter odometer reading (km): ";
        std::cin >> odometer;

    } else if (choice == 2) {
        std::cout << "Enter fuel used (liters): ";
        std::cin >> fuel;

        std::cout << "Enter odometer reading (km): ";
        std::cin >> odometer;
    } else {
        std::cout << "Invalid input. Please choose 1 or 2.\n";
        pauseAndWait();
        return;
    }

    try {
        addLog(fuel, odometer);
        std::cout << "\nLog added Successfully\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    pauseAndWait();
}

void handleViewLogs() {
    clearConsole();
    auto logs = viewLogs();
    if (logs.empty()) {
        std::cout << "No logs found.\n";
    } else {
        printLogHeader(std::cout);
        for (const auto& log : logs) {
            std::cout << parseRow(log) << "\n";
        }
    }
    pauseAndWait();
}

void handleStats() {
    clearConsole();
    std::cout << "==== Total Stats ====\n";
    std::cout << "Total Logs     : " << getTotalLogs() << "\n";
    std::cout << "Total Odometer : " << getTotalOdo() << " km\n";
    std::cout << "Total Fuel     : " << getTotalFuel() << " L\n";
    std::cout << "Average Mileage: " << getTotalAvg() << " km/l\n";
    pauseAndWait();
}

void handleMileageInfo() {
    clearConsole();
    auto info = getMileInfo();
    if (info.empty() || info[0].empty()) {
        std::cout << "Not enough logs to compute mileage info.\n";
    } else {
        std::cout << "=== Best Mileage ===\n";
        printLogHeader(std::cout);
        std::cout << parseRow(info[0]) << "\n";

        std::cout << "\n=== Worst Mileage ===\n";
        printLogHeader(std::cout);
        std::cout << parseRow(info[1]) << "\n";
    }
    pauseAndWait();
}

int main() {
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            pauseAndWait();
            continue;
        }

        switch (choice) {
            case 1: handleAddLog(); break;
            case 2: handleViewLogs(); pauseAndWait(); break;
            case 3: handleStats(); pauseAndWait(); break;
            case 4: handleMileageInfo(); pauseAndWait(); break;
            case 0: std::cout << "Exiting...\n"; return 0;
            default: std::cout << "Invalid choice!\n"; pauseAndWait(); break;
        }
    }

    return 0;
}
