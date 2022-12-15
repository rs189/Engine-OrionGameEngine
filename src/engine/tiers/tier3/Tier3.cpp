/*
	File: Tier3.cpp

	Copyright (C) 2019-2020 rs189. All rights reserved
*/

#include "Tier3.h"

void Tier3::Start(IInterfaces* interfaces)
{
	m_Interface = interfaces;

	m_IGame = new IGame;
	if (!m_IGame)
	{
		return;
	}

	return;
}

void Tier3::Stop()
{
	SafeRelease(&m_IGame);

	SafeRelease(&m_Interface);

	return;
}

void Tier3::Run(float dt)
{
	return;
}
