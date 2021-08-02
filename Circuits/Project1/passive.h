#pragma once
#include "Component.h"
class passive : public Component
{
public:
	passive(double v, double t);
};
class Cap : public passive
{
public:
	Cap(double v) : passive(v, -90){}
};
class Res : public passive
{
public:
	Res(double v) :passive(v, 0){}
};
class Ind : public passive
{
public:
	Ind(double v) : passive(v , 90){}
};

