/************************************************
 *				 SDL_image.h					*
 *************************************************/
#ifdef INCLUDE_SDL_IMAGE
#ifdef _WIN32
#include <SDL2/SDL_image.h>
#elif __APPLE__
#include "TargetConditionals.h"
#include <SDL2/SDL_image.h>
#elif __linux__
#include <SDL2/SDL_image.h>
#else
#error "Unknown compiler"
#endif
#undef INCLUDE_SDL_IMAGE
#endif // INCLUDE_SDL_IMAGE

/************************************************
 *				 SDL_mixer.h					*
 *************************************************/
#ifdef INCLUDE_SDL_MIXER
#ifdef _WIN32
#include <SDL2/SDL_mixer.h>
#elif __APPLE__
#include "TargetConditionals.h"
#include <SDL2/SDL_mixer.h>
#elif __linux__
#include <SDL2/SDL_mixer.h>
#else
#error "Unknown compiler"
#endif
#undef INCLUDE_SDL_MIXER
#endif // INCLUDE_SDL_MIXER