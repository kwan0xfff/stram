#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using Vector3d = Eigen::Vector3d;

class VectorOutput {
  public:
    virtual ~VectorOutput() = default;
    virtual void writeHeader(std::ostream& os) = 0;
    virtual void writeVector(std::ostream& os, double t, const Vector3d& v) = 0;
};

class HumanOutput : public VectorOutput {
  public:
    void writeHeader(std::ostream& os) override;
    void writeVector(std::ostream& os, double t, const Vector3d& v) override;

};

class CSVOutput : public VectorOutput {
  public:
    void writeHeader(std::ostream& os) override;
    void writeVector(std::ostream& os, double t, const Vector3d& v) override;
};

