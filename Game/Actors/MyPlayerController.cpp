#include "MyPlayerController.h"
#include "Paddle.h"

void MyPlayerController::RegisterInputs() {
	RegisterKey('W');
	RegisterKey('S');
}

void MyPlayerController::OnPossess() {
	m_paddle = (Paddle*)(m_pawn);
}

void MyPlayerController::UpdateInput() {
	if (m_paddle != NULL) {
		if (GetKeyPressed('W')) {
			m_paddle->SetInput(-1);
		}
		else if (GetKeyPressed('S')) {
			m_paddle->SetInput(1);
		}
		else {
			m_paddle->SetInput(0);
		}
	}
}
