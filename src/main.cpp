#include <iostream>
#include "switch.h"
#include "cpu.h"
#include "camera.h"
#include "gyroscope.h"
#include "engine.h"
#include "gelio.h"
#include "antenna.h"

using namespace sc_core;
int sc_main(int argc, char* argv[]) {

    //Create test env
    Cpu m_cpu("CPU");
    SwitchModule m_switch("Switch");
    camera m_camera("Camera");
    Gyroscope m_gyroscope("Gyroscope");
    Engine m_engine("Engine");
    Gelio m_gelio("Gelio");
    Antenna m_antenna("Antenna");

    //port binding
    m_cpu.p_to_switch.bind(m_switch);
    m_gyroscope.p_to_switch.bind(m_switch);
    m_gelio.p_to_switch.bind(m_switch);
    m_antenna.p_to_switch.bind(m_switch);
    m_camera.p_to_switch.bind(m_switch);
    m_engine.p_to_switch.bind(m_switch);

    m_switch.p_to_camera.bind(m_camera);
    m_switch.p_to_cpu.bind(m_cpu);
    m_switch.p_to_gyroscope.bind(m_gyroscope);
    m_switch.p_to_gelio.bind(m_gelio);
    m_switch.p_to_engine.bind(m_engine);
    m_switch.p_to_antenna.bind(m_antenna);

    sc_start(10, SC_MS);
    return 0;
}
