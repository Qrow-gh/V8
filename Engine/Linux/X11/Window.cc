//
// Created by mbracker on 5/14/22.
//

#include "Window.hh"
#include <cstring>

namespace V8::Linux
{
    CWindow::CWindow()
    {
        m_pServerConnection = xcb_connect( nullptr, nullptr );

        auto sItr = xcb_setup_roots_iterator( xcb_get_setup(m_pServerConnection) );
        for ( int lcount = 0; lcount > 0; lcount-- ) { xcb_screen_next(&sItr); }

        m_pScreen = sItr.data;

        m_pWindow = xcb_generate_id( m_pServerConnection );
    }

    CWindow::~CWindow()
    {
        xcb_disconnect( m_pServerConnection );
    }

    void CWindow::OpenWindow( const char* pWindowName )
    {
        this->mXOpenWindow();
        xcb_change_property
        (
            m_pServerConnection,
            XCB_PROP_MODE_REPLACE,
            m_pWindow,
            XCB_ATOM_WM_NAME,
            XCB_ATOM_STRING,
            8,
            std::strlen(pWindowName),
            pWindowName
        );
        xcb_map_window( m_pServerConnection, m_pWindow );
        xcb_flush( m_pServerConnection );
    }

    void CWindow::OpenWindow( char* pWindowName )
    {
        this->mXOpenWindow();
        xcb_change_property
        (
            m_pServerConnection,
            XCB_PROP_MODE_REPLACE,
            m_pWindow,
            XCB_ATOM_WM_NAME,
            XCB_ATOM_STRING,
            8,
            std::strlen(pWindowName),
            pWindowName
        );
        xcb_map_window( m_pServerConnection, m_pWindow );
        xcb_flush( m_pServerConnection );
    }

    void CWindow::CloseWindow()
    {
        xcb_destroy_window( m_pServerConnection, m_pWindow );
    }

    unsigned int CWindow::GetX()
    {
        return 0; // TODO: Get X
    }

    unsigned int CWindow::GetY()
    {
        return 0; // TODO: Get Y
    }

    void CWindow::SetX(int x)
    {
        //TODO: Set X
    }

    void CWindow::SetY(int y)
    {
        //TODO: Set Y
    }

    void* CWindow::GetNativeWindow()
    {
        return reinterpret_cast<void*>(m_pWindow);
    }

    void CWindow::WindowUpdate( bool& mIsRunning )
    {
        xcb_generic_event_t* evnt = xcb_wait_for_event( m_pServerConnection );

        switch( evnt->response_type & ~0x80 )
        {
            case XCB_CLIENT_MESSAGE:
                auto cm = reinterpret_cast<xcb_client_message_event_t*>(evnt);
                if ( cm->data.data32[0] == mWmDeleteWindow ) { mIsRunning = false; return; }
                break;
        }
        delete evnt;
    }

    void CWindow::mXOpenWindow()
    {
        auto cWmDelete = xcb_intern_atom( m_pServerConnection, 0, strlen("WM_DELETE_WINDOW"), "WM_DELETE_WINDOW" );
        auto cWmProtoc = xcb_intern_atom( m_pServerConnection, 0, strlen("WM_PROTOCOLS"), "WM_PROTOCOLS" );
        auto rWmDelete = xcb_intern_atom_reply( m_pServerConnection, cWmDelete, nullptr );
        auto rWmProtoc = xcb_intern_atom_reply( m_pServerConnection, cWmProtoc, nullptr );
        mWmProtoc = rWmProtoc->atom;
        mWmDeleteWindow = rWmDelete->atom;

        uint32_t ValList[] = { m_pScreen->black_pixel, 0 };
        xcb_create_window
        (
            m_pServerConnection,
            XCB_COPY_FROM_PARENT,
            m_pWindow,
            m_pScreen->root,
            0, 0,
            800, 600, // 800x600 by default
            0,
            XCB_WINDOW_CLASS_INPUT_OUTPUT,
            m_pScreen->root_visual,
            XCB_CW_BACK_PIXEL|XCB_CW_EVENT_MASK,
            ValList
        );
        xcb_change_property
        (
            m_pServerConnection,
            XCB_PROP_MODE_REPLACE,
            m_pWindow,
            rWmProtoc->atom,
            4, 32, 1,
            &rWmDelete->atom
        );
    }
}
