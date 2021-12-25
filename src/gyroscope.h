#ifndef ONBOARD_PROJECTS_GYROSCOPE_H
#define ONBOARD_PROJECTS_GYROSCOPE_H
#include <systemc>
#include "interface.h"
#include <random>

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

    void write_packet(const std::vector<unsigned short> &packet) override;
    void read_packet(const std::vector<unsigned short> &packet) override;

    void new_position_data();
};


#endif //ONBOARD_PROJECTS_GYROSCOPE_H
