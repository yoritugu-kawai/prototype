#include "mpdel.h"

void modelenemy::Initialize(Model* model) {
	assert(model);

	this->model_ = model;
	worldTransform_.Initialize();
}

void modelenemy::Draw(ViewProjection viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}
