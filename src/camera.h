#ifndef ONBOARD_PROJECTS_CAMERA_H
#define ONBOARD_PROJECTS_CAMERA_H

#include <systemc>

#include "interface.h"
#include "logger.h"

using namespace sc_core;
class camera:
        public sc_module,
        public Logger,
        public IOInterface{
public:
    sc_port<IOInterface> p_to_switch;
public:
    SC_HAS_PROCESS(camera);
    explicit camera(const sc_module_name& name);

    /**
     * Use logabble fields from Logger class
     */
    static inline const std::string moduleName = "Camera";

    static inline std::function<void (const std::string&)> log = Logger::generate(moduleName);
    static inline std::function<void (
        const std::string proc,
        const std::string message)> procLog = Logger::generateLogWithProcess(moduleName);

    void write_packet(const std::vector<unsigned short> &packet) override;
    void read_packet(const std::vector<unsigned short> &packet) override;
};


#endif //ONBOARD_PROJECTS_CAMERA_H
