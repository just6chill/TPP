
#ifndef FRAMEWORK_EXPORT_H
#define FRAMEWORK_EXPORT_H

#ifdef SHARED_EXPORTS_BUILD_AS_STATIC
#  define FRAMEWORK_EXPORT
#  define FRAMEWORK_NO_EXPORT
#else
#  ifndef FRAMEWORK_EXPORT
#    ifdef Framework_EXPORTS
        /* We are building this library */
#      define FRAMEWORK_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define FRAMEWORK_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef FRAMEWORK_NO_EXPORT
#    define FRAMEWORK_NO_EXPORT 
#  endif
#endif

#ifndef FRAMEWORK_DEPRECATED
#  define FRAMEWORK_DEPRECATED __declspec(deprecated)
#endif

#ifndef FRAMEWORK_DEPRECATED_EXPORT
#  define FRAMEWORK_DEPRECATED_EXPORT FRAMEWORK_EXPORT FRAMEWORK_DEPRECATED
#endif

#ifndef FRAMEWORK_DEPRECATED_NO_EXPORT
#  define FRAMEWORK_DEPRECATED_NO_EXPORT FRAMEWORK_NO_EXPORT FRAMEWORK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef FRAMEWORK_NO_DEPRECATED
#    define FRAMEWORK_NO_DEPRECATED
#  endif
#endif

#endif /* FRAMEWORK_EXPORT_H */
