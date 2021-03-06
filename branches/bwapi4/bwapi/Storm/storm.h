#pragma once
#include <windows.h>
#include <winuser.h>
#include <winsock.h>
#include <ddraw.h>

// Note to self: Linker error => forgot a return value in cpp

#ifndef STORMAPI
#define STORMAPI __stdcall
#endif

#define arrsize(x) (sizeof(x)/sizeof(x[0]))   // Official name
#define countof(x) arrsize(x)                 // Personal name

#ifndef SMAX
#define SMAX(x,y) (x < y ? y : x)
#endif

#ifndef SSIZEMAX
#define SSIZEMAX(x,y) (SMAX(sizeof(x),sizeof(y)))
#endif

#ifndef SMIN
#define SMIN(x,y) (x < y ? x : y)
#endif

#ifndef SSIZEMIN
#define SSIZEMIN(x,y) (SMAX(sizeof(x),sizeof(y)))
#endif

#ifndef __in_opt
#define __in_opt
#endif
#ifndef __in
#define __in
#endif
#ifndef __out
#define __out
#endif
#ifndef __inout
#define __inout
#endif
#ifndef __out_opt
#define __out_opt
#endif

#ifndef BLIZZ_STRUCTS
#define BLIZZ_STRUCTS
typedef struct _WRECT
{
  WORD  left;
  WORD  top;
  WORD  right;
  WORD  bottom;
} WRECT, *PWRECT;

typedef struct _WPOINT
{
  WORD  x;
  WORD  y;
} WPOINT, *PWPOINT;

typedef struct _WSIZE
{
  WORD  cx;
  WORD  cy;
} WSIZE, *PWSIZE;
#endif

#ifndef GAMESTATE_PRIVATE

#define GAMESTATE_PRIVATE 0x01
#define GAMESTATE_FULL    0x02
#define GAMESTATE_ACTIVE  0x04
#define GAMESTATE_STARTED 0x08
#define GAMESTATE_REPLAY  0x80
#endif

BOOL STORMAPI SNetCreateGame(const char *pszGameName, const char *pszGamePassword, const char *pszGameStatString, DWORD dwGameType, char *GameTemplateData, int GameTemplateSize, int playerCount, char *creatorName, char *a11, int *playerID);
BOOL STORMAPI SNetDestroy();
BOOL STORMAPI SNetEnumProviders(int (STORMAPI *callback)(DWORD, DWORD, DWORD, DWORD), int mincaps);

BOOL STORMAPI SNetEnumGames(int (STORMAPI *callback)(DWORD, DWORD, DWORD), int *hintnextcall);

/*  SNetDropPlayer @ 106
 * 
 *  Drops a player from the current game.
 *  
 *  playerid:     The player ID for the player to be dropped.
 *  flags:        
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetDropPlayer(
      __in  int playerid,
      __in  DWORD flags);

/*  SNetGetGameInfo @ 107
 * 
 *  Retrieves specific game information from Storm, such as name, password,
 *  stats, mode, game template, and players.
 *  
 *  type:         The type of data to retrieve. See GAMEINFO_ flags.
 *  dst:          The destination buffer for the data.
 *  length:       The maximum size of the destination buffer.
 *  byteswritten: The number of bytes written to the destination buffer.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetGetGameInfo(
    __in  int type,
    __out void *dst,
    __in  size_t length,
    __out size_t *byteswritten = NULL);

#ifndef SNGetGameInfo
#define SNGetGameInfo(typ,dst) SNetGetGameInfo(typ, &dst, sizeof(dst))
#endif

#ifndef GAMEINFO_NAME

#define GAMEINFO_NAME           1
#define GAMEINFO_PASSWORD       2
#define GAMEINFO_STATS          3
#define GAMEINFO_MODEFLAG       4
#define GAMEINFO_GAMETEMPLATE   5
#define GAMEINFO_PLAYERS        6

#endif

BOOL STORMAPI SNetGetNumPlayers(int *firstplayerid, int *lastplayerid, int *activeplayers);

#ifndef CAPS_STRUCT
#define CAPS_STRUCT
typedef struct _CAPS
{
  DWORD dwSize;                 // Size of this structure  // sizeof(CAPS)
  DWORD dwUnk_0x04;
  DWORD maxmessagesize;         // Size of the packet buffer, must be beteen 128 and 512
  DWORD dwUnk_0x0C;
  DWORD dwDisplayedPlayerCount; // Displayed player count in the mode selection list
  DWORD dwUnk_0x14;             // some kind of timeout or timer related
  DWORD dwPlayerLatency;        // ... latency?
  DWORD dwPlayerCount;          // the number of players that can participate, must be between 1 and 20
  DWORD dwCallDelay;            // the number of calls before data is sent over the network // between 2 and 8; single player is set to 1
} CAPS, *PCAPS;
#endif

BOOL STORMAPI SNetGetPlayerCaps(char playerid, PCAPS playerCaps);

/*  SNetGetPlayerName @ 113
 * 
 *  Retrieves the name of a player given their player ID.
 *  
 *  playerid:     The player's ID.
 *  buffer:       The buffer that will receive the name.
 *  buffersize:   The maximum size of buffer.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetGetPlayerName(
      __in  int playerid, 
      __out char *buffer, 
      __in  size_t buffersize);

/*  SNetGetProviderCaps @ 114
 * 
 *  Retrieves network provider capacity information.
 *  
 *  providerCaps: A pointer to a CAPS structure that will receive the information.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL 
STORMAPI 
SNetGetProviderCaps(
      __out PCAPS providerCaps);

/*  SNetGetTurnsInTransit @ 115
 * 
 *  Retrieves the number of turns (buffers) that have been queued
 *  before sending them over the network.
 *  
 *  turns: A pointer to an integer that will receive the value.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetGetTurnsInTransit(
      __out int *turns);


BOOL STORMAPI SNetInitializeDevice(int a1, int a2, int a3, int a4, int *a5);

#ifndef PROVIDER_STRUCTS
#define PROVIDER_STRUCTS
typedef struct _clientInfo
{
  DWORD dwSize; // 60
  char  *pszName;
  char  *pszVersion;
  DWORD dwProduct;
  DWORD dwVerbyte;
  DWORD dwUnk5;
  DWORD dwMaxPlayers;
  DWORD dwUnk7;
  DWORD dwUnk8;
  DWORD dwUnk9;
  DWORD dwUnk10; // 0xFF
  char  *pszCdKey;
  char  *pszCdOwner;
  DWORD dwIsShareware;
  DWORD dwLangId;
} clientInfo;

typedef struct _userInfo
{
  DWORD dwSize; // 16
  char  *pszPlayerName;
  char  *pszUnknown;
  DWORD dwUnknown;
} userInfo;

typedef struct _battleInfo
{
  DWORD dwSize;   // 92
  DWORD dwUnkType;
  HWND  hFrameWnd;
  void  *pfnBattleGetResource;
  void  *pfnBattleGetErrorString;
  void  *pfnBattleMakeCreateGameDialog;
  void  *pfnBattleUpdateIcons;
  DWORD dwUnk_07;
  void  *pfnBattleErrorDialog;
  void  *pfnBattlePlaySound;
  DWORD dwUnk_10;
  void  *pfnBattleGetCursorLink;
  DWORD dwUnk_12;
  void  *pfnUnk_13;
  DWORD dwUnk_14;
  void  *pfnBattleMakeProfileDialog;
  char  *pszProfileStrings;
  void  *pfnBattleDrawProfileInfo;
  void  *pfnUnk_18;
  DWORD dwUnk_19;
  void  *pfnUnk_20;
  void  *pfnUnk_21;
  void  *pfnBattleSetLeagueName;
} battleInfo;

typedef struct _moduleInfo
{
  DWORD dwSize; // 20
  char  *pszVersionString;
  char  *pszModuleName;
  char  *pszMainArchive;
  char  *pszPatchArchive;
} moduleInfo;

typedef struct _gameStruc
{
  DWORD       dwIndex;
  DWORD       dwGameState;
  DWORD       dwUnk_08;
  SOCKADDR    saHost;
  DWORD       dwUnk_1C;
  DWORD       dwTimer;
  DWORD       dwUnk_24;
  char        szGameName[128];
  char        szGameStatString[128];
  _gameStruc  *pNext;
  void        *pExtra;
  DWORD       dwExtraBytes;
  DWORD       dwProduct;
  DWORD       dwVersion;
} gameStruc;

typedef struct _stormHead
{
  WORD wChecksum;
  WORD wLength;
  WORD wSent;
  WORD wReceived;
  BYTE bCommandClass;
  BYTE bCommandType;
  BYTE bPlayerId;
  BYTE bFlags;
} stormHead;

#endif

#ifndef STRAFFIC_NORMAL

#define STRAFFIC_NORMAL 0
#define STRAFFIC_VERIFY 1
#define STRAFFIC_RESEND 2
#define STRAFFIC_REPLY  4

#endif

/*  SNetInitializeProvider @ 117
 * 
 *  Initializes a provider by storing the provider callbacks, and calling
 *  spiInitialize() using the parameters passed to this function.
 *  Note: The use of the parameters is determined by the network
 *  module.
 *  
 *  providerName:     The provider's identifier. Example: 'TENB' (BNET).
 *  gameClientInfo:   A pointer to a clientInfo structure containing 
 *                    information about the game client.
 *  userData:         A pointer to a userInfo structure containing information 
 *                    about the player.
 *  bnCallbacks:      A pointer to a battleInfo structure containing callbacks
 *                    and other information that is specific to Battle.net.
 *  moduleData:       A pointer to a moduleInfo structure containing the
 *                    executable information and paths to MPQ archives.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetInitializeProvider(
      __in  DWORD       providerName, 
      __in  clientInfo  *gameClientInfo,
      __in  userInfo    *userData,
      __in  battleInfo  *bnCallbacks,
      __in  moduleInfo  *moduleData);


BOOL STORMAPI SNetJoinGame(unsigned int a1, char *gameName, char *gamePassword, char *playerName, char *userStats, int *playerid);

/*  SNetLeaveGame @ 119
 * 
 *  Notifies Storm that the player has left the game. Storm will
 *  notify all connected peers through the network provider.
 *  
 *  type: The leave type. It doesn't appear to be important, no documentation available.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetLeaveGame(
    __in int type);

BOOL STORMAPI SNetPerformUpgrade(DWORD *upgradestatus);
BOOL STORMAPI SNetReceiveMessage(int *senderplayerid, char **data, int *databytes);
BOOL STORMAPI SNetReceiveTurns(int a1, int arraysize, char **arraydata, unsigned int *arraydatabytes, DWORD *arrayplayerstatus);

// Values for arrayplayerstatus
#ifndef SNET_PS_OK

#define SNET_PS_OK             0
#define SNET_PS_WAITING        2
#define SNET_PS_NOTRESPONDING  3
#define SNET_PS_UNKNOWN        default

#endif

#ifndef STORM_EVENT
#define STORM_EVENT

typedef struct _s_evt
{
  DWORD dwFlags;
  int   dwPlayerId;
  void  *pData;
  DWORD dwSize;
} S_EVT, *PS_EVT;
#endif

/* @TODO: "type" is unknown. */
HANDLE STORMAPI SNetRegisterEventHandler(int type, void (STORMAPI *sEvent)(PS_EVT));

int  STORMAPI SNetSelectGame(int a1, int a2, int a3, int a4, int a5, int *playerid);

/*  SNetSendMessage @ 127
 * 
 *  Sends a message to a player given their player ID. Network message
 *  is sent using class 01 and is retrieved by the other client using
 *  SNetReceiveMessage().
 *  
 *  playerID:   The player index of the player to receive the data.
 *              Conversely, this field can be one of the following constants:
 *                  SNPLAYER_ALL      | Sends the message to all players, including oneself.
 *                  SNPLAYER_OTHERS   | Sends the message to all players, except for oneself.
 *  data:       A pointer to the data.
 *  databytes:  The amount of bytes that the data pointer contains.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetSendMessage(
      __in int    playerID,
      __in void   *data,
      __in size_t databytes);


#ifndef SNPLAYER_ALL

#define SNPLAYER_ALL    -1
#define SNPLAYER_OTHERS -2

#endif

/*  SNetSendTurn @ 128
 * 
 *  Sends a turn (data packet) to all players in the game. Network data
 *  is sent using class 02 and is retrieved by the other client using
 *  SNetReceiveTurns().
 *  
 *  data:       A pointer to the data.
 *  databytes:  The amount of bytes that the data pointer contains.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetSendTurn(
      __in  char    *data,
      __in  size_t  databytes);

/*  SNetSetGameMode @ 130
 * 
 *  Set's the game's mode flags, notifying the network
 *  provider that the state of the game has changed.
 *  For example: notifies Battle.net when the game is
 *  full.
 *  
 *  You should first call SNetGetGameInfo to retrieve
 *  the existing mode flags.
 *
 *  modeFlags:  The new flags for the game mode.
 *                  GAMESTATE_PRIVATE     | The game is passworded.
 *                  GAMESTATE_FULL        | The game is full.
 *                  GAMESTATE_ACTIVE      | The game is available.
 *                  GAMESTATE_STARTED     | The game is in progress.
 *                  GAMESTATE_REPLAY      | The game is a replay.
 *  makePublic: Used to make the game a public game, removing the GAMESTATE_PRIVATE flag.
 *
 *  Returns TRUE if the function was called successfully and FALSE otherwise.
 */
BOOL
STORMAPI
SNetSetGameMode(
      __in DWORD modeFlags,
      bool makePublic = false);

#define SNMakeGamePublic() SNetSetGameMode( (DWORD mode, SNetGetGameInfo(GAMEINFO_MODEFLAGS, &mode, 4), mode), true)

BOOL STORMAPI SNetEnumGamesEx(int a1, int a2, int (__fastcall *callback)(DWORD, DWORD, DWORD), int *hintnextcall);
BOOL STORMAPI SNetSendServerChatCommand(const char *command);

BOOL STORMAPI SNetGetPlayerNames(DWORD flags); // Is actually SetPlayerFlags or something
BOOL STORMAPI SNetCreateLadderGame(const char *pszGameName, const char *pszGamePassword, const char *pszGameStatString, DWORD dwGameType, DWORD dwGameLadderType, DWORD dwGameModeFlags, char *GameTemplateData, int GameTemplateSize, int playerCount, char *creatorName, char *a11, int *playerID);
BOOL STORMAPI SNetReportGameResult(unsigned int a1, int size, int a3, int a4, int a5);

int  STORMAPI SNetSendLeagueCommand(char *cmd, char *callback);
int  STORMAPI SNetSendReplayPath(int a1, int a2, char *replayPath);
int  STORMAPI SNetGetLeagueName(int leagueID);
BOOL STORMAPI SNet144(char *buffer); // get player something (void **data[8])
int  STORMAPI SNetLeagueLogout(char *bnetName);
int  STORMAPI SNetGetLeaguePlayerName(char *curPlayerLeageName, size_t nameSize);

HGDIOBJ STORMAPI SDlgDefDialogProc(HWND hDlg, signed int DlgType, HDC textLabel, HWND hWnd);

HANDLE STORMAPI SDlgDialogBoxIndirectParam(HMODULE hModule, LPCSTR lpName, HWND hWndParent, LPVOID lpParam, LPARAM lParam);

BOOL STORMAPI SDlgEndDialog(HWND hDlg, HANDLE nResult);

BOOL STORMAPI SDlgSetControlBitmaps(HWND parentwindow, int *id, int a3, char *buffer2, char *buffer, int flags, int mask);

BOOL STORMAPI SDlgBltToWindowE(HWND hWnd, HRGN a2, char *a3, int a4, void *buffer, RECT *rct, SIZE *size, int a8, int a9, DWORD rop);
BOOL STORMAPI SDlgSetBitmapE(HWND hWnd, int a2, char *src, int mask1, int flags, int a6, int a7, int width, int a9, int mask2);

int  STORMAPI Ordinal224(int a1);

BOOL STORMAPI SFileCloseArchive(HANDLE hArchive);
BOOL STORMAPI SFileCloseFile(HANDLE hFile);

BOOL STORMAPI SFileDdaBeginEx(HANDLE directsound, DWORD flags, DWORD mask, unsigned __int32 lDistanceToMove, signed __int32 volume, signed int a6, int a7);
BOOL STORMAPI SFileDdaDestroy();
BOOL STORMAPI SFileDdaEnd(HANDLE directsound);
BOOL STORMAPI SFileDdaGetPos(HANDLE directsound, int a2, int a3);

BOOL STORMAPI SFileDdaInitialize(HANDLE directsound);
BOOL STORMAPI SFileDdaSetVolume(HANDLE directsound, signed int bigvolume, signed int volume);

BOOL STORMAPI SFileGetFileArchive(HANDLE hFile, HANDLE archive);
LONG STORMAPI SFileGetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
BOOL STORMAPI SFileOpenArchive(const char *szMpqName, DWORD dwPriority, DWORD dwFlags, HANDLE *phMpq);

// values for dwFlags
#ifndef MPQ_NO_LISTFILE

#define MPQ_NO_LISTFILE       0x0010
#define MPQ_NO_ATTRIBUTES     0x0020
#define MPQ_FORCE_V1          0x0040
#define MPQ_CHECK_SECTOR_CRC  0x0080

#endif

BOOL STORMAPI SFileOpenFile(const char *filename, HANDLE *phFile);
BOOL STORMAPI SFileOpenFileEx(HANDLE hMpq, const char *szFileName, DWORD dwSearchScope, HANDLE *phFile);

// values for dwSearchScope
#ifndef SFILE_FROM_MPQ

#define SFILE_FROM_MPQ        0x00000000
#define SFILE_FROM_ABSOLUTE   0x00000001
#define SFILE_FROM_RELATIVE   0x00000002
#define SFILE_FROM_DISK       0x00000004

#endif

BOOL STORMAPI SFileReadFile(HANDLE hFile, void *buffer, DWORD nNumberOfBytesToRead, DWORD *read, LONG lpDistanceToMoveHigh);

void STORMAPI SFileSetLocale(LCID lcLocale);

// mode:    0 - Silent (callback is NULL)
//          1 - Application Defined
//          2 - Handled by storm (callback is NULL)
// BOOL STORMAPI callback(const char *pszFilename, DWORD dwErrCode, DWORD dwErrCount)
BOOL STORMAPI SFileSetIoErrorMode(DWORD mode, BOOL (STORMAPI *callback)(const char*,DWORD,DWORD) );

BOOL STORMAPI SFileGetArchiveName(HANDLE hArchive, char *name, int length);
BOOL STORMAPI SFileGetFileName(HANDLE hFile, char *buffer, int length);

BOOL STORMAPI SFileLoadFile(char *filename, void *buffer, int buffersize, int a4, int a5);
BOOL STORMAPI SFileUnloadFile(HANDLE hFile);
BOOL STORMAPI SFileLoadFileEx(void *hArchive, char *filename, int a3, int a4, int a5, DWORD searchScope, struct _OVERLAPPED *lpOverlapped);

// Options are DWORD except for #6
// 1: [TRUE|FALSE] - If true, reports resource leaks (SErrReportResourceLeak/SErrReportNamedResourceLeak) to the attached debugger instead of a message box.
// 2: This option is unused.
// 3: [TRUE|FALSE] - If true, reports general memory leaks to the attached debugger instead of a message box.
// 4: This option is unused.
// 5: [TRUE|FALSE] - If true, reports log messages and log dumps to the attached debugger.
// 6: { DWORD blocks_allocated; DWORD blocks_freed; } Used to determine the amount of memory/heap blocks that have been allocated and freed by storm.
//    Can also be used for custom allocations outside of storm.
//
//BOOL STORMAPI StormGetOption(int type, void *pValue, size_t *pSize);
//BOOL STORMAPI StormSetOption(int type, void *pValue, size_t size);

BOOL STORMAPI SBltROP3(void *lpDstBuffer, void *lpSrcBuffer, int width, int height, int a5, int a6, int a7, DWORD rop);
BOOL STORMAPI SBltROP3Clipped(void *lpDstBuffer, RECT *lpDstRect, POINT *lpDstPt, int a4, void *lpSrcBuffer, RECT *lpSrcRect, POINT *lpSrcPt, int a8, int a9, DWORD rop);

#ifndef SBMP_DEFAULT

#define SBMP_DEFAULT  0
#define SBMP_BMP      1
#define SBMP_PCX      2
#define SBMP_TGA      3

#endif


/*  SBmpDecodeImage @ 321
 * 
 *  Decodes an image that has already been loaded into a buffer.
 *  
 *  dwImgType:        Optional, the image type. See SBMP_ macros.
 *  pSrcBuffer:       A pointer to the source buffer.
 *  dwSrcBuffersize:  The size of the data in the source buffer.
 *  pPalette:         An optional buffer that receives the image palette.
 *  pDstBuffer:       A buffer that receives the image data.
 *  dwDstBuffersize:  The size of the specified image buffer. If the size of the 
 *                    destination buffer is 0, then the destination buffer is not used.
 *  pdwWidth:         An optional variable that receives the image width.
 *  pdwHeight:        An optional variable that receives the image height.
 *  pdwBpp:           An optional variable that receives the image bits per pixel.
 *
 *  Returns TRUE if the image was supported and decoded correctly, FALSE otherwise.
 */
BOOL 
STORMAPI 
SBmpDecodeImage(
    __in_opt  DWORD        dwImgType,
    __in      void         *pSrcBuffer,
    __in      DWORD        dwSrcBuffersize,
    __out_opt PALETTEENTRY *pPalette        = NULL,
    __out     void         *pDstBuffer      = NULL,
    __out     DWORD        dwDstBuffersize  = 0,
    __out_opt DWORD        *pdwWidth        = NULL,
    __out_opt DWORD        *pdwHeight       = NULL,
    __out_opt DWORD        *pdwBpp          = NULL);


/*  SBmpLoadImage @ 323
 * 
 *  Load an image from an available archive into a buffer.
 *  
 *  pszFileName:  The name of the graphic in an active archive.
 *  pPalette:     An optional buffer that receives the image palette.
 *  pBuffer:      A buffer that receives the image data.
 *  dwBuffersize: The size of the specified image buffer.
 *  pdwWidth:     An optional variable that receives the image width.
 *  pdwHeight:    An optional variable that receives the image height.
 *  pdwBpp:       An optional variable that receives the image bits per pixel.
 *
 *  Returns TRUE if the image was supported and loaded correctly, FALSE otherwise.
 */
BOOL
STORMAPI
SBmpLoadImage(
    __in      const char   *pszFileName,
    __out_opt PALETTEENTRY *pPalette    = NULL,
    __out     void         *pBuffer     = NULL,
    __out     DWORD        dwBuffersize = 0,
    __out_opt DWORD        *pdwWidth    = NULL,
    __out_opt DWORD        *pdwHeight   = NULL,
    __out_opt DWORD        *pdwBpp      = NULL);

/*  SBmpSaveImage @ 324
 * 
 *  Save an image from a buffer to a file. The image format is determined 
 *  from the filename and is either .gif, .pcx, .tga, or .bmp being the default.
 *  
 *  pszFileName:  The name of the file to create.
 *  pPalette:     A pointer to a palette array containing 256 entries.
 *  pBuffer:      A buffer containing the image data.
 *  pdwWidth:     The width of the image.
 *  pdwHeight:    The height of the image.
 *  pdwBpp:       The bits per pixel.
 *
 *  Returns TRUE if the image was saved correctly, FALSE otherwise.
 */
BOOL
STORMAPI
SBmpSaveImage(
    __in  const char    *pszFileName,
    __in  PALETTEENTRY  *pPalette,
    __in  void          *pBuffer,
    __in  DWORD         dwWidth,
    __in  DWORD         dwHeight,
    __in  DWORD         dwBpp = 8);


HANDLE STORMAPI SBmpAllocLoadImage(const char *fileName, PALETTEENTRY *palette, void **buffer, int *width, int *height, int unused6, int unused7, void *(STORMAPI *allocFunction)(DWORD));

BOOL STORMAPI SCodeCompile(char *directives1, char *directives2, char *loopstring, unsigned int maxiterations, unsigned int flags, HANDLE handle);
BOOL STORMAPI SCodeDelete(HANDLE handle);

int  STORMAPI SCodeExecute(HANDLE handle, int a2);

BOOL STORMAPI SDrawAutoInitialize(HINSTANCE hInst, LPCSTR lpClassName, LPCSTR lpWindowName, WNDPROC pfnWndProc, int nMode, int nWidth, int nHeight, int nBits);


/*  SDrawCaptureScreen @ 342
 * 
 *  Saves a screenshot from the primary surface being handled by Storm.
 *  
 *  pszOutput: The name of the output file. The save format is automatically set by the extension.
 *             The extensions supported are .gif, .pcx, .tga, and .bmp. It will write a bitmap by default.
 *
 *  Returns TRUE if successful and FALSE otherwise.
 */
BOOL 
STORMAPI 
SDrawCaptureScreen(
    __in const char *pszOutput);


/*  SDrawGetFrameWindow @ 346
 *
 *  Retrieves the window handle that was specified in
 *  SDrawManualInitialize or created in SDrawAutoInitialize.
 *  
 *  sdraw_framewindow: Optional variable that receives the returned handle.
 *
 *  Returns the handle of the window.
 */
HWND
STORMAPI
SDrawGetFrameWindow(
    __out_opt HWND *sdraw_framewindow = NULL);


/*  SDrawGetObjects @ 347
 *  
 *  Retrieves the object information that was initialized using
 *  SDrawManualInitialize or SDrawAutoInitialize.
 *  
 *  ddInterface:    The DirectDraw interface.
 *  primarySurface: The primary DirectDraw surface.
 *  surface2:       A second unknown surface.
 *  surface3:       A third unknown surface.
 *  backSurface:    The back DirectDraw surface.
 *  ddPalette:      The DirectDraw palette.
 *  hPalette:       The palette handle.
 *
 *  Returns FALSE if the direct draw interface has not been initialized.
 */
BOOL
STORMAPI
SDrawGetObjects(
    __out_opt LPDIRECTDRAW        *ddInterface    = NULL,
    __out_opt LPDIRECTDRAWSURFACE *primarySurface = NULL,
    __out_opt LPDIRECTDRAWSURFACE *surface2       = NULL,
    __out_opt LPDIRECTDRAWSURFACE *surface3       = NULL,
    __out_opt LPDIRECTDRAWSURFACE *backSurface    = NULL,
    __out_opt LPDIRECTDRAWPALETTE *ddPalette      = NULL,
    __out_opt HPALETTE            *hPalette       = NULL);


/*  SDrawGetScreenSize @ 348
 *  
 *  Obtains information for the current screen resolution.
 *
 *  pdwWidth:   Optional variable that receives the screen width.
 *  pdwHeight:  Optional variable that receives the screen height.
 *  pdwBpp:     Optional variable that receives the bits per pixel.
 *
 *  Returns FALSE if no variables were specified.
 */
BOOL
STORMAPI
SDrawGetScreenSize(
    __out_opt DWORD *pdwWidth,
    __out_opt DWORD *pdwHeight,
    __out_opt DWORD *pdwBpp);


// undefined
BOOL STORMAPI SDrawLockSurface(int surfacenumber, RECT *lpDestRect, void **lplpSurface, int *lpPitch, int arg_unused);


/*  SDrawManualInitialize @ 351
 *  
 *  Sets the DirectDraw variables to be referenced in Storm.
 *
 *  hWnd:           The handle of the DirectDraw window.
 *  ddInterface:    The DirectDraw interface.
 *  primarySurface: The first and primary surface.
 *  surface2:       A second surface. Behaviour not completely known.
 *  surface3:       A third surface. Behaviour not completely known.
 *  backSurface:    The fourth and final surface. The back surface.
 *  ddPalette:      The DirectDraw palette if the application requires it.
 *  hPalette:       The palette handle that belongs to the window.
 *                  If this is NULL and ddPalette is specified, then it
 *                  will be created automatically. A palette can be created
 *                  using the CreatePalette WinAPI function.
 *
 *  Returns FALSE if no variables were specified.
 */
BOOL
STORMAPI
SDrawManualInitialize(
    __in_opt  HWND hWnd                           = NULL,
    __in_opt  LPDIRECTDRAW ddInterface            = NULL,
    __in_opt  LPDIRECTDRAWSURFACE primarySurface  = NULL,
    __in_opt  LPDIRECTDRAWSURFACE surface2        = NULL,
    __in_opt  LPDIRECTDRAWSURFACE surface3        = NULL,
    __in_opt  LPDIRECTDRAWSURFACE backSurface     = NULL,
    __in_opt  LPDIRECTDRAWPALETTE ddPalette       = NULL,
    __in_opt  HPALETTE hPalette                   = NULL);


/*  SDrawPostClose @ 353
 *
 *  Posts a WM_QUIT message to the active drawing window specified 
 *  in SDrawManualInitialize or created in SDrawAutoInitialize.
 *
 *  Returns TRUE if successful and FALSE otherwise.
 */
BOOL
STORMAPI
SDrawPostClose();


// undefined
BOOL STORMAPI SDrawRealizePalette();

BOOL STORMAPI SDrawUnlockSurface(int surfacenumber, void *lpSurface, int a3, RECT *lpRect);
BOOL STORMAPI SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY *pPalEntries, int a4);

BOOL STORMAPI SEvtDispatch(DWORD dwMessageID, DWORD dwFlags, int type, PS_EVT pEvent);

BOOL STORMAPI SGdiDeleteObject(HANDLE handle);

BOOL STORMAPI SGdiExtTextOut(int a1, int a2, int a3, int a4, unsigned int a8, signed int a6, signed int a7, const char *pszString, unsigned int arg20);
BOOL STORMAPI SGdiImportFont(HGDIOBJ handle, int windowsfont);

BOOL STORMAPI SGdiSelectObject(int handle);
BOOL STORMAPI SGdiSetPitch(int pitch);

BOOL STORMAPI Ordinal393(char *pszString, int, int);


/*  SMemAlloc @ 401
 *  
 *  Allocates a block of memory. This block is different
 *  from the standard malloc by including a header containing
 *  information about the block. 
 *
 *  amount:       The amount of memory to allocate, in bytes.
 *  logfilename:  The name of the file or object that this call belongs to.
 *  logline:      The line in the file or one of the SLOG_ macros.
 *  defaultValue: The default value of a byte in the allocated memory.
 *
 *  Returns a pointer to the allocated memory. This pointer does NOT include
 *  the additional storm header.
 */
void*
STORMAPI
SMemAlloc(
    __in  size_t amount,
    __in  char  *logfilename,
    __in  int   logline,
    __in  char  defaultValue = 0);

#ifndef SMAlloc
#define SMAlloc(amount) SMemAlloc((amount), __FILE__, __LINE__)
#endif


/*  SMemFree @ 403
 *  
 *  Frees a block of memory that was created using SMemAlloc, 
 *  includes the log file and line for debugging purposes.
 *
 *  location:     The memory location to be freed.
 *  logfilename:  The name of the file or object that this call belongs to.
 *  logline:      The line in the file or one of the SLOG_ macros.
 *  defaultValue: 
 *
 *  Returns TRUE if the call was successful and FALSE otherwise.
 */
BOOL
STORMAPI
SMemFree(
    __in  void *location,
    __in  char *logfilename,
    __in  int  logline,
    __in  char defaultValue = 0);

#ifndef SMFree
#define SMFree(loc) SMemFree((loc), __FILE__, __LINE__)
#endif

/*  SMemReAlloc @ 405
 *  
 *  Reallocates a block of memory that was created using SMemAlloc, 
 *  includes the log file and line for debugging purposes.
 *
 *  location:     The memory location to be re-allocated. If this parameter
 *                is NULL, then SMemAlloc is called with the remaining parameters.
 *  amount:       The amount of memory to re-allocate.
 *  logfilename:  The name of the file or object that this call belongs to.
 *  logline:      The line in the file or one of the SLOG_ macros.
 *  defaultValue: 
 *
 *  Returns a pointer to the re-allocated memory. This pointer does NOT include
 *  the additional storm header.
 */
void*
STORMAPI
SMemReAlloc(
    __in  void    *location,
    __in  size_t  amount,
    __in  char    *logfilename,
    __in  int     logline,
    __in  char    defaultValue = 0);

#ifndef SMReAlloc
#define SMReAlloc(loc,s) SMemReAlloc((loc),(s), __FILE__, __LINE__)
#endif


#ifndef SLOG_EXPRESSION

#define SLOG_EXPRESSION    0
#define SLOG_FUNCTION     -1
#define SLOG_OBJECT       -2
#define SLOG_HANDLE       -3
#define SLOG_FILE         -4
#define SLOG_EXCEPTION    -5

#endif

BOOL STORMAPI SRegLoadData(const char *keyname, const char *valuename, int size, LPBYTE lpData, BYTE flags, LPDWORD lpcbData);
BOOL STORMAPI SRegLoadString(const char *keyname, const char *valuename, BYTE flags, char *buffer, size_t buffersize);
BOOL STORMAPI SRegLoadValue(const char *keyname, const char *valuename, BYTE flags, int *value);
BOOL STORMAPI SRegSaveData(const char *keyname, const char *valuename, int size, BYTE *lpData, DWORD cbData);
BOOL STORMAPI SRegSaveString(const char *keyname, const char *valuename, BYTE flags, char *string);
BOOL STORMAPI SRegSaveValue(const char *keyname, const char *valuename, BYTE flags, DWORD result);

BOOL STORMAPI SRegDeleteValue(const char *keyname, const char *valuename, BYTE flags);

#ifndef SREG_NONE
// Flags for SReg functions

// Default behaviour checks both HKEY_LOCAL_MACHINE and HKEY_CURRENT_USER
// relative to the "Software\\Blizzard Entertainment\\" key in both hives.

#define SREG_NONE                   0x00000000
#define SREG_EXCLUDE_LOCAL_MACHINE  0x00000001  // excludes checking the HKEY_LOCAL_MACHINE hive
#define SREG_BATTLE_NET             0x00000002  // sets the relative key to "Software\\Battle.net\\" instead
#define SREG_EXCLUDE_CURRENT_USER   0x00000004  // excludes checking the HKEY_CURRENT_USER hive
#define SREG_ABSOLUTE               0x00000010  // specifies that the key is not a relative key

#endif

BOOL STORMAPI STransBlt(void *lpSurface, int x, int y, int width, HANDLE hTrans);
BOOL STORMAPI STransBltUsingMask(void *lpSurface, void *lpSource, int pitch, int width, HANDLE hTrans);

BOOL STORMAPI STransDelete(HANDLE hTrans);

BOOL STORMAPI STransDuplicate(HANDLE hTransSource, HANDLE hTransDest);
BOOL STORMAPI STransIntersectDirtyArray(HANDLE hTrans, int dirtyarraymask, unsigned __int8 dirtyarray, int sourcemask);
BOOL STORMAPI STransInvertMask(HANDLE hTrans, int sourcemask);

BOOL STORMAPI STransSetDirtyArrayInfo(int width, int height, int depth, int bits);

BOOL STORMAPI STransPointInMask(HANDLE hTrans, int x, int y); // Name is a pure guess
BOOL STORMAPI STransCombineMasks(HANDLE hTrans, int a2, int a3, int a4, int depth, int a6);

BOOL STORMAPI STransCreateE(void *pBuffer, int width, int height, int bpp, int a5, int bufferSize, HANDLE *phTransOut);

BOOL STORMAPI SVidDestroy();
BOOL STORMAPI SVidGetSize(HANDLE video, int width, int height, int zero);
BOOL STORMAPI SVidInitialize(HANDLE video);
BOOL STORMAPI SVidPlayBegin(char *filename, int arg4, int a3, int a4, int a5, int a6, HANDLE video);

BOOL STORMAPI SVidPlayContinueSingle(HANDLE video, int a2, int a3);
BOOL STORMAPI SVidPlayEnd(HANDLE video);

/* SErrDisplayError @ 461
 *
 * Displays a formatted error message. The message is detailed and flexible for many applications.
 * The message will be different if there is a debugger attached. Will typically terminate the application
 * unless the option to continue is given.
 *
 *  dwErrMessage:   The error code. See SErrGetLastError and GetLastError.
 *  logfilename:    The name of the file or object that this call belongs to.
 *  logline:        The line in the file or one of the SLOG_ macros.
 *  message:        A message or expression with additional information.
 *  allowOption:    If TRUE, allows the user the option to continue execution, otherwise the program will terminate.
 *  exitCode:       The exit code used for program termination.
 *
 *  Returns TRUE if the user chose to continue execution, FALSE otherwise.
 */
BOOL
STORMAPI
SErrDisplayError(
    __in DWORD dwErrMsg,
    __in const char *logfilename,
    __in int logline,
    __in const char *message = NULL,
    __in BOOL allowOption = FALSE,
    __in int exitCode = 1);

#define SAssert(x) { if ( !(x) ) SErrDisplayError(STORM_ERROR_ASSERTION, __FILE__, __LINE__, #x) }

#define SEDisplayError(err) SErrDisplayError(e, __FILE__, __LINE__)

/*  SErrGetErrorStr @ 462
 *  
 *  Retrieves a string that describes the specified error code for
 *  the system, Storm, DirectDraw, or DirectSound.
 *
 *  dwErrCode:    The error code to look up.
 *  buffer:       The destination buffer to receive the string.
 *  bufferchars:  The size of the destination buffer.
 *
 *  Returns TRUE if the call was successful and FALSE otherwise.
 */
BOOL
STORMAPI
SErrGetErrorStr(
    __in  DWORD dwErrCode,
    __out char *buffer,
    __in  size_t bufferchars);

#define SEGetErrorStr(e,b) SErrGetErrorStr(e,b,sizeof(b))


/*  SErrGetLastError @ 463
 *  
 *  Retrieves the last error that was specifically
 *  set for the Storm library.
 *
 *  Returns the last error set within the Storm library.
 */
DWORD
STORMAPI
SErrGetLastError();


// Registers a module as a message source for SErrGetErrorStr, always returns TRUE
// groupID is a group in a MessageTable entry for example in STORM_ERROR_BAD_ARGUMENT 0x85100065, 0x510 is the group.
// BOOL STORMAPI SErrRegisterMessageSource(WORD groupID, HMODULE hSourceModule, int a3)


/*  SErrSetLastError @ 465
 *  
 *  Sets the last error for the Storm library and the Kernel32 library.
 *
 *  dwErrCode:  The error code that will be set.
 */
void
STORMAPI
SErrSetLastError(
    __in DWORD dwErrCode = NO_ERROR);

// 
// void STORMAPI SErrReportNamedResourceLeak(const char *pszMsg, const char *pszSubMsg = nullptr)
// void STORMAPI SErrReportResourceLeak(const char *pszMsg)

void STORMAPI SErrSuppressErrors(BOOL suppressErrors);

// Values for dwErrCode
#ifndef STORM_ERROR_ASSERTION

#define STORM_ERROR_ASSERTION                    0x85100000
#define STORM_ERROR_BAD_ARGUMENT                 0x85100065
#define STORM_ERROR_GAME_ALREADY_STARTED         0x85100066
#define STORM_ERROR_GAME_FULL                    0x85100067
#define STORM_ERROR_GAME_NOT_FOUND               0x85100068
#define STORM_ERROR_GAME_TERMINATED              0x85100069
#define STORM_ERROR_INVALID_PLAYER               0x8510006a
#define STORM_ERROR_NO_MESSAGES_WAITING          0x8510006b
#define STORM_ERROR_NOT_ARCHIVE                  0x8510006c
#define STORM_ERROR_NOT_ENOUGH_ARGUMENTS         0x8510006d
#define STORM_ERROR_NOT_IMPLEMENTED              0x8510006e
#define STORM_ERROR_NOT_IN_ARCHIVE               0x8510006f
#define STORM_ERROR_NOT_IN_GAME                  0x85100070
#define STORM_ERROR_NOT_INITIALIZED              0x85100071
#define STORM_ERROR_NOT_PLAYING                  0x85100072
#define STORM_ERROR_NOT_REGISTERED               0x85100073
#define STORM_ERROR_REQUIRES_CODEC1              0x85100074
#define STORM_ERROR_REQUIRES_CODEC2              0x85100075
#define STORM_ERROR_REQUIRES_CODEC3              0x85100076
#define STORM_ERROR_REQUIRES_UPGRADE             0x85100077
#define STORM_ERROR_STILL_ACTIVE                 0x85100078
#define STORM_ERROR_VERSION_MISMATCH             0x85100079
#define STORM_ERROR_MEM_NOT_ALLOCATED            0x8510007a
#define STORM_ERROR_MEM_CORRUPTED                0x8510007b
#define STORM_ERROR_MEM_INVALID                  0x8510007c
#define STORM_ERROR_MEM_MANAGER_NOT_INITIALIZED  0x8510007d
#define STORM_ERROR_MEM_NOT_FREED                0x8510007e
#define STORM_ERROR_RESOURCES_NOT_RELEASED       0x8510007f
#define STORM_ERROR_OUT_OF_BOUNDS                0x85100080
#define STORM_ERROR_NULL_POINTER                 0x85100081
#define STORM_ERROR_CDKEY_MISMATCH               0x85100082
#define STORM_ERROR_FILE_CORRUPTED               0x85100083
#define STORM_ERROR_FATAL                        0x85100084
#define STORM_ERROR_GAMETYPE_UNAVAILABLE         0x85100085

#endif


/*  SMemCopy @ 491
 *  
 *  Copies a block of memory from source to destination.
 *  This function immediately calls memcpy. See online documentation
 *  of memcpy for more details.
 *
 *  dest:   The destination buffer.
 *  source: The source buffer.
 *  size:   The number of bytes to copy.
 */
void
STORMAPI
SMemCopy(
    __out void *dest, 
    __in  const void *source, 
    __in  size_t size);

#ifndef SMCopy
#define SMCopy(d,s) ( SMemCopy(d, s, SSIZEMIN(s,d)) )
#endif

/*  SMemFill @ 492
 *  
 *  Fills a block of memory with the specified character.
 *  This function immediately calls memset. See online documentation
 *  of memset for more details.
 *
 *  dest:   The destination buffer.
 *  source: The size of the destination buffer.
 *  size:   The format to use.
 */
void
STORMAPI
SMemFill(
    __in  void *location,
    __in  size_t length,
    __in  char fillWith = 0);

#ifndef SMFill
#define SMFill(l,f) (SMemFill(l, sizeof(l), f))
#endif

/*  SMemZero @ 494
 *  
 *  Fills a block of memory with the integer 0x00 (Zero).
 *
 *  location: The location to write at.
 *  length:   The amount of bytes to write.
 */
void 
STORMAPI 
SMemZero(
    __in  void *location,
    __in  size_t length);

#ifndef SMZero
#define SMZero(l) (SMemZero(l, sizeof(l)))
#endif

int   STORMAPI SMemCmp(void *location1, void *location2, DWORD size);

#ifndef SMCmp
#define SMCmp(l,x) ( SMemCmp(l, x, SSIZEMIN(x,l)) )
#endif

/*  SStrCopy @ 501
 *  
 *  Copies a string from src to dest (including NULL terminator)
 *  until the max_length is reached.
 *
 *  dest:         The destination array.
 *  src:          The source array.
 *  max_length:   The maximum length of dest.
 *
 *  Returns the number of characters copied.
 */
int
STORMAPI
SStrCopy(
    __out char *dest, 
    __in  const char *src,
    __in  int max_length = 0x7FFFFFFF);

#ifndef SSCopy
#define SSCopy(d,s) (SStrCopy(d, s, sizeof(d)))
#endif

#ifndef STORM_HASH_ABSOLUTE
#define STORM_HASH_ABSOLUTE 1
#endif

/*  SStrHash @ 502
 *  
 *  Creates a simple hash for the string. This function
 *  should NOT be used for sensitive information.
 *
 *  string:   The input string.
 *  flags:    If STORM_HASH_ABSOLUTE is set then this
              function uses the absolute string, otherwise
              it will convert backslashes to forward
              slashes and some other processing.
 *  seed:     The hash seed. If this value is 0 then the
 *            default value 0x7FED7FED will be used.
 *
 *  Returns the 32-bit hash of the string.
 */
DWORD
STORMAPI
SStrHash(
      __in  const char *string,
      __in  DWORD flags = 0,
      __in  DWORD Seed  = 0);

int   STORMAPI SStrNCat(char *dest, const char *src, DWORD max_length);

/*  SStrLen @ 506
 *  
 *  Retrieves the length of a string.
 *
 *  string:   The input string of which to obtain a
 *            length for.
 *
 *  Returns the length of the string.
 */
int
STORMAPI
SStrLen(
      __in  const char *string);

/*  SStrCmp @ 508
 *  
 *  Compares two strings case sensitive.
 *
 *  string1:  The first string.
 *  string2:  The second string.
 *  size:     The maximum amount of characters to compare.
 *
 *  Returns 0 if strings are equal. See strcmp documentation for more details.
 */
int
STORMAPI
SStrCmp(
      __in  const char *string1, 
      __in  const char *string2, 
      __in  size_t size);

#ifndef SSCmp
#define SSCmp(s,x) ( SStrCmp(s,x,SSIZEMIN(s,x)) )
#endif

/*  SStrCmpI @ 509
 *  
 *  Compares two strings case insensitive.
 *
 *  string1:  The first string.
 *  string2:  The second string.
 *  size:     The maximum amount of characters to compare.
 *
 *  Returns 0 if strings are equal. See strcmpi documentation for more details.
 */
int
STORMAPI
SStrCmpI(
      __in  const char *string1, 
      __in  const char *string2, 
      __in  size_t size);

#ifndef SSCmpI
#define SSCmpI(s,x) ( SStrCmpI(s,x,SSIZEMIN(s,x)) )
#endif

/*  SStrUpper @ 510
 *  
 *  Converts all lower-case alpha characters of a string to upper-case.
 *
 *  string:   The string to convert.
 *  
 *  Returns the same pointer given in the input.
 */
char*
STORMAPI
SStrUpper(
      __inout char* string);

void  STORMAPI SRgn523(HANDLE hRgn, RECT *pRect, int a3, int a4);
void  STORMAPI SRgnCreateRegion(HANDLE *hRgn, int a2);
void  STORMAPI SRgnDeleteRegion(HANDLE hRgn);

void  STORMAPI SRgn529i(int handle, int a2, int a3);


/* SErrDisplayErrorFmt @ 562
 *
 * Displays a formatted error message. The message is detailed and flexible for many applications.
 * The message will be different if there is a debugger attached. Will typically terminate the application
 * unless the option to continue is given.
 *
 *  dwErrMessage:   The error code. See SErrGetLastError and GetLastError.
 *  logfilename:    The name of the file or object that this call belongs to.
 *  logline:        The line in the file or one of the SLOG_ macros.
 *  allowOption:    If TRUE, allows the user the option to continue execution, otherwise the program will terminate.
 *  exitCode:       The exit code used for program termination.
 *  format:         Additional message formatting. See printf.
 *
 *  Returns TRUE if the user chose to continue execution, FALSE otherwise.
 */
BOOL
SErrDisplayErrorFmt(
    __in DWORD dwErrMsg,
    __in const char *logfilename,
    __in int logline,
    __in BOOL allowOption,
    __in int exitCode,
    __in const char *format,
    ...);

#define SEDisplayErrorFmt(err,...) SErrDisplayErrorFmt(err, __FILE__, __LINE__, FALSE, 1, __VA_ARGS__)

/*  SErrCatchUnhandledExceptions @ 567
 *  
 *  Registers a top-level exception filter managed entirely by Storm.
 *  The registered filter will display formatted exception information by calling SErrDisplayError.
 */
void
STORMAPI
SErrCatchUnhandledExceptions();


/*  SStrChr @ 571
 *  
 *  Searches a string for the given character. See 
 *  strchr documentation for more details.
 *
 *  string:   The string to search.
 *  c:        The character to search for.
 *  
 *  Returns a pointer to the first occurance of the character.
 */
char*
STORMAPI
SStrChr(
    __in  const char *string, 
    __in  char c);


char *STORMAPI SStrChrR(const char *string, char c);


/*  SStrVPrintf @ 578
 *  
 *  Prints a formatted string to a destination buffer.
 *  This function calls vsnprintf with some extra error handling.
 *  See online documentation of vsnprintf for more details.
 *
 *  dest:   The destination buffer.
 *  size:   The size of the destination buffer.
 *  format: The format to use.
 *
 *  Returns the number of characters written.
 */
size_t
SStrVPrintf(
    __out char *dest, 
    __in  size_t size, 
    __in  const char *format, ...);


int STORMAPI SBigDel(void *buffer);

int STORMAPI SBigFromBinary(void *buffer, const void *str, size_t size);

int STORMAPI SBigNew(void **buffer);

int STORMAPI SBigPowMod(void *buffer1, void *buffer2, int a3, int a4);

int STORMAPI SBigToBinaryBuffer(void *buffer, int length, int a3, int a4);
