#ifndef ONBOARD_PROJECTS_ENGINE_H
#define ONBOARD_PROJECTS_ENGINE_H
#include <systemc>
#include "interface.h"

using namespace sc_core;
class Engine:
        public sc_module,
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

    void write_packet(const std::vector<unsigned short> &packet) override;

    void read_packet(const std::vector<unsigned short> &packet) override;

    void change_position();
};


#endif //ONBOARD_PROJECTS_ENGINE_H
