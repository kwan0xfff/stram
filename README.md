# stram
Simple Trajectory Modeling

The initial C++ code `flight.cc` is for an exceedingly simple model of a small UAV.
It uses the Eigen C++ template library, and currently assumes version 3.4.0.
To change the location of the Eigen library, specify `EIGEN_PATH` to the make command.
For example,

    make -e EIGEN_PATH=/home/me/mystuff/include/eigen3

The directory tree `Eigen/Dense` should be directly below `eigen3`.
