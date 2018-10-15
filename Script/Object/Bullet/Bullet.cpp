#include "Bullet.h"
#include "DxLib.h"

const int Game_WidthSize = 420;
const int Game_HeightSize = 480;

const int Image_AllNum = 176;
const int Image_Size = 16;

Bullet::Bullet(){
}

Bullet::Bullet(Vector2D<float> vec, float speed){

	vec2 = vec;
	moveSpeed = speed;
	
	image = new int[Image_AllNum];
	LoadDivGraph("Image/Bullet/danmaku.png", Image_AllNum, 16, 11, Image_Size, Image_Size, image);
	

}

Bullet::~Bullet(){

	delete[] image;

}

bool Bullet::Update(){

	vec2.Add(0.0f, moveSpeed);

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

	return true;
}

void Bullet::Draw(){

	DrawRotaGraph(vec2.GetDx(), vec2.GetDy(), 1.0, 0.0, image[48], true);

}