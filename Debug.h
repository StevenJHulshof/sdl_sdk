#pragma once

#include <stdio.h>
#include <stdarg.h>

#define DEBUG_ALLOC_ENABLE 0
#define DEBUG_ALLOC_COMP_ENABLE 0
#define DEBUG_ALLOC_GAME_OBJECT_ENABLE 1

#define DEBUG_FUN_VAR_ENABLE 0

/** Macro to enable disable memory usage of the Debug class. */
#if DEBUG_ALLOC_ENABLE
#define DEBUG_ALLOC(f_, ...) printf((f_), __VA_ARGS__)
#else
#define DEBUG_ALLOC(f_, ...)
#endif

/** Macro to enable disable memory usage of the Debug class. */
#if DEBUG_FUN_VAR_ENABLE
#define DEBUG_FUN_VAR(f_, ...) printf((f_), __VA_ARGS__)
#else
#define DEBUG_FUN_VAR(f_, ...)
#endif

/** Macro to enable disable memory usage of the Debug class. */
#if DEBUG_FUN_VAR_ENABLE
#define DEBUG_FUN_VAR_COUT(out) std::cout << out;
#else
#define DEBUG_FUN_VAR_COUT(out)
#endif