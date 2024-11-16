#include "PlayerController.h"
#include "../Managers/GameManager.h"

PlayerController::PlayerController() {

}

PlayerController::~PlayerController() {

}


void PlayerController::BeginPlay() {
	PawnController::BeginPlay();
	m_inputManager = GameManager::GetInstance<GameManager>()->GetInputManager();
	RegisterInputs();
}

void PlayerController::EndPlay() {
	PawnController::EndPlay();
}

void PlayerController::Tick(float deltaTime) {
	if (m_pawn != NULL) {
		PawnController::Tick(deltaTime);
		UpdateInput();
	}
}

void PlayerController::RegisterKey(BYTE key) {
	m_inputManager->RegisterKey(key);
}

bool PlayerController::GetKeyPressed(BYTE key) {
	return m_inputManager->GetKeyPressed(key);
}

bool PlayerController::GetKeyUp(BYTE key) {
	return m_inputManager->GetKeyUp(key);
}

bool PlayerController::GetKeyDown(BYTE key) {
	return m_inputManager->GetKeyUp(key);
}