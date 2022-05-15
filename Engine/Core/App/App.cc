//
// Created by mbracker on 5/14/22.
//

#include "App.hh"

namespace V8
{

    CApp::CApp( IWin* pWindow, IGfx* pGfx )
    {
        mIsRunning = true;
        m_pWin = pWindow;
        m_pGfx = pGfx;
    }

    void CApp::Run()
    {
        this->m_pWin->OpenWindow( m_pAppName );
        this->m_pGfx->Init( m_pWin );

        while(mIsRunning)
        {
            this->m_pWin->WindowUpdate( mIsRunning );
        }

        this->m_pWin->CloseWindow();
    }
}
