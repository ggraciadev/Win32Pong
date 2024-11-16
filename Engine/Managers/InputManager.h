#pragma once
#include "../Objects/Scene.h"
#include <map>

typedef struct KeyState {
	bool currentState = false;
	bool lastState = false;
} KeyState;

class InputManager {

public:
	InputManager();
	friend class GameManager;

protected:
	virtual ~InputManager();

	std::map<BYTE, KeyState> m_keyState;	// current key states

	void UpdateInputState();

public:
/**
 To register a new key to be listened
 */
	void RegisterKey(BYTE key);

/**
 * This method is used to know if a key, previously registered, is being pressed
 * @param key: The key index
 * @return If the key is being pressed
 */
	bool GetKeyPressed(BYTE key);

/**
* This method is used to know if a key, previously registered, is being just released
* @param key: The key index
* @return If the key is being just released
*/
	bool GetKeyUp(BYTE key);

/**
* This method is used to know if a key, previously registered, is being just pressed
* @param key: The key index
* @return If the key is being just pressed
*/
	bool GetKeyDown(BYTE key);


};
