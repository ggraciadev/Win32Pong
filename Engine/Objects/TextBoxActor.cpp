#include "TextBoxActor.h"

TextBoxActor::TextBoxActor() {
	m_textBoxComponent = AddActorComponent<TextBoxComponent>();
	
}

TextBoxActor::~TextBoxActor() {

}


void TextBoxActor::BeginPlay() {
	Actor::BeginPlay();
	m_textBoxComponent->SetColor(D2D1::ColorF(0,0,0));
}

void TextBoxActor::EndPlay() {
	Actor::EndPlay();
}

void TextBoxActor::Tick(float deltaTime) {
	Actor::Tick(deltaTime);
}