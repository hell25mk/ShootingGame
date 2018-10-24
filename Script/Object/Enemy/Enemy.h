#pragma once

#include "../Base/BaseObject.h"

class BaseCollider;
class Score;

class Enemy : public BaseObject{

public:
	Enemy();
	Enemy(float x, float y, float speed);
	virtual ~Enemy();
	virtual bool Update() override;
	virtual void Draw() override;
	void HitAction();

private:
	BaseCollider* collider;
	float moveVector;
	Score* score;

};

