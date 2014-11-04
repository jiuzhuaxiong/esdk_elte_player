// $Id: config-macosx-iphone-hardware.h 93117 2011-01-20 12:11:28Z mcorino $
#ifndef ACE_CONFIG_MACOSX_IPHONE_HARDWARE_H
#define ACE_CONFIG_MACOSX_IPHONE_HARDWARE_H

#define ACE_HAS_IPHONE
#define ACE_SIZEOF_LONG_DOUBLE 8

#include "ace/config-macosx-snowleopard.h"

#ifdef ACE_HAS_SYSV_IPC
#undef ACE_HAS_SYSV_IPC
#endif

#endif ACE_CONFIG_MACOSX_IPHONE_HARDWARE_H
