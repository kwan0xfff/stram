#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using Vector3d = Eigen::Vector3d;

#include "vectoroutput.hh"

class HumanOutput : public VectorOutput {
public:
    void writeHeader(std::ostream& os) override {
        // No header for human-readable format
    }

    void writeVector(std::ostream& os, double t, const Vector3d& v) override {
        os << std::fixed << std::setprecision(3);
        os << "t = " << t << ", v = ("
           << v.x() << ", " << v.y() << ", " << v.z() << ")\n";
    }
};


class CSVOutput : public VectorOutput {
public:
    void writeHeader(std::ostream& os) override {
        os << "time, posx, posy, posz\n";
    }

    void writeVector(std::ostream& os, double t, const Vector3d& v) override {
        os << std::fixed << std::setprecision(3);
        os << t << ", " << v.x() << ", " << v.y() << ", " << v.z() << "\n";
    }
};

