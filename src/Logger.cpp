#include "../include/Logger.h"

#include <fstream>
#include <ctime>

void Logger::log(string message) {

    ofstream file("data/logs.txt", ios::app);

    time_t now = time(0);

    char* dt = ctime(&now);

    file << "[" << dt << "] "
         << message << endl;

    file.close();
}