#include "MyAIController.h"
#include "Paddle.h"
#include "Ball.h"
#include "../Managers/MyGameManager.h"
#include "../../Engine/Utils/Utils.h"

void MyAIController::OnPossess() {
	m_paddle = (Paddle*)(m_pawn);
	m_gameManger = MyGameManager::GetInstance<MyGameManager>();
}

void MyAIController::SetBall(Ball* ball) {
	m_ball = ball;
}

void MyAIController::UpdateAIState(float deltaTime) {
	if (m_ball->GetTransform()->GetPosition().GetX() > m_gameManger->GetWindowSize().GetX() / 2) {
		float inputY = m_ball->GetTransform()->GetPosition().GetY() - m_paddle->GetTransform()->GetPosition().GetY();
		inputY = inputY * (m_ball->GetTransform()->GetPosition().GetX() / m_gameManger->GetWindowSize().GetX()) / 50;
		m_paddle->SetInputY(CLAMP(inputY, -0.8f, 0.8f));
	}
	else {
		m_paddle->SetInputY(0);
	}
}