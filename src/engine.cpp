#include "engine.h"

Engine::Engine(const sc_module_name &name) : sc_module(name), x(0), y(0), z(0) {
    log("Module created");

    got_x = got_y = got_z = 0;
    SC_METHOD(change_position)
    sensitive << e_change_position;
    dont_initialize();

}

void Engine::read_packet(const std::vector<unsigned short> &packet) {

}

void Engine::write_packet(const std::vector<unsigned short> &packet) {
    procLog("RECEIVE", "got a packet");
    procLog("START CHANGE", "start change engine position");

    got_x = packet[2] + (packet[3] << 8)
            + (packet[4] << 16)
            + (packet[5] << 24);


    got_y = packet[6] + (packet[7] << 8)
            + (packet[8] << 16)
            + (packet[9] << 24);

    got_z = packet[10] + (packet[11] << 8)
            + (packet[12] << 16)
            + (packet[13] << 24);

    e_change_position.notify(200, SC_NS);
}

void Engine::change_position() {
    if ((x == got_x) && (y == got_y) && (z == got_z)) {
        procLog("NOPE", "nothing to change, aborting");
    }
    else {
        procLog("CHANGE", "changing position");
        std::cout << sc_time_stamp().to_string()
        << " "
        << name()
        << " position was [x],[y],[z] = "
        << x << "," << y << ","<< z <<  std::endl;

        x = got_x;
        y = got_y;
        z = got_z;

        std::cout << sc_time_stamp().to_string()
        << " "
        << name()
        << " new position [x],[y],[z] = "
        << x << "," << y << ","<< z <<  std::endl;
    }
}
