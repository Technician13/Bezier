#ifndef BEZIER_HPP
#define BEZIER_HPP

#include <iostream>
#include <Eigen/Dense>
#include <math.h>

/* ************************************ option start ************************************ */

/* ************************************ option end ************************************ */

class Bezier
{
    private:
        /* N order Bezier */
        int N;
        /* dim of state vector, for example, x-y or x-y-z */
        int dim_state;
        /* count of sampling point */
        int cnt_sampling;
        /* period of sampling */
        double T;
        /* load the coefficient */
        Eigen::VectorXd C;
        /* load the result */
        Eigen::MatrixXd res;
        
    protected:
        
    public:
        Bezier(int N_, int dim_state_, double T_);
        ~Bezier();
        void BezierInit();
        void BezierRun(Eigen::MatrixXd P_);
        void GetDesire();
};

#endif