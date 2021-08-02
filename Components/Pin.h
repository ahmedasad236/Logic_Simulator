#ifndef _PIN_H
#define _PIN_H

#include "..\Defs.h"

class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
public:
	bool alreadySet;
	Pin();
	void setStatus(STATUS r_Status);
	STATUS getStatus();
};

#endif