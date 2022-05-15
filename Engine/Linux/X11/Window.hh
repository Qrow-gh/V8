//
// Created by mbracker on 5/14/22.
//

#ifndef V8_WINDOW_HH
#define V8_WINDOW_HH

#include <Win/IWin.hh>
#include <xcb/xcb.h>

namespace V8::Linux
{
    class CWindow : public IWin
    {

    public:

        CWindow();
        ~CWindow();

        void OpenWindow( const char* pWindowName ) override;
        void OpenWindow( char* pWindowName ) override;

        void CloseWindow() override;

        unsigned int GetX() override;
        unsigned int GetY() override;

        void SetX( int x ) override;
        void SetY( int y ) override;

        void* GetNativeWindow() override;

        void WindowUpdate( bool& ) override;

    private:

        void mXOpenWindow();

        xcb_connection_t* m_pServerConnection;
        xcb_screen_t* m_pScreen;
        xcb_window_t m_pWindow;

        unsigned int mWmDeleteWindow;
        unsigned int mWmProtoc;

    };
}

#endif //V8_WINDOW_HH
