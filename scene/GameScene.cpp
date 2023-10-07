#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	textureHandle_ = TextureManager::Load("enemy.png");
	model_ = Model::Create();
	
	viewProjection_.Initialize();

	enemmy = Model::CreateFromOBJ("enemy" ,true);
	enemyy = new modelenemy;
	enemyy->Initialize(enemmy);
	
	enemy_[0] = new Enemy;
	enemy_[1] = new Enemy;
	enemy_[2] = new Enemy;
	enemy_[3] = new Enemy;
	enemy_[4] = new Enemy;
	enemy_[5] = new Enemy;


	enemy_[0]->Initialize(model_,textureHandle_, -22, 0,-0.5f,0.05f);
	enemy_[1]->Initialize(model_,textureHandle_, 10, -10,0.5f,-0.5f);
	enemy_[2]->Initialize(model_,textureHandle_, -23, -20,-0.5f,-0.5f);
	enemy_[3]->Initialize(model_,textureHandle_, 0, 0,0.5f,0.5f);
	enemy_[4]->Initialize(model_,textureHandle_, -30, -10,-0.5f,0.5f);
	enemy_[5]->Initialize(model_,textureHandle_, 20, 5,0.5f,-0.5f);
}

void GameScene::Update() {
	enemy_[0]->Update(); 
	enemy_[1]->Update(); 
	enemy_[2]->Update(); 
	enemy_[3]->Update(); 
	enemy_[4]->Update(); 
	enemy_[5]->Update(); 

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	/*enemy_[0]->Draw(viewProjection_);
	enemy_[1]->Draw(viewProjection_);
	enemy_[2]->Draw(viewProjection_);
	enemy_[3]->Draw(viewProjection_);
	enemy_[4]->Draw(viewProjection_);
	enemy_[5]->Draw(viewProjection_);*/

	enemyy->Draw(viewProjection_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
