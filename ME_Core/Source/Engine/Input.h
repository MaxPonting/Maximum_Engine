#pragma once

#include <bitset>

#include <SDL.h>

#include "../Helper/Vector2i.h"
//
// Maximum number of keys
//
#define MAX_KEYS 100

namespace ME
{
	//
	// Stores which keys are currenly pressed, which keys have just been pressed and which keys have just been released.
	// This data can be retrieved by calling the getter methods.
	// Updates every frame.
	//
	class Input
	{
	public:

		Input() = default;

		void UpdateMouse();
		void Update();
		void MouseDown(Uint8 index);
		void MouseUp(Uint8 index);
		void MouseWheel(float value);

		bool GetKey(unsigned char code);
		bool GetKeyUp(unsigned char code);
		bool GetKeyDown(unsigned char code);

		bool GetMouse(unsigned char index);
		bool GetMouseUp(unsigned char index);
		bool GetMouseDown(unsigned char index);

		Vector2i GetMousePosition();

		float GetMouseWheel();

	private:

		std::bitset<MAX_KEYS> m_Keyboard;
		std::bitset<MAX_KEYS> m_KeyboardUp;
		std::bitset<MAX_KEYS> m_KeyboardDown;
		std::bitset<3> m_Mouse;
		std::bitset<3> m_MouseUp;
		std::bitset<3> m_MouseDown;
		Vector2i mousePosition;
		float mouseWheel;
	};
}

//
// Keycodes
// 

//
// Numbers
//
#define ME_KEYCODE_0 SDL_SCANCODE_0
#define ME_KEYCODE_1 SDL_SCANCODE_1
#define ME_KEYCODE_2 SDL_SCANCODE_2
#define ME_KEYCODE_3 SDL_SCANCODE_3
#define ME_KEYCODE_4 SDL_SCANCODE_4
#define ME_KEYCODE_5 SDL_SCANCODE_5
#define ME_KEYCODE_6 SDL_SCANCODE_6
#define ME_KEYCODE_7 SDL_SCANCODE_7
#define ME_KEYCODE_8 SDL_SCANCODE_8
#define ME_KEYCODE_9 SDL_SCANCODE_9

//
// Characters
//
#define ME_KEYCODE_A SDL_SCANCODE_A
#define ME_KEYCODE_B SDL_SCANCODE_B
#define ME_KEYCODE_C SDL_SCANCODE_C
#define ME_KEYCODE_D SDL_SCANCODE_D
#define ME_KEYCODE_E SDL_SCANCODE_E
#define ME_KEYCODE_F SDL_SCANCODE_F
#define ME_KEYCODE_G SDL_SCANCODE_G
#define ME_KEYCODE_H SDL_SCANCODE_H
#define ME_KEYCODE_I SDL_SCANCODE_I
#define ME_KEYCODE_J SDL_SCANCODE_J
#define ME_KEYCODE_K SDL_SCANCODE_K
#define ME_KEYCODE_L SDL_SCANCODE_L
#define ME_KEYCODE_M SDL_SCANCODE_M
#define ME_KEYCODE_N SDL_SCANCODE_N
#define ME_KEYCODE_O SDL_SCANCODE_O
#define ME_KEYCODE_P SDL_SCANCODE_P
#define ME_KEYCODE_Q SDL_SCANCODE_Q
#define ME_KEYCODE_R SDL_SCANCODE_R
#define ME_KEYCODE_S SDL_SCANCODE_S
#define ME_KEYCODE_T SDL_SCANCODE_T
#define ME_KEYCODE_U SDL_SCANCODE_U
#define ME_KEYCODE_V SDL_SCANCODE_V
#define ME_KEYCODE_W SDL_SCANCODE_W
#define ME_KEYCODE_X SDL_SCANCODE_X
#define ME_KEYCODE_Y SDL_SCANCODE_Y
#define ME_KEYCODE_Z SDL_SCANCODE_Z

//
// Arrows
//
#define ME_KEYCODE_UP SDL_SCANCODE_UP
#define ME_KEYCODE_DOWN SDL_SCANCODE_DOWN
#define ME_KEYCODE_LEFT SDL_SCANCODE_LEFT
#define ME_KEYCODE_RIGHT SDL_SCANCODE_RIGHT

//
// Misc
//
#define ME_KEYCODE_SPACE SDL_SCANCODE_SPACE
#define ME_KEYCODE_LSHIFT SDL_SCANCODE_LSHIFT
#define ME_KEYCODE_RSHIFT SDL_SCANCODE_RSHIFT
#define ME_KEYCODE_LCTRL SDL_SCANCODE_LCTRL
#define ME_KEYCODE_RCTRL SDL_SCANCODE_RCTRL
#define ME_KEYCODE_TAB SDL_SCANCODE_TAB
#define ME_KEYCODE_ESCAPE SDL_SCANCODE_ESCAPE

//
// F Numbers
//
#define ME_KEYCODE_F1 SDL_SCANCODE_F1
#define ME_KEYCODE_F2 SDL_SCANCODE_F2
#define ME_KEYCODE_F3 SDL_SCANCODE_F3
#define ME_KEYCODE_F4 SDL_SCANCODE_F4
#define ME_KEYCODE_F5 SDL_SCANCODE_F5
#define ME_KEYCODE_F6 SDL_SCANCODE_F6
#define ME_KEYCODE_F7 SDL_SCANCODE_F7
#define ME_KEYCODE_F8 SDL_SCANCODE_F8
#define ME_KEYCODE_F9 SDL_SCANCODE_F9
