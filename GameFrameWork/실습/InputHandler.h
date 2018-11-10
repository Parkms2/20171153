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
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear �ϴ� �Լ� �ۼ��ϸ�ȴ�.
	bool isKeyDown(SDL_Scancode key);	//�ش�Ű�� ���ȴ��� Ȯ��
	bool getMouseButtonState(int buttonNumber);	//���콺 ��ư ���� ���� ������
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

	
