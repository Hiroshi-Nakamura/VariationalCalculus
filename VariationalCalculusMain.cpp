#include "Minimization.hpp"

template<typename T>
T sum_of_sq(const std::vector<T> x)
{
    T rtn=AutomaticDifferentiation::zero<T>();
    for(auto e: x){
        rtn = rtn + e*e;
    }
    return rtn;
}

template<typename T>
T sum_of_sq_diff(const std::vector<T> x)
{
    T rtn=AutomaticDifferentiation::zero<T>();
    for(size_t i=1; i<x.size(); i++){
        rtn = rtn + (x[i]-x[i-1])*(x[i]-x[i-1]);
    }
    return rtn;
}

template<typename T>
T cost_function(const std::vector<T> x)
{
    return sum_of_sq(x)+5.0*sum_of_sq_diff(x);
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
    std::cout << std::endl;
    {
        Eigen::VectorXd x_val(10);
        x_val.setZero();
        minimization_with_equality_constraints(
            [](const std::vector<FuncPtr<double>> x){ return sum_of_sq(x)+5.0*sum_of_sq_diff(x); },
            {
                [](const std::vector<FuncPtr<double>> x){ return x.front()-10.0; }, /// initial x(t) is 10.0
                [](const std::vector<FuncPtr<double>> x){ return x.back()-10.0; }, /// last x(t) is 0.0
                [](const std::vector<FuncPtr<double>> x){ return x[1]-x[0]-1.0; }, /// initial difference(dirivative approximation) x(t) is 1.0
                [](const std::vector<FuncPtr<double>> x){ return x[x.size()-1]-x[x.size()-2]+1.0; }, /// last difference(dirivative approximation) x(t) is -1.0
            },
            x_val);
        std::cout << x_val << std::endl;
    }

}


