#include <windows.h>
#include <commdlg.h>
#pragma comment(lib, "comdlg32.lib")
#define ID_FILE_OPEN   1001
#define ID_FILE_SAVE   1002
#define ID_FILE_SAVEAS 1003
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
void OpenFile(HWND hwnd);
void SaveFile(HWND hwnd, const char* fileName);
void SaveFileAs(HWND hwnd);

HWND hEdit;
char szFileName[MAX_PATH] = "";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Pencere Kaydi Basarisiz Oldu!", "Hata!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(0, "WindowClass", "Not Defteri", WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        640,
        480,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Pencere Olusturulamadi!", "Hata!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "Hosgeldiniz", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
        0, 0, 640, 480, hwnd, NULL, hInstance, NULL);


    if (hEdit == NULL) {
        MessageBox(NULL, "Düzenleme Kutusu Olusturulamadi!", "Hata!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    HMENU hMenu, hSubMenu;

    hMenu = CreateMenu();
    hSubMenu = CreatePopupMenu();
    AppendMenu(hSubMenu, MF_STRING, ID_FILE_OPEN, "Ac");
    AppendMenu(hSubMenu, MF_STRING, ID_FILE_SAVE, "Kaydet");
    AppendMenu(hSubMenu, MF_STRING, ID_FILE_SAVEAS, "Farkli Kaydet");
    AppendMenu(hMenu, MF_STRING | MF_POPUP, static_cast<UINT_PTR>(reinterpret_cast<UINT_PTR>(hSubMenu)), "Dosya");

    SetMenu(hwnd, hMenu);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);


    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

void OpenFile(HWND hwnd) {
    OPENFILENAME ofn;
    char szFile[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if (GetOpenFileName(&ofn)) {
        HANDLE hFile = CreateFile(ofn.lpstrFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile != INVALID_HANDLE_VALUE) {
            DWORD dwFileSize = GetFileSize(hFile, NULL);
            if (dwFileSize != 0xFFFFFFFF) {
                LPSTR lpBuffer = static_cast<LPSTR>(GlobalAlloc(GPTR, dwFileSize + 1));
                if (lpBuffer != NULL) {
                    DWORD dwRead;
                    if (ReadFile(hFile, lpBuffer, dwFileSize, &dwRead, NULL)) {
                        lpBuffer[dwFileSize] = 0; // Null-terminate the string
                        SetWindowText(hEdit, lpBuffer);
                    }
                    GlobalFree(lpBuffer);
                }
            }
            CloseHandle(hFile);
        }
    }
}

void SaveFile(HWND hwnd, const char* fileName) {
    HANDLE hFile = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD dwTextLength = GetWindowTextLength(hEdit);
        LPSTR lpText = static_cast<LPSTR>(GlobalAlloc(GPTR, dwTextLength + 1));
        if (lpText != NULL) {
            GetWindowText(hEdit, lpText, dwTextLength + 1);
            DWORD dwWritten;
            WriteFile(hFile, lpText, dwTextLength, &dwWritten, NULL);
            GlobalFree(lpText);
        }
        CloseHandle(hFile);
    }
}

void SaveFileAs(HWND hwnd) {
    OPENFILENAME ofn;
    char szFile[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if (GetSaveFileName(&ofn)) {
        SaveFile(hwnd, ofn.lpstrFile);
        strcpy(szFileName, ofn.lpstrFile);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    switch (Message) {
    case WM_SIZE: {
        RECT rcClient;
        GetClientRect(hwnd, &rcClient);
        MoveWindow(hEdit, 0, 0, rcClient.right, rcClient.bottom, TRUE);
        break;
    }
    case WM_COMMAND: {
        switch (LOWORD(wParam)) {
        case ID_FILE_OPEN: {
            OpenFile(hwnd);
            break;
        }
        case ID_FILE_SAVE: {
            if (szFileName[0] == '\0') {
                SaveFileAs(hwnd);
            } else {
                SaveFile(hwnd, szFileName);
            }
            break;
        }
        case ID_FILE_SAVEAS: {
            SaveFileAs(hwnd);
            break;
        }
        }
        break;
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

