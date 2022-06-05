#pragma once
#include <map>

enum class States_Gearbox { back = -1, neutral = 0, first = 1, second = 2, third = 3, fourth = 4, fifth = 5 };

enum class Movement_Direction { Backward = -1, Stopped = 0, Forward = 1 };

static const std::map<States_Gearbox, std::pair<unsigned, unsigned>> SPEED_RANGE = {
	{States_Gearbox::back, {0, 20}},
	{States_Gearbox::neutral, {0, 150}},
	{States_Gearbox::first, {0, 30}},
	{States_Gearbox::second, {20, 50}},
	{States_Gearbox::third, {30, 60}},
	{States_Gearbox::fourth, {40, 90}},
	{States_Gearbox::fifth, {50, 150}}
};

class CCar
{
public:
	CCar();
	~CCar() = default;

	bool IsEngineWorking() const
	{
		return m_isEngineTurnedOn;
	}

	bool TurnOnEngine();

	bool TurnOffEngine();

	States_Gearbox GetGear() const;

	Movement_Direction GetMovementDirection() const;

	unsigned GetCurrentSpeed() const;

	bool SetSpeed(unsigned const& speed);

	bool SetGear(States_Gearbox const& gearState);


private:

	void SetMovementDirection();

	unsigned m_currentSpeed;

	bool m_isEngineTurnedOn;

	States_Gearbox m_gearboxState;

	Movement_Direction m_movementDirection;
};