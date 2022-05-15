//
// Created by mbracker on 5/15/22.
//

#include "Vk.hh"
#include <vector> // Todo: Make a custom vector class :V

namespace V8::Linux
{
    void CVk::Init( IWin* pWindow )
    {
        auto r_pWindow = pWindow->GetNativeWindow(); // raw window pointer
        m_pServerConnection = xcb_connect( nullptr, nullptr );

        VkApplicationInfo sVkAppInfo
        {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName = "V8",
            .applicationVersion = VK_MAKE_VERSION( 1, 0, 0 ),
            .pEngineName = "V8",
            .engineVersion = VK_MAKE_VERSION( 1, 0, 0 ),
            .apiVersion = VK_API_VERSION_1_3,
        };

        std::vector<const char*> ppExtensions = { VK_KHR_SURFACE_EXTENSION_NAME };

        ppExtensions.push_back( VK_KHR_XCB_SURFACE_EXTENSION_NAME );

        VkInstanceCreateInfo sVkInstanceInfo
        {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0,
            .pApplicationInfo = &sVkAppInfo,
        };

        sVkInstanceInfo.enabledExtensionCount = ppExtensions.size();
        sVkInstanceInfo.ppEnabledExtensionNames = ppExtensions.data();

        vkCreateInstance( &sVkInstanceInfo, nullptr, &m_hVkInstance ); // Todo: Make A Memory Allocator



    }

    void CVk::DeInit()
    {
        vkDestroyInstance( m_hVkInstance, nullptr );
    }
}