//
//
//	Copyright ZKA Technologies 2024
//
//	File: xpcom.h
//	Purpose: ZKA OS XPCOM SDK.
//
//

#ifndef __SDK_STD_H__
#define __SDK_STD_H__

#ifndef __NDK__
#define object	 class
#define protocol class
#define clsid(X)

#warning ! You may be using the clang version of the ZKA NDK, please be cautious that some thing mayn't be present. !
#endif // !__NDK__

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN extern
#endif

#define PVOID void*
#define VOID  void

#define INT32  __INT32_TYPE__
#define UINT32 __UINT32_TYPE__

#define INT16  __INT16_TYPE__
#define UINT16 __UINT16_TYPE__

#define INT64  __INT64_TYPE__
#define UINT64 __UINT64_TYPE__

#define UINTOFF __UINTPTR_TYPE__
#define UINTPTR __UINTPTR_TYPE__

#define BOOL __UINT8_TYPE__

#define SIZE_T __SIZE_TYPE__

#define WCHAR __WCHAR_TYPE__

#define TRUE  1
#define FALSE 0

struct __gHANDLE
{
	__CHAR32_TYPE__ __UNUSED;
};

// So actualy we need to define handles.

typedef struct __gHANDLE* XHANDLE; // XPCOM handle type.

typedef INT32 XRESULT;

enum
{
	DRIVE_LETTER_START = 0,
	DRIVE_LETTER_END   = 26,
	DRIVE_LETTER_INVALID,
};

EXTERN XHANDLE* X_DESKTOP_LIST;
EXTERN XHANDLE	X_CURRENT_DESKTOP;

EXTERN XRESULT XMessageBox(XHANDLE hWnd, XHANDLE hContent, XHANDLE hOnSuccess, XHANDLE hOnFailure);

EXTERN XRESULT XDialogBoxShow(XHANDLE hWnd, XHANDLE hDlg);

EXTERN XRESULT XDialogBoxDestroy(XHANDLE hDlg);

EXTERN XRESULT XVirtualAlloc(SIZE_T szPtr, UINT32 iFlags, PVOID* ppOut);

EXTERN XRESULT XVirtualFree(PVOID* ppOut);

EXTERN XHANDLE XOpenFile(const WCHAR* szFileName, UINT32 iDriveIdOrIndex, UINT32 iFlags);

EXTERN XRESULT XCloseFile(XHANDLE* ppFile);

EXTERN XRESULT XWriteFile(XHANDLE pFile, PVOID* ppOutBuf, UINT32 iFlags, UINTOFF pOff);

EXTERN XRESULT XReadFile(XHANDLE pFile, PVOID* ppOutBuf, UINT32 iFlags, UINTOFF pOff);

EXTERN XRESULT XGetLastError(VOID);

#endif // ifndef __SDK_STD_H__