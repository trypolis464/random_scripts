/*
 * Clipcopy.
 * Simple CLI tool to copy a string of text to the Windows clipboard.
 * 
 * Copyright (C) 2021, Ty Gillespie. All rights reserved.
 * MIT License.
 */

#define ER_IMPLEMENTATION
#include "../../c/easy_rng/easy_rng.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

// Coppies a given string to the Windows clipboard.
void to_clipboard(HWND hwnd, const std::string &s);

int main() {
    er_init();
    std::string final;
    std::string symbols = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";
    std::string length_str;
    int length;
    printf("How long would you like this password to be?\n");
    getline(std::cin, length_str);
    length = atoi(length_str.c_str());
    if (length == 0) {
        printf("This number can't be 0.\n");
        return -1;
    } else {
        for (int i = 0; i < length; i++) {
            final += symbols[er_generate(0, symbols.length() - 1)];
        }
        HWND hwnd = GetDesktopWindow();
        to_clipboard(hwnd, final);
        printf("%s", final.c_str());
        return 0;
    }
}

void to_clipboard(HWND hwnd, const std::string &s) {
    OpenClipboard(hwnd);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    GlobalFree(hg);
}
