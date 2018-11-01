#include "SystemMain.h"
#include "DxLib.h"
#include "../Define/Define.h"
#include "GameMain.h"

const char* Game_Title = "STG";
const int Color_Bit = 32;

bool SystemMain::Init() const{

	ChangeWindowMode(true);
	SetGraphMode(Window::Window_Width, Window::Window_Height, Color_Bit);
	SetMainWindowText(Game_Title);
	SetOutApplicationLogValidFlag(false);		//Log.txt�̏o�͂��~

	if(DxLib_Init()){
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

bool SystemMain::Update() const{

	GameMain gameMain;

	while(ProcessLoop()){

		if(!gameMain.GameLoop()){
			break;
		}

	}

	return false;
}

void SystemMain::Final() const{

	DxLib_End();

}

bool SystemMain::ProcessLoop() const{

	if(ScreenFlip() != 0){
		return false;
	}
	if(ProcessMessage() != 0){
		return false;
	}
	if(ClearDrawScreen() != 0){
		return false;
	}

	return true;
}