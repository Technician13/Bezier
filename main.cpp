#include "Bezier.hpp"

int main()
{
    double T = 0.05;
    Bezier *bezier = new Bezier(3, 3, T);

    Eigen::MatrixXd control_pt;
    control_pt.resize(3, 4);
    control_pt.col(0) << 0.0, 0.0, 0.0;
    control_pt.col(1) << -2.0, 1.0, 6.0;
    control_pt.col(2) << -5.0, 5.0, -5.0;
    control_pt.col(3) << 0.0, 8.0, 0.0;

    bezier->BezierInit();
    bezier->BezierRun(control_pt);

    delete bezier;
    return 0;
}