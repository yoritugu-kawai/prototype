#pragma once
#include"mathh.h"
#include<Model.h>
#include<WorldTransform.h>
class Enemy  {
public:
	void Initialize(Model* model, 
		uint32_t textureHandle, float x, float y, float kCharacterSpeedx,
	    float kCharacterSpeedy);

	void Update();

	void Draw(ViewProjection viewProjection_);

private:
	
	WorldTransform worldTransform_;

	Model* model_ = nullptr;
	uint32_t textureHandle_ = 0u;

	float kCharacterSpeedX_ = 0;
	float kCharacterSpeedY_ = 0;
	Vector3 move = {0, 0, 0};

};
