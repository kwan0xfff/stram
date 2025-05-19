#include <iostream>
#include <iomanip>
#include <Eigen/Dense>


class VectorOutput {
public:
    virtual ~VectorOutput() = default;
    virtual void writeHeader(std::ostream& os) = 0;
    virtual void writeVector(std::ostream& os, double t, const Vector3d& v) = 0;
};

