/*
	File: IImageWidget.cpp

	Copyright (C) 2019-2020 rs189. All rights reserved
*/

#include "IImageWidget.h"

//-----------------------------------------------------------------------------
// Activates IImageWidget initalization process
//-----------------------------------------------------------------------------
void IImageWidget::Start(IInterfaces* interfaces)
{
	m_Interface = interfaces;

	m_RenderPath = (RenderPath2D*)m_Interface->m_Tier0->m_Rendering->m_RenderPath;
}

//-----------------------------------------------------------------------------
// Activates IImageWidget shutdown process
//-----------------------------------------------------------------------------
void IImageWidget::Stop()
{
	m_Interface = nullptr;
}

//-----------------------------------------------------------------------------
// Processing a single frame of IImageWidget
//-----------------------------------------------------------------------------
void IImageWidget::Run(float dt)
{
	return;
}

//-----------------------------------------------------------------------------
// Sets a widget position
//-----------------------------------------------------------------------------
void IImageWidget::SetPos(float x, float y, bool immedUpdate)
{
	m_Data.m_Position = Vector(x, y, 0.0f);

	if (immedUpdate)
	{
		Update();
	}
}

//-----------------------------------------------------------------------------
// Returns a widget position
//-----------------------------------------------------------------------------
void IImageWidget::GetPos(float& x, float& y)
{
	x = m_Widget->params.pos.x;
	y = m_Widget->params.pos.y;
}

//-----------------------------------------------------------------------------
// Sets a widget size
//-----------------------------------------------------------------------------
void IImageWidget::SetSize(float width, float height, bool immedUpdate)
{
	m_Data.m_Size = Vector(width, height, 0.0f);

	if (immedUpdate)
	{
		Update();
	}
}

//-----------------------------------------------------------------------------
// Returns a widget size
//-----------------------------------------------------------------------------
void IImageWidget::GetSize(float& width, float& height)
{
	height = m_Data.m_Size.y;
	width = m_Data.m_Size.x;
}

//-----------------------------------------------------------------------------
// Sets a widget visibility
//-----------------------------------------------------------------------------
void IImageWidget::SetHidden(bool hidden, bool immedUpdate)
{
	m_Data.m_Hidden = hidden;

	if (immedUpdate)
	{
		Update();
	}
}

//-----------------------------------------------------------------------------
// Returns a widget visibility
//-----------------------------------------------------------------------------
void IImageWidget::GetHidden(bool& hidden)
{
	hidden = m_Data.m_Hidden;
}

//-----------------------------------------------------------------------------
// Sets a widget image
//-----------------------------------------------------------------------------
void IImageWidget::SetImage(std::string image, bool immedUpdate)
{
	m_Data.m_Image = image;

	if (immedUpdate)
	{
		Update();
	}
}

//-----------------------------------------------------------------------------
// Returns a widget image
//-----------------------------------------------------------------------------
void IImageWidget::GetImage(std::string& image)
{
	image = m_Data.m_Image;
}

//-----------------------------------------------------------------------------
// Sets a widget color
//-----------------------------------------------------------------------------
void IImageWidget::SetColor(Color color, bool immedUpdate)
{
	m_Data.m_Color = color;
	
	if (immedUpdate)
	{
		Update();
	}
}

//-----------------------------------------------------------------------------
// Returns a widget position
//-----------------------------------------------------------------------------
void IImageWidget::GetColor(Color& color)
{
	color = m_Data.m_Color;
}

//-----------------------------------------------------------------------------
// Sets a widget priority
//-----------------------------------------------------------------------------
void IImageWidget::SetPriority(int priority, bool immedUpdate)
{
	m_Data.m_Priority = priority;

	if (immedUpdate)
	{
		Update();
	}
}

//-----------------------------------------------------------------------------
// Returns a widget priority
//-----------------------------------------------------------------------------
void IImageWidget::GetPriority(int& priority)
{
	priority = m_Data.m_Priority;
}

//-----------------------------------------------------------------------------
// Updates a widget
//-----------------------------------------------------------------------------
void IImageWidget::Update()
{
	m_RenderPath->RemoveSprite(m_Widget);

	m_Widget = new wiSprite();
	m_RenderPath->AddSprite(&*m_Widget);

	m_RenderPath->SetSpriteOrder(m_Widget, m_Data.m_Priority);

	if (!m_Data.m_Image.empty())
	{
		m_RenderPath->RemoveSprite(m_Widget);

		m_Widget = new wiSprite(m_Data.m_Image);
		m_RenderPath->AddSprite(&*m_Widget);

		m_RenderPath->SetSpriteOrder(m_Widget, m_Data.m_Priority);
	}
	else
	{
		m_Widget->params.color = XMFLOAT4(m_Data.m_Color.rBase(), m_Data.m_Color.gBase(), m_Data.m_Color.bBase(), m_Data.m_Color.aBase());
	}

	m_Widget->params.pos = XMFLOAT3(m_Data.m_Position.x, m_Data.m_Position.y, 0.0f);
	m_Widget->params.siz = XMFLOAT2(m_Data.m_Size.x, m_Data.m_Size.y);

	m_Widget->SetHidden(m_Data.m_Hidden);
}
