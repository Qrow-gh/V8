//
// Created by mbracker on 5/14/22.
//

#ifndef V8_IWIN_HH
#define V8_IWIN_HH

#include <Core.hh>

namespace V8
{
    class V8_EXPORT IWin
    {

    public:

        virtual void OpenWindow( const char* pWindowName ) = 0;
        virtual void OpenWindow( char* pWindowName ) = 0;
        virtual void CloseWindow() = 0;

        virtual unsigned int GetX() = 0;
        virtual unsigned int GetY() = 0;

        virtual void SetX( int x ) = 0;
        virtual void SetY( int y ) = 0;

        virtual void* GetNativeWindow() = 0;

        virtual void WindowUpdate( bool& ) = 0;

    private:



    protected:



    };
}

#endif //V8_IWIN_HH
