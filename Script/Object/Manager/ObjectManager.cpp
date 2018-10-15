#include "ObjectManager.h"
#include "../Player/Player.h"
#include "DxLib.h"

ObjectManager::ObjectManager(){

	listObject.push_back(new Player(10.0f,10.0f));

	listBegin = listObject.begin();
	listEnd = listObject.end();

}

ObjectManager::~ObjectManager(){

	//確保したメモリの解放
	for(auto itr = listBegin; itr != listEnd; itr++){

		delete *itr;
		*itr = nullptr;

	}

}

bool ObjectManager::Update(){

	//更新
	for(auto itr = listBegin; itr != listEnd; itr++){

		(*itr)->Update();

	}

	return true;
}

void ObjectManager::Draw(){

	//描画
	for(auto itr = listBegin; itr != listEnd; itr++){

		(*itr)->Draw();

	}

}