#include "camera.h"

camera::camera(const sc_module_name& name):sc_module(name) {
    std::cout << std::string(name) + " module is created" << std::endl;
}

void camera::write_packet(const std::vector<unsigned short> &packet) {

}

void camera::read_packet(const std::vector<unsigned short> &packet) {

}
