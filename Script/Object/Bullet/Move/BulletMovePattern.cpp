#include "BulletMove.h"
#include "../Base/BaseBullet.h"
#include "../../../Define/Define.h"
#include <random>

//真上
void BulletMove::MovePattern00(BaseBullet* bullet){

	bullet->SetAngle((Define::Math_Pai * 3 / 2));
	bullet->SetSpeed(10.0f);

	return;
}

//くるくる(渦巻)
void BulletMove::MovePattern01(BaseBullet* bullet){

	const int count = bullet->GetCount();

	bullet->SetAngle((Define::Math_Pai + (0.1f * count)));
	bullet->SetSpeed(1.0f + (0.05f * count));

	return;
}

//角度の向きへ
void BulletMove::MovePattern02(BaseBullet* bullet){

	return;
}