#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

void InputManager::UpdateInputState() {
	for (auto key = m_keyState.begin(); key != m_keyState.end(); key++) {
		key->second.lastState = key->second.currentState;
		key->second.currentState = GetKeyState(key->first) & 0x8000; //this mask of bits give us the current state of the key
		if (key->second.currentState) {
			int i = 0;
		}
	}
}

void InputManager::RegisterKey(BYTE key) {
	if (m_keyState.find(key) != m_keyState.end()) { //if it's already registered we don't want to add it again
		return;
	}
	m_keyState.emplace(std::make_pair(key, KeyState()));
}

bool InputManager::GetKeyPressed(BYTE key) {
	if (m_keyState.find(key) == m_keyState.end()) { //if it's not registered it will return false
		return false;
	}
	bool result = m_keyState[key].currentState;
	return result;
}

bool InputManager::GetKeyUp(BYTE key) {
	if (m_keyState.find(key) == m_keyState.end()) { //if it's not registered it will return false
		return false;
	}
	return !GetKeyPressed(key) && m_keyState[key].lastState;
}

bool InputManager::GetKeyDown(BYTE key) {
	if (m_keyState.find(key) == m_keyState.end()) { //if it's not registered it will return false
		return false;
	}
	return GetKeyPressed(key) && !m_keyState[key].lastState;
}