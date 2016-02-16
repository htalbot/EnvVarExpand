
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl ENVVAREXPAND
// ------------------------------
#ifndef ENVVAREXPAND_EXPORT_H
#define ENVVAREXPAND_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ENVVAREXPAND_HAS_DLL)
#  define ENVVAREXPAND_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ENVVAREXPAND_HAS_DLL */

#if !defined (ENVVAREXPAND_HAS_DLL)
#  define ENVVAREXPAND_HAS_DLL 1
#endif /* ! ENVVAREXPAND_HAS_DLL */

#if defined (ENVVAREXPAND_HAS_DLL) && (ENVVAREXPAND_HAS_DLL == 1)
#  if defined (ENVVAREXPAND_BUILD_DLL)
#    define ENVVAREXPAND_Export ACE_Proper_Export_Flag
#    define ENVVAREXPAND_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ENVVAREXPAND_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ENVVAREXPAND_BUILD_DLL */
#    define ENVVAREXPAND_Export ACE_Proper_Import_Flag
#    define ENVVAREXPAND_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ENVVAREXPAND_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ENVVAREXPAND_BUILD_DLL */
#else /* ENVVAREXPAND_HAS_DLL == 1 */
#  define ENVVAREXPAND_Export
#  define ENVVAREXPAND_SINGLETON_DECLARATION(T)
#  define ENVVAREXPAND_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ENVVAREXPAND_HAS_DLL == 1 */

// Set ENVVAREXPAND_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ENVVAREXPAND_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ENVVAREXPAND_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ENVVAREXPAND_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ENVVAREXPAND_NTRACE */

#if (ENVVAREXPAND_NTRACE == 1)
#  define ENVVAREXPAND_TRACE(X)
#else /* (ENVVAREXPAND_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ENVVAREXPAND_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ENVVAREXPAND_NTRACE == 1) */

#endif /* ENVVAREXPAND_EXPORT_H */

// End of auto generated file.
