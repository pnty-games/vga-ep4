#include "engine\input\keyboard.h"

#include "engine\defs.h"

#include <dos.h>
#include <memory.h>

#include <iostream.h>

static VGKeyboard* Keyboard = 0;

void interrupt (*prevInt9)(...);
void interrupt handleInt9(...) {
  if (Keyboard != 0) {
		Keyboard->HandleInt9();
  }

  prevInt9(...);
}


VGKeyboard::VGKeyboard() {
	Keyboard = this;

  memset((void *)_KeyState, 0, NUM_KEYS);
  memset((void *)_PrevState, 0, NUM_KEYS);

  prevInt9 = getvect(9);
	setvect(9, handleInt9);
}

VGKeyboard::~VGKeyboard() {
	setvect(9, prevInt9);
	Keyboard = 0;
}

void VGKeyboard::HandleInt9() {

	unsigned char scanCode = inportb(0x60);
  unsigned char keyCode = scanCode;

  if (scanCode & 0x80) {
  	keyCode = scanCode & 0x7F;
    _KeyState[keyCode] = 0;
  } else {
  	_KeyState[keyCode] = 1;
  }

  // notify the system control we're set with the keyboard
  byte_t ctrl = inportb(0x61);
  outportb(0x61, ctrl | 0x80);
	outportb(0x61, ctrl);

  // notify the PIC we're done with the interrupt
  outportb(0x20, 0x20); // 0x20 = PIC, 0x20 unspecific end of int
}

void VGKeyboard::Poll() {
	memcpy(_PrevState, (void *)_KeyState, NUM_KEYS);
}