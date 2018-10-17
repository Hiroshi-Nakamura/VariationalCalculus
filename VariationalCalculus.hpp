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
    T sum_of(const std::vector<T> x)
    {
        T rtn=AutomaticDifferentiation::zero<T>();
        for(auto e: x){
            rtn = rtn + e;
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
    T length_of(const std::vector<T> x)
    {
        T rtn=AutomaticDifferentiation::zero<T>();
        for(size_t i=1; i<x.size(); i++){
            rtn = rtn + sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+1.0);
        }
        return rtn;
    }

    template<typename T>
    T Brachistochrone_cost(const std::vector<T> x)
    {
        T rtn=AutomaticDifferentiation::zero<T>();
        for(size_t i=1; i<x.size(); i++){
            auto diff=x[i]-x[i-1];
            rtn = rtn + sqrt((1.0+diff*diff)/(2.0*9.8*x[i]));
        }
        return rtn;
    }
}
#endif // VARIATIONALCALCULUS_HPP_INCLUDED
