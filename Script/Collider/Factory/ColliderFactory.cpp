#include "ColliderFactory.h"
#include "../Manager/ColliderManager.h"
#include "../Inheritance/StationeryCollider.h"

void ColliderFactory::Init(ColliderManager* colliderManager){

	this->colliderManager = colliderManager;

}

/// <summary>
/// @brief 円形の当たり判定を追加する
/// </summary>
/// <param name="vec">座標</param>
/// <param name="rad">半径</param>
/// <param name="tag">タグ</param>
/// <param name="isDraw">判定位置を描画するか</param>
/// <returns>生成した判定</returns>
std::shared_ptr<CircleCollider> ColliderFactory::CreateCircleCollider(Vector2D<float>* const vec, const int rad, const int tag, const bool isDraw){

	std::shared_ptr<CircleCollider> collider = std::make_shared<CircleCollider>();

	collider->SetVector(vec);
	collider->SetRadius(rad);
	collider->SetObjectTag(tag);
	collider->SetIsDraw(isDraw);

	colliderManager->AppendCollider(collider);

	return collider;
}