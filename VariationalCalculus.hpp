#ifndef VARIATIONALCALCULUS_HPP_INCLUDED
#define VARIATIONALCALCULUS_HPP_INCLUDED

#include "AutomaticDifferentiation.hpp"

namespace VariationalCalculus {
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
}
#endif // VARIATIONALCALCULUS_HPP_INCLUDED
