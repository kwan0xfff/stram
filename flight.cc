#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

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


int main() {
    State state;
    state << 0.0, 0.0, 0.0,  // Initial position
             0.0, 0.0, 0.0;  // Initial velocity
    int fmtcode = 2;

    for (double t = 0; t <= total_time; t += dt) {
        switch(fmtcode) {
            default:
            case 1:
                std::cout << "t = " << t << "s, pos = (" << state(0) << ", " << state(1) << ", " << state(2) << ")" << std::endl;
                break;
            case 2:
                std::cout << std::setw(8) << std::fixed << std::setprecision(3);
                std::cout << t;
                for (int i=0; i<3; ++i) {
                    std::cout << ", " << state(i);
                }
                std::cout << std::endl;
                break;
        }

        State dstate = derivative(state);
        state += dt * dstate;
    }

    return 0;
}
