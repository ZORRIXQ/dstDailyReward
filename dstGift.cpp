#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void click() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

int main() {
	for (; true;) {
		HWND hwnd = FindWindow(nullptr, L"Don't Starve Together");
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);
		string dst_path = R"(your path to dst.exe, may contain spaces and ')";

		string command = "start \"\" \"" + dst_path + "\"";
		system(command.c_str());

		SetCursorPos(screenHeight / 2, screenHeight / 2);
		
		Sleep(40 * 1000);
		click();

		PostMessage(hwnd, WM_CLOSE, 0, 0);
		Sleep(60 * 60 * 24 * 1000);
	}
}