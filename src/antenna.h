#ifndef ONBOARD_PROJECTS_ANTENNA_H
#define ONBOARD_PROJECTS_ANTENNA_H

#include <systemc>

#include "interface.h"
#include "logger.h"
#include "defs.h"

using namespace sc_core;
class Antenna:
        public sc_module,
        public Logger,
        public IOInterface{
public:
    sc_port<IOInterface> p_to_switch;
private:
    std::vector<std::vector<short>> rx_buffer[PACKET_TYPES];
    sc_event checkRxBuffer;
public:
    SC_HAS_PROCESS(Antenna);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Antenna";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

    explicit Antenna(const sc_module_name &name);

    void check_receive_buffer();
    void new_data();

    void write_packet(const std::vector<unsigned short> &packet) override;
    void read_packet(const std::vector<unsigned short> &packet) override;
};


#endif //ONBOARD_PROJECTS_CPU_H
