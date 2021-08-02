#include "Pin.h"

Pin::Pin()
{
	m_Status = LOW;	
	alreadySet = 0;//Default Status is LOW
}

void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
	alreadySet = 1;
}

STATUS Pin::getStatus()
{
	return m_Status;
}