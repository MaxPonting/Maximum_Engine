#include "Input.h"

namespace ME
{
    void ME::Input::Update()
    {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

        m_KeyboardUp.reset();
        m_KeyboardDown.reset();
        
        for (int i = 0; i < MAX_KEYS; i++)
        {
            if (m_Keyboard[i] == false && keystates[i] == true)  m_KeyboardDown[i] = true;         
            else if (m_Keyboard[i] == true && keystates[i] == false) m_KeyboardUp[i] = true;          
            m_Keyboard[i] = keystates[i];
        }
    }

    bool ME::Input::GetKey(unsigned char code)
    {
        if (code >= MAX_KEYS) return false;
        return m_Keyboard[code];
    }

    bool ME::Input::GetKeyUp(unsigned char code)
    {
        if (code >= MAX_KEYS) return false;
        return m_KeyboardUp[code];
    }

    bool ME::Input::GetKeyDown(unsigned char code)
    {
        if (code >= MAX_KEYS) return false;
        return m_KeyboardDown[code];
    }
}

