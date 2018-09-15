#include <iostream>
#include <Windows.h>
#include "XBoxController.h"
#include "XInputWrapper.h"
#include <cmath>

#define zd_max 32767

GamePad::XBoxController::XBoxController(XInputWrapper * xinput, DWORD id)
{
	
	CTRID = id;
	this->xinput = xinput;
}

DWORD GamePad::XBoxController::GetControllerId()
{
	return CTRID;
}

bool GamePad::XBoxController::IsConnected()
{

	if (XInputGetState(CTRID, &State) == ERROR_SUCCESS)//id or directly 0
	{
		return true;
	}
	return false;
}

bool GamePad::XBoxController::PressedA()
{
	if ((State.Gamepad.wButtons & 0x1000) == 0x1000)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedB()
{
	if ((State.Gamepad.wButtons & 0x2000) == 0x4000)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedX()
{
	if ((State.Gamepad.wButtons & 0x4000) == 0x4000)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedY()
{
	if ((State.Gamepad.wButtons & 0x1000) == 0x1000)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedLeftShoulder()
{
	if ((State.Gamepad.wButtons & 0x0100) == 0x0100)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedRightShoulder()
{
	if ((State.Gamepad.wButtons & 0x0200) == 0x0200)
	{
		return true;
	}
	return false;

}

bool GamePad::XBoxController::PressedLeftDpad()
{
	if ((State.Gamepad.wButtons & 0x0004) == 0x0004)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedRightDpad()
{
	if ((State.Gamepad.wButtons & 0x0008) == 0x0008)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedUpDpad()
{
	if ((State.Gamepad.wButtons & 0x0001) == 0x0001)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedDownDpad()
{
	if ((State.Gamepad.wButtons & 0x0002) == 0x0002)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedStart()
{
	if ((State.Gamepad.wButtons & 0x0010) == 0x0010)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedBack()
{
	if ((State.Gamepad.wButtons & 0x0020) == 0x0020)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedLeftThumb()
{
	if ((State.Gamepad.wButtons & 0x0040) == 0x0040)
	{
		return true;
	}

	return false;
}

bool GamePad::XBoxController::PressedRightThumb()
{
	if ((State.Gamepad.wButtons & 0x0080) == 0x0080)
	{
		return true;
	}

	return false;
}

BYTE GamePad::XBoxController::LeftTriggerLocation()
{
	return State.Gamepad.bLeftTrigger;
}

BYTE GamePad::XBoxController::RightTriggerLocation()
{
	return State.Gamepad.bRightTrigger;
}

GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation()
{
	LCO.SetX(State.Gamepad.sThumbLX);
	LCO.SetY(State.Gamepad.sThumbLY);
	return LCO;
}

GamePad::Coordinate GamePad::XBoxController::RightThumbLocation()
{
	RCO.SetX(State.Gamepad.sThumbRX);
	RCO.SetY(State.Gamepad.sThumbRY);
	return RCO;
}

void GamePad::XBoxController::Vibrate(WORD left, WORD right)
{
	

	Vibration.wLeftMotorSpeed = left;
	Vibration.wRightMotorSpeed = right;
	XInputSetState(CTRID, &Vibration); //id or 0.
}

void GamePad::XBoxController::SetDeadzone(unsigned int radius)
{
	SHORT LX = LCO.GetX();
	SHORT LY = LCO.GetY();
	SHORT RX = RCO.GetX();
	SHORT RY = RCO.GetY();


	unsigned int lmagnitude = sqrt(LX ^ 2 + LY ^ 2);
	SHORT radian = atan2(LY, LX);
	SHORT ratio = 0;
	if (lmagnitude >= zd_max)
	{
		lmagnitude = zd_max;
	}
	if (lmagnitude > radius)
	{
		ratio = (lmagnitude / zd_max - radius)*zd_max;
		lmagnitude = ratio * lmagnitude;
		LX = cos(radian) * lmagnitude;
		LY = sin(radian) * lmagnitude;
		LCO.SetX(LX);
		LCO.SetX(LY);
	}
	else
	{
		LCO.SetX(0);
		LCO.SetY(0);
	}
	unsigned int Rmagnitude = sqrt(RX ^ 2 + RY ^ 2);
	radian = atan2(RY, RX);
	ratio = 0;
	if (Rmagnitude >= zd_max)
	{
		Rmagnitude = zd_max;
	}
	if (Rmagnitude > radius)
	{
		ratio = (Rmagnitude / zd_max - radius)*zd_max;
		Rmagnitude = ratio * Rmagnitude;
		RX = cos(radian) * Rmagnitude;
		RY = sin(radian) * Rmagnitude;
		RCO.SetX(RX);
		RCO.SetX(RY);
	}
	else
	{
		RCO.SetX(0);
		RCO.SetY(0);
	}
}
