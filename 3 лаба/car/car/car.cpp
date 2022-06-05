#include "CCar.h"
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const string MENU = "Menu:";
const string TURNON_TURNOFF = "TurnOn/ TurnOff";
const string SETSPEED = "SetSpeed";
const string SETGEAR = "SetGear(back/ neutral/ first/ second/ third/ fouth/ fifth)";
const string INFO = "Info";

const string UNK_COMM = "Unknown command!";
const string INV_COMM = "Invalid command!";

const string MOV_DIR = "Movement Direction: ";
const string CUR_SPEED = "Current Speed ";
const string GEAR_STATE = "Gearbox state ";

static const map<string, States_Gearbox> GEARBOX_STATES_MAP = {
	{"back", States_Gearbox::back},
	{"neutral", States_Gearbox::neutral},
	{"first", States_Gearbox::first},
	{"second", States_Gearbox::second},
	{"third", States_Gearbox::third},
	{"fourth", States_Gearbox::fourth},
	{"fifth", States_Gearbox::fifth}
};

static const map <States_Gearbox, string> GEARBOX_INFO_MAP = {
	{ States_Gearbox::back, "back" },
	{ States_Gearbox::neutral, "neutral" },
	{ States_Gearbox::first, "first" },
	{ States_Gearbox::second, "second" },
	{ States_Gearbox::third, "third" },
	{ States_Gearbox::fourth, "fourth" },
	{ States_Gearbox::fifth, "fifth" }
};

static const map <Movement_Direction, string> MOVEMENT_INFO_MAP = {
	{ Movement_Direction::Forward, "Forward"},
	{ Movement_Direction::Backward, "Backward" },
	{ Movement_Direction::Stopped, "Stay" }
};

void ShowCarInfo(CCar const& car)
{
	string infoStr;
	infoStr = (car.IsEngineWorking() == true ? "Engine active!" : "Engine disabled");

	cout << infoStr << "\n";

	cout << MOV_DIR << MOVEMENT_INFO_MAP.find(car.GetMovementDirection())->second << "\n";
	cout << CUR_SPEED << car.GetCurrentSpeed() << "\n";
	cout << GEAR_STATE << GEARBOX_INFO_MAP.find(car.GetGear())->second << "\n";

}

int main()
{
	cout << MENU << "\n";
	cout << TURNON_TURNOFF << "\n";
	cout << SETSPEED << "\n";
	cout << SETGEAR << "\n";
	cout << INFO << "\n";
	cout << "\n";

	CCar myCar;
	std::string str;
	unsigned value;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::cin >> str;

		transform(str.begin(), str.end(), str.begin(), tolower);

		if (str == "turnoff")
		{
			myCar.TurnOffEngine();
		}
		else if (str == "turnon")
		{
			myCar.TurnOnEngine();
		}
		else if (str == "setspeed")
		{
			std::cin >> value;
			myCar.SetSpeed(value);
		}
		else if (str == "setgear")
		{
			std::cin >> str;
			if (GEARBOX_STATES_MAP.find(str) != GEARBOX_STATES_MAP.end())
			{
				myCar.SetGear(GEARBOX_STATES_MAP.find(str)->second);
			}
			else
			{
				cout << UNK_COMM << "\n";
			}
		}
		else if (str == "info")
		{
			ShowCarInfo(myCar);
		}
		else
		{
			std::cout << INV_COMM << "\n";
		}
	}

	return 0;
}