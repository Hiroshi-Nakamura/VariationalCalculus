#include "Minimization.hpp"
#include "VariationalCalculus.hpp"

int main(int argc, char** argv)
{
    using namespace Minimization;
    using namespace AutomaticDifferentiation;
    using namespace VariationalCalculus;

    {
        std::cout << "minimization of sum_of_sq()+sum_of_sq_diff() with an initial value 10.0" << std::endl;
        Eigen::VectorXd x_val(20);
        x_val.setZero();
        minimization_with_equality_constraints(
            [](const std::vector<FuncPtr<double>> x){ return sum_of_sq(x)+5.0*sum_of_sq_diff(x); },
            {
                [](const std::vector<FuncPtr<double>> x){ return x.front()-10.0; }
            }, /// initial x(t) is 10.0
            x_val);
        std::cout << x_val << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "minimization of sum_of_sq()+sum_of_sq_diff() with an initial and last value 10.0, an initial difference and last difference 1.0" << std::endl;
        Eigen::VectorXd x_val(20);
        x_val.setZero();
        minimization_with_equality_constraints(
            [](const std::vector<FuncPtr<double>> x){ return sum_of_sq(x)+5.0*sum_of_sq_diff(x); },
            {
                [](const std::vector<FuncPtr<double>> x){ return x.front()-10.0; }, /// initial x(t) is 10.0
                [](const std::vector<FuncPtr<double>> x){ return x.back()-10.0; }, /// last x(t) is 10.0
                [](const std::vector<FuncPtr<double>> x){ return x[1]-x[0]-1.0; }, /// initial difference(dirivative approximation) x(t) is 1.0
                [](const std::vector<FuncPtr<double>> x){ return x[x.size()-1]-x[x.size()-2]+1.0; }, /// last difference(dirivative approximation) x(t) is -1.0
            },
            x_val);
        std::cout << x_val << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Catenary curve: minimization of sum_of() with an initial and last value 0.0, and the length of curve are twice of x-axis" << std::endl;
        const int length=39;
        Eigen::VectorXd x_val(length);
        x_val.setOnes();
        minimization_with_equality_constraints(
            [](const std::vector<FuncPtr<double>> x){ return sum_of(x); },
            {
                [](const std::vector<FuncPtr<double>> x){ return x.front(); }, /// initial x(t) is 0.0
                [](const std::vector<FuncPtr<double>> x){ return x.back(); }, /// last x(t) is 0.0
                [](const std::vector<FuncPtr<double>> x){ return length_of(x)-2.0*length; }, /// initial difference(dirivative approximation) x(t) is 1.0
            },
            x_val);
        std::cout << x_val << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "Brachistochrone curve: minimization of Brachistochrone_cost() with an initial and last value 0.0" << std::endl;
        Eigen::VectorXd x_val(20);
        x_val.setOnes();
        minimization_with_equality_constraints(
            [](const std::vector<FuncPtr<double>> x){ return Brachistochrone_cost(x); },
            {
                [](const std::vector<FuncPtr<double>> x){ return x.front(); }, /// initial x(t) is 0.0
                [](const std::vector<FuncPtr<double>> x){ return x.back(); }, /// last x(t) is 0.0
            },
            x_val);
        std::cout << x_val << std::endl;
    }

}


