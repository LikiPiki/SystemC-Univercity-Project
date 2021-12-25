#ifndef ONBOARD_PROJECTS_GELIO_H
#define ONBOARD_PROJECTS_GELIO_H

#include <systemc>
#include "interface.h"
#include "defs.h"

using namespace sc_core;
class Gelio:
    public sc_module,
    public IOInterface{

public:
    sc_port<IOInterface> p_to_switch;

private:
    std::vector<std::vector<short>> rx_buffer[PACKET_TYPES];
    sc_event checkRxBuffer;

    /**
     * Size of transfering package
     */
    const int PACKAGE_SIZE = 10;

    /**
     * Fake generating gelio-module data max number
     */
    const int GENERATE_DATA_LEN = 100;

public:
    SC_HAS_PROCESS(Gelio);

    explicit Gelio(const sc_module_name &name);

    void check_receive_buffer();
    void new_data();

    void write_packet(const std::vector<unsigned short> &packet) override;
    void read_packet(const std::vector<unsigned short> &packet) override;

    /**
     * Generate the shape of the studied surface data
     */ 
    void generate_data(int *package, int size);
};


#endif //ONBOARD_PROJECTS_CPU_H
