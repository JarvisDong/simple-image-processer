#include <logging.h>
#include <iostream>

using std::cout;
using std::endl;

void Logger::LogEvent(const char *event) {
    cout << event << endl;
}

void Logger::Finalize() {
    
}
