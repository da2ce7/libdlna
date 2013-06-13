/*
 * libdlna: reference DLNA standards implementation.
 * Copyright (C) 2007 Benjamin Zores <ben@geexbox.org>
 *
 * This file is part of libdlna.
 *
 * libdlna is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * libdlna is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with libdlna; if not, write to the Free Software
 * Foundation, Inc, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _DLNA_INTERNALS_H_
#define _DLNA_INTERNALS_H_

#if defined(__GNUC__)
#    define dlna_unused __attribute__((unused))
#else
#    define dlna_unused
#endif

#include "dlna.h"

#ifdef _WIN32
#ifndef DOT_ID
#define DOT_ID
#endif
#ifndef DOT_MIME
#define DOT_MIME
#endif
#ifndef DOT_LABEL
#define DOT_LABEL
#endif
#ifndef DOT_CLASS
#define DOT_CLASS
#endif
#ifndef DOT_EXTENSIONS
#define DOT_EXTENSIONS
#endif
#ifndef DOT_PROBE
#define DOT_PROBE
#endif
#ifndef DOT_NEXT
#define DOT_NEXT
#endif
#else
#ifndef DOT_ID
#define DOT_ID .id =
#endif
#ifndef DOT_MIME
#define DOT_MIME .mime =
#endif
#ifndef DOT_LABEL
#define DOT_LABEL .label =
#endif
#ifndef DOT_CLASS
#define DOT_CLASS .class =
#endif
#ifndef DOT_EXTENSIONS
#define DOT_EXTENSIONS .extensions =
#endif
#ifndef DOT_PROBE
#define DOT_PROBE .probe =
#endif
#ifndef DOT_NEXT
#define DOT_NEXT .next =
#endif
#endif

//////////////////////////////////
// C specific
#ifdef _WIN32
#ifndef S_ISREG
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif

#ifndef S_ISDIR
#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#endif

#ifndef strcasecmp
#define strcasecmp		_stricmp
#endif
#ifndef strncasecmp
#define strncasecmp		strnicmp
#endif

#ifndef sleep
#define sleep(a)		Sleep((a)*1000)
#endif
#ifndef usleep
#define usleep(a)		Sleep((a)/1000)
#endif
#ifndef strerror_r
#define strerror_r(a,b,c)	//(strerror_s((b),(c),(a)))
#endif

#else

#ifndef max
#define max(a, b)   (((a)>(b))? (a):(b))
#endif
#ifndef min
#define min(a, b)   (((a)<(b))? (a):(b))
#endif
#endif /* WIN32 */


/**
 * DLNA Library's controller.
 * This controls the whole library.
 */
struct dlna_s {
  /* has the library's been inited */
  int inited;
  /* defines verbosity level */
  int verbosity;
  /* defines flexibility on file extension's check */
  int check_extensions;
  /* linked-list of registered DLNA profiles */
  void *first_profile;
};

#endif /* _DLNA_INTERNALS_H_ */
