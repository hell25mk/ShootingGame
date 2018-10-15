#pragma once

#include "../Library/StationeryObject.h"

class BaseController;

class Player : public BoxObject{

public:
	Player();
	Player(float x, float y, int rad, unsigned int color);
	virtual ~Player();
	virtual void Update() override;
	virtual void Draw() override;
	void Move();
	void Shot();

private:
	static const float moveSpeed;

private:
	BaseController* controller;

};

