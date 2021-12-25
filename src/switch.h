#ifndef ONBOARD_PROJECTS_SWITCH_H
#define ONBOARD_PROJECTS_SWITCH_H

#include <systemc>

#include "interface.h"
#include "logger.h"

using namespace sc_core;

class SwitchModule:
        public sc_module,
        public Logger,
        public IOInterface{
public:
    sc_port<IOInterface> p_to_camera;
    sc_port<IOInterface> p_to_cpu;
    sc_port<IOInterface> p_to_gyroscope;
    sc_port<IOInterface> p_to_engine;
    sc_port<IOInterface> p_to_gelio;
    sc_port<IOInterface> p_to_antenna;
private:
    std::vector<std::vector<short>> routing_table;
public:
    SC_HAS_PROCESS(SwitchModule);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Switch";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

    explicit SwitchModule(const sc_module_name& name);

    void write_packet(const std::vector<unsigned short> &packet) override;

    void read_packet(const std::vector<unsigned short> &packet) override;

};


#endif //ONBOARD_PROJECTS_SWITCH_H
