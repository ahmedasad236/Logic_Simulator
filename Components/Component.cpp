#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo, bool select)
{
	m_GfxInfo = r_GfxInfo;
	LabelGfx.x1 = 0;
	LabelGfx.x2 = 0;
	LabelGfx.y1 = 0;
	LabelGfx.y2 = 0;
	mSelected = select;
	isSelected = 0;
	isDeleted = 0;
	m_Label = "";
}

Component::Component()
{
	isSelected = 0;
}

void Component::setAllNewLevels()
{
}

/* Returns whether the component is selected or not */
bool Component::IsSelected() const {
	return mSelected;
}

void Component::setLabel(string l)
{
	m_Label = l;
}

int Component::GetID()
{
	return id_comp;
}

void Component::SetID(int s)
{
	id_comp = s;
}
string Component::getLabel()
{
	return m_Label;
}

void Component::setLabelGraphics(GraphicsInfo L)
{
	LabelGfx = L;
}

GraphicsInfo Component::GetLabelGraphics()
{
	return LabelGfx;
}

GraphicsInfo Component::GetGraphicsInfo() const {
	return m_GfxInfo;
}

void Component::SetGraphicsInfo(GraphicsInfo g1)
{
	m_GfxInfo.x1 = g1.x1;
	m_GfxInfo.x2 = g1.x2;
	m_GfxInfo.y1 = g1.y1;
	m_GfxInfo.y2 = g1.y2;
}

void Component::save(ofstream& f)
{
}

/*bool* Component::get_selectedcomp()
{
	return SelectedComp;
}*/

bool Component::ValidComponent()
{
	return false;
}

void Component::setAllStatus()
{
}

Component::~Component()
{}

