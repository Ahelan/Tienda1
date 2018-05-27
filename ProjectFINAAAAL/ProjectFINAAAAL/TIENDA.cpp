#include <iostream>
#include <windows.h>
#include <fstream>
#include <CommDlg.h>
#include <mmsystem.h>
#include "resource.h"

#pragma comment (lib, "Winmm.lib")
using namespace std;
HWND ghMainWnd = 0;
HINSTANCE ghAppInst = 0;
HMENU ghMenu = 0;
HWND ghDlg = 0;
int nResult;

struct Registrar {
	char Nombre[30];
	char Nickname[30];
	char Contraseña[30];
	char Verificar[30];
	char Correo[30];

};
Registrar Reg;
#define ID_5SECONDS 100 
UINT TimmerID1 = 0;
UINT TimmerID2 = 0;



BOOL CALLBACK Inicio(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK Principal(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK Carrito(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam);
BOOL CALLBACK Registro(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam);


int WINAPI WinMain(HINSTANCE hin, HINSTANCE hinp, PSTR cmd, int show) {
	TimmerID1 = SetTimer(ghDlg, ID_5SECONDS, 5000, NULL);
	ghAppInst = hin;
	ghMainWnd = CreateDialog(hin, MAKEINTRESOURCE(IDD_DIALOG1), 0, Inicio);
	ShowWindow(ghMainWnd, show);
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (ghMainWnd == 0 || !IsDialogMessage(ghMainWnd, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;



}



BOOL CALLBACK Inicio(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam) {

	static HWND hEditBox = 0;

	switch (msg) {
	case WM_INITDIALOG: {
		

		hEditBox = GetDlgItem(Ini, IDD_DIALOG1);
	}
	case WM_COMMAND: 
	{
		switch (LOWORD(wparam))
		{
		case IDC_INGRESAR: {


			EndDialog(Ini, IDD_DIALOG1);
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_DIALOG2), 0, Principal);
			
			return true; }
		
		case IDC_GUARDAR:
		{
			EndDialog(Ini, IDD_DIALOG1);
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_DIALOG4), 0, Registro);

			return true;
		}
		
		case IDC_FOTO: 
		{
			
			return true;
		}

		}
		
		return true; }
	case WM_CLOSE: 
	{
	nResult=	MessageBox(ghDlg, "¿Esta seguro que quiere salir?", "Advertencia", MB_OKCANCEL);
		switch (nResult) {
		case IDOK: {
			PostQuitMessage(0);

		}
		
		}
		return true; }
	
	case WM_DESTROY:
	{
	
		
		return true; }
	}
	
	return false;
}

BOOL CALLBACK Principal(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam) {


	switch (LOWORD(msg)) {
	case WM_INITDIALOG: 
	{
	

    }

	case WM_COMMAND: 
	{
		switch (LOWORD(wparam)) 
		{
		case ID_CARR:
		{
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_DIALOG3), 0, Carrito);
			return true;
			
		}
		case ID_CERRARSE: 
		{
			EndDialog(Ini, IDD_DIALOG2);
				DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, Inicio);

			return true;
		}
		case IDC_PLAY1: 
		{
			mciSendString("open c:\\Gravity Falls  Dreamscaperers  End Credits.mp3", NULL, 0, 0);
			return true;

		}
		case IDC_COMBO1: 
		{
		

		}
			return true;
		}

return true; 
	}

	case WM_CLOSE: 
	{
		nResult = MessageBox(ghDlg, "¿Esta seguro que quiere salir?", "Advertencia", MB_OKCANCEL);
		switch (nResult) {
		case IDOK: 
		{
			PostQuitMessage(0);

		}

		               }

		return true; 
	}

	case WM_DESTROY: 
	{

		return true;
	}
		
	}

	return false;

}

BOOL CALLBACK Carrito(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam) {

	switch (LOWORD(msg)) {
	case WM_INITDIALOG:
	{


	}

	case WM_COMMAND:
	{
		switch(LOWORD(wparam))
		{
		case ID_CANCEL1: 
		{
			EndDialog(Ini, IDD_DIALOG3);
		}
		
		
		}

		return true;
	}

	case WM_CLOSE:
	{
		nResult = MessageBox(ghDlg, "¿Esta seguro que quiere salir?", "Advertencia", MB_OKCANCEL);
		switch (nResult) {
		case IDOK: {
			PostQuitMessage(0);

		}

		}

		return true;
	}

	case WM_DESTROY:
	{

		return true;
	}

	}

	return false;

}


BOOL CALLBACK Registro(HWND Ini, UINT msg, WPARAM wparam, LPARAM lparam) {

	switch (LOWORD(msg)) {
	case WM_INITDIALOG:
	{


	}

	case WM_COMMAND:
	{
		switch (LOWORD(wparam))
		{
	
		case IDC_REGRESAR:
		{
			EndDialog(Ini, IDD_DIALOG4);
			DialogBox(ghAppInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, Inicio);
		}

		}

		return true;
	}

	case WM_CLOSE:
	{
		EndDialog(Ini, IDD_DIALOG4);
		return true;
	}

	case WM_DESTROY:
	{

		return true;
	}

	}

	return false;

}



