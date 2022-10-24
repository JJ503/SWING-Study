// 해당 코드는 리버싱 핵심원리 (이승원 저)를 참고했습니다.

#include "windows.h"
#include "tchar.h"

BOOL InjectionDll(DWORD dwPID, LPCTSTR szDllPath) {
	HANDLE hProcess = NULL, hThread = NULL;
	HMODULE hMod = NULL;
	LPVOID pRemoteBuf = NULL;
	DWORD dwBufSize = (DWORD)(_tcslen(szDllPath) + 1) * sizeof(TCHAR);
	LPTHREAD_START_ROUTINE pThreadProc;

	// 1. dwPID를 이용해 대상 프로세스인 notpad의 HANDLE을 구한다
	if (!(hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID))) {
		_tprintf(L"OpenProcess(%d) failed!!! [%d]\n", dwPID, GetLastError());
		return FALSE;
	}

	// 2. 대상 프로세스인 notepad의 메모리에 szDllPath 크기만큼 메모리를 할당한다
	pRemoteBuf = VirtualAllocEx(hProcess, NULL, dwBufSize, MEM_COMMIT, PAGE_READWRITE);

	// 4. LoadLibraryW() API 주소를 구한다
	hMod = GetModuleHandle(L"kernel32.dll");
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(hMod, "LoadLibraryW");

	// 5. notepad 프로세스에 스레드를 실행
	hThread = CreateRemoteThread(hProcess,        // hProcess
								NULL,             // lpThreadAttributes
								0,                // dwStackSize
								pThreadProc,      // lpStartAddress
								pRemoteBuf,       // lpParameter
								0,                // dwCreationFlags
								NULL);            // lpThreadId
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hProcess);

	return TRUE;
}

int _tmain(int argc, TCHAR* argv[]) {
	if (argc != 3) {
		_tprintf(L"USAGE : %s pid dll_path\n", argv[0]);
		return 1;
	}

	// injection dll
	if (InjectionDll((DWORD)_tstol(argv[0]), argv[2]))
		_tprintf(L"InjectDll(\"%s\") success!!!\n", argv[2]);
	else
		_tprintf(L"InjectDll(\"%s\") failed!!!\n", argv[2]);

	return 0;
}