#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using Vector3d = Eigen::Vector3d;

#include "writers.hh"

void
HumanOutput :: writeHeader(std::ostream& os) {
        // No header for human-readable format
}

void
HumanOutput :: writeVector(std::ostream& os, double t, const Vector3d& v) {
    os << std::fixed << std::setprecision(3);
    os << "t = " << t << ", v = ("
       << v.x() << ", " << v.y() << ", " << v.z() << ")\n";
}


void
CSVOutput :: writeHeader(std::ostream& os) {
    os << "time, posx, posy, posz\n";
}

void
CSVOutput :: writeVector(std::ostream& os, double t, const Vector3d& v) {
    os << std::fixed << std::setprecision(3);
    os << t << ", " << v.x() << ", " << v.y() << ", " << v.z() << "\n";
}

