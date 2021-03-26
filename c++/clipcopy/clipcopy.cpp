/*
 * Clipcopy.
 * Simple CLI tool to copy a string of text to the Windows clipboard.
 * 
 * Copyright (C) 2021, Ty Gillespie. All rights reserved.
 * MIT License.
 */

#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <iostream>

void to_clipboard(HWND hwnd, const std::string &s);

int main (void) {
    std::string str;
    printf("Please enter what you would like coppied.");
    getline(std::cin, str);
    size_t len = str.length();
    HWND hwnd = GetDesktopWindow();
    to_clipboard(hwnd, str);
    return 0;
}

void to_clipboard(HWND hwnd, const std::string &s) {
    OpenClipboard(hwnd);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg), s.c_str(), s.size()+1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    GlobalFree(hg);
}
