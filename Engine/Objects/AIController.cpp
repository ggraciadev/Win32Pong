#include "AIController.h"

AIController::AIController() {

}

AIController::~AIController() {

}


void AIController::BeginPlay() {
	PawnController::BeginPlay();
}

void AIController::EndPlay() {
	PawnController::EndPlay();
}

void AIController::Tick(float deltaTime) {
	if (m_pawn != NULL) {
		PawnController::Tick(deltaTime);
		UpdateAIState(deltaTime);
	}
}