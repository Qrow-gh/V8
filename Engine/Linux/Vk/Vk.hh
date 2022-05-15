//
// Created by mbracker on 5/15/22.
//

#ifndef V8_VK_HH
#define V8_VK_HH

#define VK_USE_PLATFORM_XCB_KHR 1 // Enable VK_KHR_XCB_SURFACE_EXTENSION_NAME

#include <Gfx/IGfx.hh>
#include <Win/IWin.hh>
#include <xcb/xcb.h> // we have to hold a connection to the x server
#include <vulkan/vulkan.hpp>

namespace V8::Linux
{
    class CVk : public V8::IGfx
    {

    public:

        void Init( IWin* ) override;
        void DeInit() override;

    private:

        xcb_connection_t* m_pServerConnection; // we have to hold a connection to the x server
        VkInstance m_hVkInstance;

    };
}

#endif //V8_VK_HH
