/* 
 * File:   CKarlmanFilter.h
 * Author: sascha
 *
 * Created on 6. September 2012, 10:16
 */

#ifndef CKALMANFILTER_H
#define	CKALMANFILTER_H

#include <boost/numeric/ublas/matrix.hpp>

class CKalmanFilter {
public:
    CKalmanFilter();
    virtual ~CKalmanFilter();
    
    run(float newAngle, float newRate,int looptime);
private:
    float Q_angle       =  0.001;
    float Q_gyro        =  0.003;
    float R_angle       =  0.03; 

    float x_angle       = 0;
    float x_bias        = 0;
    float P_00          = 0; 
    float P_01          = 0;
    float P_10          = 0;
    float P_11          = 0;      
    float dt, y, S;
    float K_0, K_1;
   };

#endif	/* CKALMANFILTER_H */

