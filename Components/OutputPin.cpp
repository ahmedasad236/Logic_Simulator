#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}
	return false;	//can't connect to any more connections
}

bool OutputPin::ConnectedTo(Connection* r_Conn)
{
	for (int i = 0; i < m_Conn; i++)
	{
		if (m_Connections[i] == r_Conn)
		{
			return 1;
		}
	}
	return 0;
}

void OutputPin::setNewLevel()
{
	for (int i = 0; i < m_Conn; i++)
	{
		m_Connections[i]->getDestPin()->getComponent()->newLevel = 1;
	}
}

void OutputPin::setConnectionsStatus()
{
	for (int i = 0; i < m_Conn; i++)
	{
		m_Connections[i]->Operate();
	}
}

bool OutputPin::valid()
{
	return m_Conn;
}

void OutputPin::decrementFanOut()
{
	m_Conn--;
}

bool OutputPin::canConnectToAdditionalWire()
{
	return m_Conn < m_FanOut;
}
