#include "TextBoxComponent.h"
#include "../Objects/Actor.h"

#pragma comment(lib, "dwrite")
#pragma comment(lib, "d2d1")

TextBoxComponent::TextBoxComponent() {
	m_fontFamily = L"Arial";
	m_fontSize = 32;
	m_text = L"Text";
	m_textBoxSize = Vector2D(200, 32);
}

TextBoxComponent::~TextBoxComponent() {
	if (m_textFormat != NULL) {
		m_textFormat->Release();
		m_textFormat = NULL;
	}
	if (m_writeFactory != NULL) {
		m_writeFactory->Release();
		m_writeFactory = NULL;
	}
}

void TextBoxComponent::Init(Actor* actor, D2D1_COLOR_F color) {
	DrawableShapeComponent::Init(actor, color);


	ID2D1HwndRenderTarget* renderTarget = m_actor->GetRenderTarget();
	if (renderTarget != NULL) {
		D2D1_SIZE_F renderTargetSize = renderTarget->GetSize();
		UpdateShape();

		HRESULT hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&m_writeFactory));
		if (FAILED(hr)) return;

		UpdateTextFormat();
	}
}

void TextBoxComponent::UpdateShape() {
	Vector2D sizeMulti = Vector2D(
		m_actor->GetTransform()->GetScale().GetX() * m_transform.GetScale().GetX(),
		m_actor->GetTransform()->GetScale().GetY() * m_transform.GetScale().GetY());

	m_layoutRect = D2D1::RectF(
		m_actor->GetTransform()->GetPosition().GetX() + m_transform.GetPosition().GetX(),
		m_actor->GetTransform()->GetPosition().GetY() + m_transform.GetPosition().GetY() - (m_textBoxSize.GetY() * sizeMulti.GetY()) / 2.0f,
		m_actor->GetTransform()->GetPosition().GetX() + m_transform.GetPosition().GetX() + (m_textBoxSize.GetX() * sizeMulti.GetX()),
		m_actor->GetTransform()->GetPosition().GetY() + m_transform.GetPosition().GetY() + (m_textBoxSize.GetY() * sizeMulti.GetY()) / 2.0f
	);
}

void TextBoxComponent::Draw() {
	DrawableShapeComponent::Draw();
	ID2D1HwndRenderTarget* renderTarget = m_actor->GetRenderTarget();
	if (renderTarget != NULL) {
		renderTarget->DrawText(
			m_text.c_str(),           // Text to render
			static_cast<UINT32>(m_text.length()), // Text length
			m_textFormat,          // Text format
			&m_layoutRect,            // Layout rectangle
			m_brush                // Brush
		);
	}
}

void TextBoxComponent::UpdateTextFormat() {
	HRESULT hr = m_writeFactory->CreateTextFormat(
		m_fontFamily.c_str(),			// Font family name
		nullptr,						// Font collection (nullptr means use the system font collection)
		DWRITE_FONT_WEIGHT_REGULAR,		// Weight
		DWRITE_FONT_STYLE_NORMAL,		// Style
		DWRITE_FONT_STRETCH_NORMAL,		// Stretch
		m_fontSize,						// Size
		L"en-us",						// Locale
		&m_textFormat					// Text format object
	);
	if (FAILED(hr)) return;
}

void TextBoxComponent::BeginPlay() {
	DrawableShapeComponent::BeginPlay();
	UpdateShape();
}

void TextBoxComponent::EndPlay() {
	DrawableShapeComponent::EndPlay();
}

void TextBoxComponent::SetText(const std::wstring& text) {
	m_text = text;

}

void TextBoxComponent::SetFontFamily(const std::wstring& fontFamily) {
	m_fontFamily = fontFamily;
	UpdateTextFormat();
}


void TextBoxComponent::SetTextBoxSize(const Vector2D& textBoxSize) {
	m_textBoxSize = textBoxSize;
	UpdateTextFormat();
}


void TextBoxComponent::SetFontSize(const float fontSize) {
	m_fontSize = fontSize;
	UpdateTextFormat();
}