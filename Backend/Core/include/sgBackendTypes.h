//
//  sgBackendTypes.h
//  sgsdl2
//
//  Created by Andrew Cain on 20/11/2013.
//  Copyright (c) 2013 Andrew Cain. All rights reserved.
//

#ifndef sgsdl2_sgBackendTypes_h
#define sgsdl2_sgBackendTypes_h

//
// A list of the available kinds of drawing surface.
// Drivers must support drawing onto these.
//
enum sg_drawing_surface_kind
{
    SGDS_Unknown,   // Unknown, so do not draw onto this!
    SGDS_Window,    // A window
    SGDS_Bitmap     // A surface, bitmap, or texture
};

//
// A drawing surface is something the user can draw onto.
// The driver is then required to provide the ability to
// perform the requested drawing actions on the different
// kinds of drawing surface.
//
typedef struct sg_drawing_surface
{
    sg_drawing_surface_kind kind;
    int width;
    int height;
    
    // private data used by the backend
    void * _data;
} sg_drawing_surface;


typedef struct sg_mode
{
    int width, height;
} sg_mode;

typedef struct sg_display
{
    const char *    name;
    int             x, y;
    int             width, height;
    int             num_modes;
    sg_mode *       modes;
    
    // private data used by the backend
    void * _data;
} sg_display;

typedef struct sg_audiospec
{
    int audio_rate;
    int audio_format;
    int audio_channels;
    int times_opened;

} sg_audiospec;

typedef struct sg_system_data
{
    int             num_displays;
    sg_display    * displays;
    sg_audiospec    audio_specs;
    
} sg_system_data;


enum sg_sound_kind
{
    SGSD_UNKNOWN = 0,
    SGSD_SOUND_EFFECT = 1,
    SGSD_MUSIC = 2
};

//
// Sound data is an audio chunk the user can play.
//
typedef struct sg_sound_data
{
    sg_sound_kind kind;
    
    // private data used by backend
    void * data;
} sg_sound_data;

#endif