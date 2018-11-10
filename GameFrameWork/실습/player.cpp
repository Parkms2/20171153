#include"Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {
}
void Player::draw() {
	SDLGameObject::draw();
}
void Player::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_acceleration.setX(1);	//점차 가속
	SDLGameObject::update();
}
void Player::clean() {
}