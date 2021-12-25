#ifndef ONBOARD_PROJECTS_LOGGER_H
#define ONBOARD_PROJECTS_LOGGER_H

#include <systemc>
#include <iostream>

/**
 * Logger, log all events in other classes,
 * include only one function, wrapper, with logNode
 */
class Logger {
public:
    static auto generate(const std::string& logNode) {
        return [logNode] (const std::string message) {
            const auto time = sc_core::sc_time_stamp().to_string();

            std::cout << "[" << time << "] [" << logNode << "] -> " << message << std::endl;
        };
    }

    /**
     * Convert integer data array to loggable string
     */
    std::string dataToLoggableString(int *data, int size);
};

#endif //ONBOARD_PROJECTS_LOGGER_H