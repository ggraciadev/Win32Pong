#include "PawnController.h"
#include "Pawn.h"

PawnController::PawnController() {

}

PawnController::~PawnController() {

}


void PawnController::BeginPlay() {
	Actor::BeginPlay();
}

void PawnController::EndPlay() {
	Actor::EndPlay();
}

void PawnController::Tick(float deltaTime) {
	if (m_pawn != NULL) {
		Actor::Tick(deltaTime);
	}
}

void PawnController::Possess(Pawn* pawn) {
	if (pawn == NULL) { return; }
	if (m_pawn != NULL) {
		UnPossess();
	}
	m_pawn = pawn;
	m_pawn->SetPawnController(this);
	OnPossess();
}

void PawnController::UnPossess() {
	if (m_pawn != NULL) {
		m_pawn->SetPawnController(NULL);
		m_pawn = NULL;
	}
}

Pawn* PawnController::GetPawn() const {
	return m_pawn;
}