#include "game\st_game.h"
#include "engine\engine.h"

#include "engine\input\vginput.h"
#include "engine\input\keyboard.h"
#include "engine\render\biostext.h"
#include "engine\render\vgsprite.h"
#include "engine\render\pxlbuff.h"
#include "engine\render\vgpcx.h"
#include "engine\types\vgrect.h"
#include "engine\ui\vgui.h"
#include "engine\ui\vgpanel.h"

#include "engine\video\mode13h.h"

#include <stdlib.h>

void StateGame::Enter(Engine* _engine) {
	GameState::Enter(_engine);

	VGPanel *testPanel = new VGPanel();
  testPanel->SetRect(VGRect(320/2, 50, 17, 20));

  PixelBuffer* borderPixels = VGPCX::LoadPCX("build/data/image1.pcx");
	_BorderSprite = new VGSprite(borderPixels);
  testPanel->SetSprite(_BorderSprite);

  VGPanel* titlePanel = new VGPanel();
  titlePanel->SetLabel("Welcome");
  titlePanel->SetRect(VGRect(5, 0, 7*8, 1));
  titlePanel->SetText(new VGBIOSText());
  testPanel->AddChild(titlePanel);

  VGUI* UI = _Engine->UI();
  UI->AddRoot(testPanel);
}

void StateGame::Exit() {
  _BorderSprite->FreePixels();
	delete _BorderSprite;
  _BorderSprite = null;
}

void StateGame::Tick() {
	if (_Engine->Input()->GetKeyboard()->GetState(0x01)) {
  	_Engine->SetGameState(0);
  }
}

void StateGame::Render() {

}
