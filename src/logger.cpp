#include "logger.h"

/**
 * Convert integer data array to loggable string
 */
std::string Logger::dataToLoggableString(int *data, int size) {
    const int lastIndex = size - 1;
    std::string result = "(";

    for (int i = 0; i < size; i++) {
        result += std::to_string(data[i]);
        std::cout << "size" << size - 2 << " " << i << std::endl;
        if (i != lastIndex) {
            result += ", ";
        }
    }

    result += ")";

    return result;
}