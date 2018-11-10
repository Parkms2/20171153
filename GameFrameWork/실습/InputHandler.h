#pragma once
#include "SDL.h"
#include<vector>
#include"Vector2D.h"
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	Vector2D* m_mousePosition;
	Vector2D* getMousePosition();
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 하는 함수 작성하면된다.
	bool isKeyDown(SDL_Scancode key);	//해당키가 눌렸는지 확인
	bool getMouseButtonState(int buttonNumber);	//마우스 버튼 눌림 상태 가져옴
	std::vector<bool> m_mouseButtonStates;
	const Uint8* m_keystates;
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();
};

typedef InputHandler TheInputHandler;

	
