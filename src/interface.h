#ifndef ONBOARD_PROJECTS_INTERFACE_H
#define ONBOARD_PROJECTS_INTERFACE_H
#include <systemc>

class IOInterface:
    public sc_core::sc_interface {
public:
    virtual void write_packet(const std::vector<unsigned short> &packet) = 0;
    virtual void read_packet(const std::vector<unsigned short> &packet) = 0;
};
#endif //ONBOARD_PROJECTS_INTERFACE_H
