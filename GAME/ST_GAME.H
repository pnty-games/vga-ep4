#ifndef __ST_GAME_H
#define __ST_GAME_H

#include "engine\defs.h"
#include "engine\gamestat.h"

class Engine;
class VGSprite;

class StateGame : public GameState {

	VGSprite* _BorderSprite;

public:

	StateGame() : _BorderSprite(null) { ; }

	virtual void Enter(Engine* _engine);
  virtual void Exit();

  virtual void Tick();
  virtual void Render();
};

#endif
