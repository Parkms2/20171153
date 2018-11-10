#include"InputHandler.h"
#include"Game.h"
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() {
	// ������ 
}

void InputHandler::clean() {
	//SDL_DestroyWindow(m_pWindow);
	//SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			TheGame::Instance()->quit();
		}
		if (event.type == SDL_KEYUP) {		//Ű������������?
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_KEYDOWN) {	//Ű���� �ն�?
			m_keystates = SDL_GetKeyboardState(0);
		}
	}
}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) {
		if (m_keystates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

