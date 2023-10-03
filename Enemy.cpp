#include "Enemy.h"

void Enemy::Initialize(Model* model, uint32_t textureHandle) {
	model_ = model;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize();


}

void Enemy::Update() {}

void Enemy::Draw(ViewProjection viewProjection_) {


	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}
