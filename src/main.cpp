#include <systemc>
#include <random>

#include "gelio.h"
#include "switch.h"
#include "antenna.h"
#include "cpu.h"
#include "control_center.h"

using namespace sc_core;

int sc_main(int argc, char* argv[]) {
    // use current time as seed for random generator
    std::srand(std::time(nullptr));

    sc_signal<bool> clk;

    Gelio mgelio("Gelio");
    mgelio.clk(clk);

    CPU mcpu("CPU");
    mcpu.clk(clk);

    Antenna mantenna("Antenna");
    mantenna.clk(clk);

    Switch mswitch("Switch");
    mswitch.clk(clk);
    
    ControlCenter mcontrolCenter("ControlCenter");
    mantenna.radio.bind(mcontrolCenter);
    mcontrolCenter.port.bind(mantenna);

    mgelio.port.bind(mswitch);
    mswitch.gelio_port.bind(mgelio);

    mcpu.port.bind(mswitch);
    mswitch.cpu_port.bind(mcpu);

    mantenna.port.bind(mswitch);
    mswitch.antenna_port.bind(mantenna);

    sc_start(0, SC_NS);
    for(int i = 0; i < 50; i++){
        clk.write(1);
        sc_start( 10, SC_NS );
        clk.write(0);
        sc_start( 10, SC_NS );
    }

    return 0;
}