#include "camera.h"

camera::camera(const sc_module_name& name):sc_module(name) {
    log("Module created");
}

void camera::write_packet(const std::vector<unsigned short> &packet) {

}

void camera::read_packet(const std::vector<unsigned short> &packet) {

}
