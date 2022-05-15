//
// Created by mbracker on 5/14/22.
//

#ifndef V8_APP_HH
#define V8_APP_HH

#include <Core.hh>

#include <Win/IWin.hh>
#include <Gfx/IGfx.hh>

namespace V8
{
    class V8_EXPORT CApp
    {

    public:

        CApp( IWin*, IGfx* );
        virtual inline ~CApp() = default;

        void Run();

    private:

        bool mIsRunning;

    protected:

        IWin* m_pWin;
        IGfx* m_pGfx;
        const char* m_pAppName;

    };

    extern CApp* CreateApp( IWin*, IGfx* );

}

#endif //V8_APP_HH
