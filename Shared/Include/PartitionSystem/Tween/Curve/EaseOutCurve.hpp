//
// Created by hippolyteb on 11/24/16.
//

#ifndef R_TYPE_EASEOUTCURVE_HPP
#define R_TYPE_EASEOUTCURVE_HPP

#include "ITweeningCurve.hpp"

class EaseOutCurve : public ITweeningCurve {
public:
    double Curve(const double &d) const override final {
        return sin(d * (M_PI/2));
    }
};


#endif //R_TYPE_EASEOUTCURVE_HPP
