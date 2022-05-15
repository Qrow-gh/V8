//
// Created by mbracker on 5/14/22.
//

#ifndef V8_V8_HH
#define V8_V8_HH

#include <Core.hh>
#include <App/App.hh>
#include <Gfx/IGfx.hh>

#ifdef __V8_PLATFORM_LINUX__

#include <X11/Window.hh>
#include <Vk/Vk.hh>

int main( int argc, char** argv )
{
    auto pCVk = new V8::Linux::CVk;
    auto pCWindow = new V8::Linux::CWindow;

    auto App = V8::CreateApp( pCWindow, pCVk );

    App->Run();

    delete App;

    delete pCVk;
    delete pCWindow;

    return 0;
}

#endif //__V8_PLATFORM_LINUX__

#endif //V8_V8_HH
