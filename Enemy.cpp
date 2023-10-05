#include "Enemy.h"
#include "ImGuiManager.h"
void Enemy::Initialize(Model* model, uint32_t textureHandle, float x, float y) {
	model_ = model;
	textureHandle_ = textureHandle;
	worldTransform_.Initialize();
	worldTransform_.translation_.x = x;
	worldTransform_.translation_.y = y;
	move.x = kCharacterSpeed;
	move.y = kCharacterSpeed;
}

void Enemy::Update() {
	worldTransform_.TransferMatrix();

	float inputFloat3[3] = {
	    worldTransform_.translation_.x, worldTransform_.translation_.y,
	    worldTransform_.translation_.z};
	///

	if (worldTransform_.translation_.x > 30.0) {

		move.x *= -1;
	}

	if (worldTransform_.translation_.x < -30.0) {

		move.x *= -1;
	}

	if (worldTransform_.translation_.y > 20.0) {

		move.y *= -1;
	}

	if (worldTransform_.translation_.y < -20.0) {

		move.y *= -1;
	}

	worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	ImGui::Begin("enemy");
	ImGui::SliderFloat3("trns", inputFloat3, -33.0f, 33.0f);
	ImGui::SliderFloat("kCharacterSpeed", &kCharacterSpeed, -5.0f, 5.0f);
	ImGui::End();

	///

	/*const float kMoveLimitX = 33;
	const float kMoveLimitY = 18;
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);
*/
}

void Enemy::Draw(ViewProjection viewProjection_) {

	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}
