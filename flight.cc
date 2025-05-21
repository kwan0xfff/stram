#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

#include "vectoroutput.hh"

constexpr double g = 9.81;          // Gravity (m/s^2)
constexpr double dt = 0.01;         // Time step (s)
constexpr double total_time = 10.0; // Total simulation time (s)
constexpr double mass = 1.5;        // UAV mass (kg)
constexpr double thrust = 20.0;     // Constant upward thrust (N)
constexpr double drag_coef = 0.05;  // Simplified linear drag coefficient

using State = Eigen::Matrix<double, 6, 1>; // [x, y, z, vx, vy, vz]
using Vector3d = Eigen::Vector3d;

State derivative(const State& state) {
    State dstate;

    // Unpack position and velocity
    Vector3d pos [[maybe_unused]] = state.segment<3>(0);
    Vector3d vel = state.segment<3>(3);

    // Position derivative is velocity
    dstate.segment<3>(0) = vel;

    // Compute forces
    Vector3d F_gravity(0, 0, -mass * g);
    Vector3d F_thrust(0, 0, thrust); // Thrust along +z (up)
    Vector3d F_drag = -drag_coef * vel; // Simplified linear drag

    Vector3d acc = (F_gravity + F_thrust + F_drag) / mass;
    dstate.segment<3>(3) = acc;

    return dstate;
}


int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [human|csv]\n";
        return 1;
    }

    std::string mode = argv[1];
    std::unique_ptr<VectorOutput> output;

    if (mode == "human") {
        output = std::make_unique<HumanOutput>();
    } else if (mode == "csv") {
        output = std::make_unique<CSVOutput>();
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }


    State state;
    state << 0.0, 0.0, 0.0,  // Initial position
             0.0, 0.0, 0.0;  // Initial velocity
    int msgnum = 0;
    int msgcycle = 50;

    output->writeHeader(std::cout);

    for (double t = 0; t <= total_time; t += dt) {

        if (msgnum == 0) {
            output->writeVector(std::cout, t, state.segment<3>(0));
        }

        State dstate = derivative(state);
        state += dt * dstate;

        msgnum++;
        if (msgnum >= msgcycle) msgnum = 0;
    }

    return 0;
}
