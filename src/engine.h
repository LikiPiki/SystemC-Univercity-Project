#ifndef ONBOARD_PROJECTS_ENGINE_H
#define ONBOARD_PROJECTS_ENGINE_H
#include <systemc>

#include "interface.h"
#include "logger.h"

using namespace sc_core;
class Engine:
        public sc_module,
        public Logger,
        public IOInterface{
public:
    sc_port<IOInterface> p_to_switch;
private:
    std::uint32_t x, y, z;
    std::uint32_t got_x, got_y, got_z;
    sc_event e_change_position;
public:
    SC_HAS_PROCESS(Engine);
    explicit Engine(const sc_module_name& name);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Engine";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

    void write_packet(const std::vector<unsigned short> &packet) override;

    void read_packet(const std::vector<unsigned short> &packet) override;

    void change_position();
};


#endif //ONBOARD_PROJECTS_ENGINE_H
