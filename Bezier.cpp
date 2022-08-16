#include "Bezier.hpp"

int GetFactorial(int n_)
{   
    int res;

    if((n_ > -0.1) && (n_ < 0.1))
        return 1;
    else
    {   res = n_;
        for( ; n_ > 0 ; n_--)
        {
            res *= n_;
        }
    }

    return res;
}

/* constructor */
Bezier::Bezier(int N_, int dim_state_, double T_):
    N(N_), dim_state(dim_state_), T(T_)
{
    C.resize(N + 1);
    cnt_sampling = 1 + (int)(1.0 / T);
    res.resize(dim_state, cnt_sampling);

    std::cout << "Bezier Birth Done" << std::endl;
}

/* destructor */
Bezier::~Bezier()
{
    std::cout << "Bezier Die ..." << std::endl;
}

void Bezier::BezierInit()
{   
    /* get C */
    for(int i = 0 ; i < (N + 1) ; i++)
    {
        C[i] = ( GetFactorial(N) / GetFactorial(i) * GetFactorial(N - i) );
    }
}

void Bezier::BezierRun(Eigen::MatrixXd P_)
{
    res = Eigen::MatrixXd::Zero();
    /* error checking */
    if((P_.rows()) != dim_state)
        std::cout << "P is in wrong rows !!!" << std::endl; 
    if((P_.cols()) != (N + 1))
        std::cout << "P is in wrong cols !!!" << std::endl; 

    for(double j = 0 ; j < cnt_sampling ; j++)
    {
        for(int i = 0 ; i < (N + 1) ; i++)
        {
            res.col(j) += P_.col(i) * C[i] * pow((j * T) , i) * pow((1.0 - j * T) , i);
        }
    }
}

void Bezier::GetDesire()
{

}