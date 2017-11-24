// PID.h
// Author: Jan Wielgus
// Date: 06.11.2017
//

#ifndef _PID_h
#define _PID_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Komunikacja.h"
#include "config.h"



class PIDClass
{
//  =====   FUNKCJE   =====
 public:
	void setPID_gains(float _kP, float _kI, float _kD);             // ustawianie wzmocnie�
	void setPD_gains(float _kP, float _kD);                         // ustawianie wzmocnie�
	float getPID(float _current, float _set);       // zwraca obliczon� warto�� P+I+D
	float getPD(float current, float set);           // zwraca obliczon� warto�� P+D
	
 private:
	
	
//  =====   ZMIENNE   =====
 public:
	
 private:
	float kP, kI, kD;    // Wzmocznienia poszczeg�lnych cz�on�w kontrolera PID
	double val_I = 0;    // warto�� ca�ki
	float last_error;    // ostatnia warto�� b��du (do oblicznania D)
	double dt_;
	uint32_t timerPrev = 0;
};

extern PIDClass levelX_PID;
extern PIDClass levelY_PID;
extern PIDClass yaw_PD;

#endif

