#include "ScoreBoard.h"


ScoreBoard::ScoreBoard() {
	
}

ScoreBoard::~ScoreBoard() {

}


void ScoreBoard::BeginPlay() {
	TextBoxActor::BeginPlay();

	m_textBoxComponent->SetText(L"" + std::to_wstring(0) + L" - " + std::to_wstring(0));
	m_textBoxComponent->SetFontFamily(L"Impact", false);
	m_textBoxComponent->SetFontSize(50, false);
	m_gameManager = MyGameManager::GetInstance<MyGameManager>();
	UpdateScoreBoardPosition();
}

void ScoreBoard::EndPlay() {
	TextBoxActor::EndPlay();
}

void ScoreBoard::Tick(float deltaTime) {
	TextBoxActor::Tick(deltaTime);
	UpdateScoreBoardText();
}

void ScoreBoard::UpdateScoreBoardText() {
	m_textBoxComponent->SetText(L"" + std::to_wstring(m_gameManager->GetScorePlayerA()) + L" - " + std::to_wstring(m_gameManager->GetScorePlayerB()));
}

void ScoreBoard::UpdateScoreBoardPosition() {
	Vector2D screenSize = m_gameManager->GetWindowSize();
	Vector2D textBoxSize(150, 50);
	m_textBoxComponent->SetTextBoxSize(textBoxSize, true);

	m_transform.SetPosition(Vector2D(screenSize.GetX() / 2 - textBoxSize.GetX() / 2, 50));
}