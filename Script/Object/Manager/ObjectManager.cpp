#include "ObjectManager.h"
#include "../Player/Player.h"
#include "DxLib.h"

ObjectManager::ObjectManager(){

	vectorObject.push_back(new Player(10.0f,10.0f));

}

ObjectManager::~ObjectManager(){

	auto begin = vectorObject.begin();
	auto end = vectorObject.end();
	//確保したメモリの解放
	for(auto itr = begin; itr != end; itr++){

		delete *itr;
		*itr = nullptr;

	}

	//vectorの解放
	std::vector<BaseObject*>().swap(vectorObject);

}

bool ObjectManager::Update(){

	auto begin = vectorObject.begin();
	auto end = vectorObject.end();
	//更新
	for(auto itr = begin; itr != end; itr++){

		(*itr)->Update();

	}

	return true;
}

void ObjectManager::Draw(){

	auto begin = vectorObject.begin();
	auto end = vectorObject.end();
	//描画
	for(auto itr = begin; itr != end; itr++){

		(*itr)->Draw();

	}

}