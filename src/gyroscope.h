#ifndef ONBOARD_PROJECTS_GYROSCOPE_H
#define ONBOARD_PROJECTS_GYROSCOPE_H

#include <systemc>
#include <random>

#include "interface.h"
#include "logger.h"

using namespace sc_core;
class Gyroscope:
        public sc_module,
        public IOInterface{
public:
    sc_port<IOInterface> p_to_switch;
private:
    std::random_device rd;
    std::mt19937 mersenne;
    sc_event e_generation_position_data;

public:
    SC_HAS_PROCESS(Gyroscope);
    explicit Gyroscope(const sc_module_name& name);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Gyroscope";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

    void write_packet(const std::vector<unsigned short> &packet) override;
    void read_packet(const std::vector<unsigned short> &packet) override;

    void new_position_data();
};


#endif //ONBOARD_PROJECTS_GYROSCOPE_H
