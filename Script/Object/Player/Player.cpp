#include "Player.h"
#include "DxLib.h"
#include "../../MyLibrary/MyLibrary.h"
#include "../../Define/Define.h"
#include "../../Input/Controller.h"
#include "../../System/Image/Image.h"
#include "../Bullet/Factory/ShotFactory.h"
#include "../../Collider/Factory/ColliderFactory.h"
#include "../../Collider/Inheritance/StationeryCollider.h"

#include "../../Test/TestGameInfomation.h"

using Key = Input::eInputType;
namespace Game = Define::GameSize;

Player::Player(float x, float y):BaseGameObject(x,y){

	Init();

}

Player::Player(Vector2D<float>& vec):BaseGameObject(vec){

	Init();

}

void Player::Init(){

	moveSpeed = 4.0f;
	isDrawHitRange = false;

	width = 15;
	height = 15;

	imageHandle = Image::Instance().GetImage("Player");

	shotDelayCount = 0;
	dirayTime = 0;

	collider = ColliderFactory::Instance().CreateCircleCollider(&vec2, 2, ObjectType::eType_Player, true);

}

void Player::Destroy(){

	TestGameInfomation::Instance().isGameMode = false;
	collider->SetAliveFlag(false);

}

bool Player::Update(){

	if(dirayTime < 25){
		dirayTime++;
		return true;
	}

	if(collider->GetHitFlag()){
		return false;
	}

	Move();

	if(Controller::Instance().Get(Key::Shot)){
		Shot();
	}

	return isAlive;
}

void Player::Draw() const{

	DrawRotaGraphF(vec2.GetX(), vec2.GetY(), 1.0, 0.0, imageHandle, true);

	if(!isDrawHitRange){
		return;
	}
	collider->Draw();

}

void Player::Move(){

	float moveX = 0, moveY = 0;

	if(Controller::Instance().Get(Key::Up)){
		moveY -= moveSpeed;
	}

	if(Controller::Instance().Get(Key::Down)){
		moveY += moveSpeed;
	}

	if(Controller::Instance().Get(Key::Left)){
		moveX -= moveSpeed;
	}

	if(Controller::Instance().Get(Key::Right)){
		moveX += moveSpeed;
	}

	//斜め移動時√2で割る
	if(moveX && moveY){
		moveX /= (float)std::sqrt(2.0);
		moveY /= (float)std::sqrt(2.0);
	}

	//減速
	if(Controller::Instance().Get(Key::Slow)){
		moveX /= 2;
		moveY /= 2;
		isDrawHitRange = true;
	} else{
		isDrawHitRange = false;
	}

	//移動可能範囲の確認
	float px = vec2.GetX(), py = vec2.GetY();
	if(px + moveX - width < Game::In_Px){
		moveX = 0;
	} else if(px + moveX + width > Game::In_Px + Game::In_Width){
		moveX = 0;
	}

	if(py + moveY - height < Game::In_Py){
		moveY = 0;
	} else if(py + moveY + height > Game::In_Py + Game::In_Height){
		moveY = 0;
	}

	vec2.Add(moveX , moveY);

}

void Player::Shot(){

	const int Shot_DelayTime = 5;

	if(shotDelayCount > Shot_DelayTime){
		ShotFactory::Instance().PlayerBulletCreate(vec2);
		shotDelayCount = 0;
	}

	shotDelayCount++;

}