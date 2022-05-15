//
// Created by mbracker on 5/14/22.
//

#include <v8.hh>
#include <iostream>

class Ignite : public V8::CApp
{

public:

    Ignite( V8::IWin* pWin, V8::IGfx* pGfx )
        : V8::CApp{ pWin, pGfx }
    {
        m_pAppName = "Ignite";
    }

    ~Ignite() override
    {
        m_pAppName = nullptr;
    }

};

V8::CApp* V8::CreateApp( V8::IWin* pWin, V8::IGfx* pGfx )
{
    return new Ignite{ pWin, pGfx };
}
