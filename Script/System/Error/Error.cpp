#include "Error.h"
#include <string>
#include "DxLib.h"

void Error::Finish(const char* message, LPCTSTR lpszFuncName, int lineN){

	char funcName[1024];
	sprintf_s(funcName, "%s", lpszFuncName);
	printfDx("異常が発生しました \n%s\n%s(%d)", message, funcName, lineN);

	while(!ProcessMessage()){

		ClearDrawScreen();
		ScreenFlip();

	}

	DxLib_End();

	exit(99);

}