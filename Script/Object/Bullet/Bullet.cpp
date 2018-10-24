#include "Bullet.h"
#include "DxLib.h"
#include "../../Collider/Inheritance/StationeryCollider.h"

const int Game_WidthSize = 420;
const int Game_HeightSize = 480;

const int Image_AllNum = 176;
const int Image_Size = 16;

Bullet::Bullet(){
}

Bullet::Bullet(Vector2D<float> vec, int rad, float speed){

	vec2 = vec;
	moveVector = speed;
	isAlive = true;
	
	radius = rad;
	color = GetColor(240, 120, 220);

	collider = new CircleCollider(vec2, radius, eTag_Player);

	ListRegistration(this);

}

Bullet::~Bullet(){

	collider->SetAliveFlag(false);

}

bool Bullet::Update(){

	this->HitAction();

	if(vec2.GetY() <= 0){
		return false;
	}
	if(vec2.GetY() >= Game_HeightSize){
		return false;
	}
	if(vec2.GetX() <= 0){
		return false;
	}
	if(vec2.GetX() >= Game_WidthSize){
		return false;
	}

	this->Move();
	collider->SetVector(vec2);

	return isAlive;
}

void Bullet::Draw(){

	DrawCircle(vec2.GetDx(), vec2.GetDy(),radius, color, true);

}

void Bullet::Move(){

	vec2.Add(0.0f, moveVector);

}

void Bullet::HitAction(){

	if(collider->GetHitFlag()){
		isAlive = false;
	}

}