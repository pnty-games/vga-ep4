#ifndef __VGINPUT_H 
#define __VGINPUT_H

class VGKeyboard;

class VGInput {
private:
	VGKeyboard* _Keyboard;

public:
	VGInput();
  ~VGInput();

  VGKeyboard* GetKeyboard() { return _Keyboard; }

  void Poll();

};


#endif