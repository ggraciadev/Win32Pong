#include "MyPlayerController.h"
#include "Paddle.h"

void MyPlayerController::RegisterInputs() {
	RegisterKey('W');
	RegisterKey('S');
	RegisterKey('A');
	RegisterKey('D');
}

void MyPlayerController::OnPossess() {
	m_paddle = (Paddle*)(m_pawn);
}

void MyPlayerController::UpdateInput() {
	if (m_paddle != NULL) {
		if (GetKeyPressed('W')) {
			m_paddle->SetInputY(-1);
		}
		else if (GetKeyPressed('S')) {
			m_paddle->SetInputY(1);
		}
		else {
			m_paddle->SetInputY(0);
		}
		if (GetKeyPressed('A')) {
			m_paddle->SetInputX(-1);
		}
		else if (GetKeyPressed('D')) {
			m_paddle->SetInputX(1);
		}
		else {
			m_paddle->SetInputX(0);
		}
	}
}
