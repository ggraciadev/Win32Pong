#include "Pawn.h"
#include "PawnController.h"

Pawn::Pawn() {
	
}

Pawn::~Pawn() {

}


void Pawn::BeginPlay() {
	Actor::BeginPlay();
}

void Pawn::EndPlay() {
	Actor::EndPlay();
}

void Pawn::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}

void Pawn::SetPawnController(PawnController* pawnController) {
	m_pawnController = pawnController;
}

PawnController* Pawn::GetPawnController() const {
	return m_pawnController;
}