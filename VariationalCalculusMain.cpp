#include "Minimization.hpp"

template<typename T>
T cost_function(const std::vector<T> x)
{
    constexpr double alpha=5.0;
    T rtn=x[0]*x[0];
    for(size_t i=1; i<x.size(); i++){
        rtn = rtn + x[i]*x[i];
    }

    for(size_t i=1; i<x.size(); i++){
        rtn = rtn + alpha*(x[i]-x[i-1])*(x[i]-x[i-1]);
    }
    return rtn;
}

template<typename T>
T constraint_eq(const std::vector<T> x)
{
    return x.front()-10.0;
}

int main(int argc, char** argv)
{
    using namespace Minimization;
    using namespace AutomaticDifferentiation;

    {
        Eigen::VectorXd x_val(10);
        x_val.setZero();
        minimization_with_equality_constraints(
            cost_function<FuncPtr<double>>,
            {constraint_eq<FuncPtr<double>>},
            x_val);
        std::cout << x_val << std::endl;
    }
    {
        Eigen::VectorXd x_val(10);
        x_val.setZero();
        minimization_with_equality_constraints(
            cost_function<FuncPtr<double>>,
            {
                [](const std::vector<FuncPtr<double>> x){ return x.front()-10.0; }, /// initial x(t) is 10.0
                [](const std::vector<FuncPtr<double>> x){ return x.back()-0.0; }, /// last x(t) is 0.0
                [](const std::vector<FuncPtr<double>> x){ return x[0]-x[1]-1.0; }, /// initial difference(dirivative approximation) x(t) is 1.0
            },
            x_val);
        std::cout << x_val << std::endl;
    }

}


