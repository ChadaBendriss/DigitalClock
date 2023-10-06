#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

int main() {
    while (true) {
        // Get the current time
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Convert to local time
        struct tm *localTime;
        localTime = std::localtime(&currentTime);

        // Determine AM or PM
        std::string meridiem = (localTime->tm_hour >= 12) ? "PM" : "AM";

        // Convert 24-hour format to 12-hour format
        int hour12 = localTime->tm_hour % 12;
        if (hour12 == 0) hour12 = 12;

        // Clear screen and print the time
        std::system("cls");  // Clear screen on Windows. Use "clear" on Linux.
        std::cout << "Digital Dashboard Local Time\n";
        std::cout << "_________________________________\n\n";
        std::cout << "| " 
                  << hour12 << " : "
                  << (localTime->tm_min < 10 ? "0" : "") << localTime->tm_min << " : "
                  << (localTime->tm_sec < 10 ? "0" : "") << localTime->tm_sec << " "
                  << meridiem << " |\n";
        std::cout << "|________________________________|\n";

        // Wait for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
