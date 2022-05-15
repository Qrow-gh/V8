//
// Created by mbracker on 5/14/22.
//

#ifndef V8_IGFX_HH
#define V8_IGFX_HH

#include <Core.hh>

namespace V8
{
    class IWin;

    class V8_EXPORT IGfx
    {

    public:

        IGfx() = default;
        virtual inline ~IGfx() = default;

        virtual void Init( IWin* ) = 0;
        virtual void DeInit() = 0;

        // TODO: Define Interface :V

    private:



    protected:



    };
}

#endif //V8_IGFX_HH
