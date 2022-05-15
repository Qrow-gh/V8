//
// Created by mbracker on 5/14/22.
//

#ifndef V8_EXPORT_HH
#define V8_EXPORT_HH

#ifdef __V8_PLATFORM_LINUX__

#define V8_EXPORT __attribute__((visibility("default")))
#define V8_IMPORT

#endif //__V8_PLATFORM_LINUX__

#endif //V8_EXPORT_HH
