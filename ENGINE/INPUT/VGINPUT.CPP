#include "engine\input\vginput.h" 

#include "engine\input\keyboard.h"

VGInput::VGInput() {
	_Keyboard = new VGKeyboard();
}

VGInput::~VGInput() {
	delete _Keyboard;
  _Keyboard = 0;
}

void VGInput::Poll() {
	_Keyboard->Poll();
}
