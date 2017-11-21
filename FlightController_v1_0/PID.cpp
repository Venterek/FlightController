// Author: Jan Wielgus
// Date: 06.11.2017
// 

#include "PID.h"

PIDClass levelX_PID;
PIDClass levelY_PID;
PIDClass yaw_PD;


// =============================  PUBLIC  =============================

void PIDClass::setPID_gains(float _kP, float _kI, float _kD)
{
	kP = _kP;
	kI = _kI;
	kD = _kD;
}



void PIDClass::setPD_gains(float _kP, float _kD)
{
	kP = _kP;
	kI = 0.0;
	kD = _kD;
}



float PIDClass::getPID(float _current, float _set, double _deltaT)
{
	float er_ = _current - _set;
	// -P-
	float val_P = er_*kP;
	// -I-
	val_I += (er_ * kI) * _deltaT;
	val_I = constrain(val_I, -kom.conf.I_level_limiter, kom.conf.I_level_limiter);
	// -D-
	er_ /= D_error_divisor;
	float val_D = ((er_ - last_error) / _deltaT) * kD;
	last_error = er_;
	
	return val_P + val_I + val_D;
}




// =============================  PRIVTE  =============================




