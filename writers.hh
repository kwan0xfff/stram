#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using Vector3d = Eigen::Vector3d;

class VectorOutput {
  public:
    virtual ~VectorOutput() = default;
    virtual void writeHeader(std::ostream& os) = 0;
    virtual void writeScalar(std::ostream& os, double s) = 0;
    virtual void writeVector(std::ostream& os, double t, const Vector3d& v) = 0;
    virtual void writeState(std::ostream& os, double t, const Vector3d& v) = 0;
};

class HumanOutput : public VectorOutput {
  public:
    void writeHeader(std::ostream& os) override;
    void writeScalar(std::ostream& os, double s) override;
    void writeVector(std::ostream& os, double t, const Vector3d& v) override;
    void writeState(std::ostream& os, double t, const Vector3d& v) override;

};

class CSVOutput : public VectorOutput {
  public:
    void writeHeader(std::ostream& os) override;
    void writeScalar(std::ostream& os, double s) override;
    void writeVector(std::ostream& os, double t, const Vector3d& v) override;
    void writeState(std::ostream& os, double t, const Vector3d& v) override;
};

