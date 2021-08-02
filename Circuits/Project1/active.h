#pragma once
#include "Component.h"
class active : public Component
{
public:
	active(double v, double t) :Component(v, t){}
};
class Indpendant : public active
{
public:
	Indpendant(double v , double t) : active(v , t){}
};
class Dependant : public active
{
protected:
	int p1, p2;
public:
	Dependant(double v, double t, int x, int y) :active(v, t) , p1(x) , p2(y)
	{
	}
};
class Isrc : public Indpendant
{
public:
	Isrc(double v, double t) : Indpendant(v, t){}
};
class Vsrc : public Indpendant
{
public:
	Vsrc(double v, double t) :Indpendant(v, t) {}
};
class Vccs : public Dependant
{
	Component* Comp;
public:
	Vccs(double v , double t , int x , int y , Component*c):Dependant(v,t,x,y),Comp(c){}
};
class Cccs : public Dependant
{
	Component* Comp;
public:
	Cccs(double v, double t, int x, int y, Component* c) :Dependant(v, t, x, y), Comp(c) {}
};
class Vcvs : public Dependant
{
public:
	Vcvs(double v, double t, int x, int y) :Dependant(v, t, x, y){}
};
class Ccvs : public Dependant
{
public:
	Ccvs(double v, double t, int x, int y) :Dependant(v, t, x, y) {}
};