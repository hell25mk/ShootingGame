#include "EnemyMove.h"
#include "../Base/BaseEnemy.h"
#include "../../../Define/Define.h"

using Math = Define::Math;

//���ɉ������Ĉꎞ��~�A���̌�ēx������
void EnemyMove::MovePattern00(BaseEnemy* enemy){

	const int count = enemy->GetCount();
	const int wait = 180;

	if(count == 0){
		enemy->SetAngle(Math::Math_Pai / 2);
		enemy->SetSpeed(3.0f);
		return;
	}
	if(count > 50 && count <= 80){
		enemy->SetSpeed(enemy->GetSpeed() - 0.1f);
		return;
	}
	if(count > wait + 80 && count <= wait + 80 + 30){
		enemy->SetSpeed(enemy->GetSpeed() + 0.1f);
		return;
	}

}

//�����ֈړ�
void EnemyMove::MovePattern01(BaseEnemy* enemy){

	const int count = enemy->GetCount();

	if(count == 0){
		enemy->SetAngle(Math::Math_Pai * 3 / 4);
		enemy->SetSpeed(3.0f);
		return;
	}

}

//�E���ֈړ�
void EnemyMove::MovePattern02(BaseEnemy* enemy){

	const int count = enemy->GetCount();

	if(count == 0){
		enemy->SetAngle(Math::Math_Pai * 1 / 4);
		enemy->SetSpeed(3.0f);
		return;
	}

}

void EnemyMove::MovePattern03(BaseEnemy* enemy){

	const int count = enemy->GetCount();
	const int wait = 180;

	if(count == 0){
		enemy->SetAngle(Math::Math_Pai / 2);
		enemy->SetSpeed(3.0f);
		return;
	}
	if(count > 50 && count <= 80){
		enemy->SetSpeed(enemy->GetSpeed() - 0.1f);
		return;
	}

}