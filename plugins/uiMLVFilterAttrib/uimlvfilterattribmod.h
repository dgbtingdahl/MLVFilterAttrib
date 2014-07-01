#ifndef uimlvfilterattribmod_h
#define uimlvfilterattribmod_h

/*+
________________________________________________________________________

 (C) dGB Beheer B.V.; (LICENSE) http://opendtect.org/OpendTect_license.txt
 Author:	K. Tingdahl
 Date:		Mar 2006
 RCS:		$Id: moduleheader.h.in 32104 2013-10-23 20:11:53Z kristofer.tingdahl@dgbes.com $
________________________________________________________________________


-*/

//
//This file is generated automatically from CMAKE. It contains export/import
//Declarations that are used on windows. It also includes deps of all modules
//that this module is dependent on.
//

#if defined( __win64__ ) || defined ( __win32__ )
# define do_import_export
#else
# ifdef do_import_export
#  undef do_import_export
# endif
#endif

#ifndef dll_export
# if defined( do_import_export )
#  define dll_export	__declspec( dllexport )
#  define dll_import	__declspec( dllimport )
#  define dll_extern	extern
# else
#  define dll_export
#  define dll_import
# endif
#endif

#if defined(uiMLVFilterAttrib_EXPORTS) || defined(UIMLVFILTERATTRIB_EXPORTS)
# define do_export_uiMLVFilterAttrib
#else
# if defined ( do_export_uiMLVFilterAttrib )
#  undef do_export_uiMLVFilterAttrib
# endif
#endif


#if defined( do_export_uiMLVFilterAttrib )
# define Export_uiMLVFilterAttrib	dll_export
# define Extern_uiMLVFilterAttrib
#else
# define Export_uiMLVFilterAttrib	dll_import
# define Extern_uiMLVFilterAttrib	dll_extern
#endif

#if defined ( do_import_export )



#endif

#endif
