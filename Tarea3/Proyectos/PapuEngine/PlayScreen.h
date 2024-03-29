#pragma once
#include "IGameScreen.h"
#include "Camera2D.h"
#include "GLS_Program.h"
#include "Window.h"
#include "SpriteBatch.h"
#include "GLTexture.h"
#include "Gamer.h"
#include "Enemy.h"
#include <random>
#include <ctime>

class PlayScreen: public IGameScreen
{
private:
	GLS_Program _program;
	Gamer* player;
	Camera2D _camera2D;
	Window* _window = nullptr;
	SpriteBatch _spriteBatch;
	SpriteBatch _hudBach;
	Camera2D _hudCamera;
	void drawHUD();

	vector<Enemy*> enemies;

	mt19937 randomEngine = mt19937(time(nullptr));
	std::uniform_int_distribution<int> randomX;
	std::uniform_int_distribution<int> randomY;
	std::uniform_int_distribution<int> random100;
public:
	PlayScreen(Window* window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void initGUI() override;
	virtual void draw() override;
	virtual void update()override;
	virtual void initSystem()override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
	void checkBoundaries();
	~PlayScreen();
};

