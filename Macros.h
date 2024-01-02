/*****************************************************************//**
 * \file    Macros.h
 * \brief   Directly Musical Data Access library for VST3 with JUCE.
 *
 * \author  WuChang
 * \email   31423836@qq.com
 * \date    Jan 2024
 * \version 1.2.3
 * \license	MIT License
 *********************************************************************/

#pragma once

/**
 * TUID of the context object.
 */
#define DMDA_HANDLE_ID_VST3 "CAFEBABEDEADBEEF"

#ifndef DMDA_PLUGIN
#define DMDA_PLUGIN 0
#endif // !DMDA_PLUGIN

#if defined (__clang__)
#define DMDA_CLANG 1

#elif defined (__GNUC__)
#define DMDA_GCC 1

#elif defined (_MSC_VER)
#define DMDA_MSVC 1

#else
#error Unknown cpp compiler
#endif

#if DMDA_MSVC
#define DMDA_EXPORT __declspec(dllexport)
#define DMDA_IMPORT __declspec(dllimport)
#define DMDA_CALL _cdecl
#endif

#if DMDA_CLANG
#define DMDA_EXPORT __attribute__((visibility("default")))
#define DMDA_IMPORT __attribute__((visibility("default")))
#define DMDA_CALL
#endif

#if DMDA_GCC
#define DMDA_EXPORT __attribute__((visibility("default")))
#define DMDA_IMPORT __attribute__((visibility("default")))
#define DMDA_CALL
#endif

#if !(DMDA_MSVC || DMDA_CLANG || DMDA_GCC)
#define DMDA_EXPORT 
#define DMDA_IMPORT 
#define DMDA_CALL
#endif

#if DMDA_DLL_BUILD
#define DMDA_API DMDA_EXPORT
#elif DMDA_DLL
#define DMDA_API DMDA_IMPORT
#else
#define DMDA_API 
#endif // DMDA_DLL_BUILD
