#pragma once
#include "DrawableShapeComponent.h"
#include <string>
#include <dwrite.h>


class TextBoxComponent : public DrawableShapeComponent
{

public:
	TextBoxComponent();
	virtual ~TextBoxComponent();

protected:

	std::wstring			m_text;								// Text to render
	std::wstring			m_fontFamily;						// Text font
	float					m_fontSize;							// Text size
	Vector2D				m_textBoxSize;						// Text box size

	IDWriteTextFormat*		m_textFormat = NULL;				// Text format
	IDWriteFactory*			m_writeFactory = NULL;				// Text factory
	D2D1_RECT_F				m_layoutRect = D2D1_RECT_F();		// Rectangle layout

/**
This event is called at the begining of the destructor method
 */
	virtual void EndPlay();

public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay();

/**
 * Initalize the DrawableShapeComponent with the reference of its owner and a inital transform
 *
 * Default Transform is at Position(0,0), Rotation(0) and Scale(1,1)
 *
 * @param actor:  a reference to the owner Actor.
 * @param transform: the position, rotation and scale relative to the relative actor this ActorComponent should start with
 * @param color: the initial color of the DrawableShape
 */
	virtual void Init(Actor* actor, D2D1_COLOR_F color);

/**
This event is for the rendering of the component if needed. This method should be overrided by every ActorComponent that uses it
*/
	virtual void Draw();

/**
This method is called just before Draw to update every shape positions.
*/
	virtual void UpdateShape();

	void UpdateTextFormat();

/**
* This method returns the value of the text
* @return The value of the text
*/
	inline std::wstring GetText() const { return m_text; }

/**
* This method is to set a new value to the text to reneder
* @param New vaue of the text
*/
	void SetText(const std::wstring& text);

/**
* This method returns the value of the font family
* @return The value of the font family
*/
	inline std::wstring GetFontFamily() const { return m_fontFamily; }

/**
* This method is to set a new value to the text to reneder
* @param New vaue of the text
* @param updateTextFormat (optional): if the text format should be updated or not (default = true)
*/
	void SetFontFamily(const std::wstring& fontFamily, bool updateTextFormat = true);
	

/**
* This method returns the value of the text box size
* @return The value of the text box size
*/
	inline Vector2D GetTextBoxSize() const { return m_textBoxSize; }

/**
* This method is to set a new value to the text to reneder
* @param New vaue of the text
* @param updateTextFormat (optional): if the text format should be updated or not (default = true)
*/
	void SetTextBoxSize(const Vector2D& textBoxSize, bool updateTextFormat = true);


	/**
	* This method returns the value of the font size
	* @return The value of the font size
	*/
	inline float GetFontSize() const { return m_fontSize; }

	/**
	* This method is to set a new value to the font size
	* @param New vaue of the font size
	* @param updateTextFormat (optional): if the text format should be updated or not (default = true)
	*/
	void SetFontSize(const float fontSize, bool updateTextFormat = true);

};