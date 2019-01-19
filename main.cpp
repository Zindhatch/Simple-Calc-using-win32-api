#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <winuser.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

const char g_szClassName[] = "myWindowClass";

// function prototype
void addControls(HWND);
void oprandSearch(char*,int,int);
void arrSize(char);
int charInt(char*); // returns multi digit number from arr of char having numbers
int asc(int x); // returns single number of passing ASCII value
int reverseNum(int num);  //returns reverse of passed number
int checkMultiop(char*,int,int);
int opArthmatic(int);
void removeTailingZero(string);
void cStrDel(char *,int,int); //for deleting c sstyle string character
void doNoth(void);



#define buttOn(cap,id,x,y,w,h) CreateWindowW(L"BUTTON", cap, WS_TABSTOP | WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, (HMENU)id, NULL, NULL)
#define maxArr 204

HWND hEdit;
HMENU hMenu;
char outG[50];
char inputA[50];
//string inputA;
char inputBL[200];
char inputB[50];
double inputAi=0;
double inputBi=0;
int flag=0; //to check entering multidigit in editbox 0 for single and 1 for multi
int numil=0; //number of character before oprator
int numep=0; //size of inputBL ie inputA+op+inputB
int checkMultiOp=0;
int opflag=0; //tells which oprator is passed in op
double result=0;
string resultS; //result string
double resultTemp; //to store fraction part of result
string resultRound;
int eqeq=0; //to handle double equal;
int eqeqop=0; //to check number is pressed;
int mismis=0; //compersary for each command
int outCame=0; //It declares that edit box has result value in it


//Dialog proc
BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDOK:
                    EndDialog(hwnd, IDOK);
                break;
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                break;
                case ID_Nf:

                MessageBox(NULL, "you just clicked 6", "Button Click", MB_OK | MB_ICONINFORMATION);
                break;
            }
        break;
        default:
            return FALSE;
    }
    return TRUE;
}

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_RBUTTONDOWN:
        {
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, "Under Construction!", "This program is:", MB_OKCANCEL | MB_ICONINFORMATION);
        }
        break;
        case VK_RETURN:
            {
                char szInput[MAX_PATH];
                GetWindowText(GetDlgItem(hwnd, 101), szInput, MAX_PATH);
                MessageBox(NULL, szInput, "captio",MB_ICONERROR| MB_OK);
            }
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
            case ID_FILE_EXIT:
                PostMessage(hwnd, WM_CLOSE, 0, 0);
                break;
            /*case ID_VER:
                MessageBox(NULL, "yoyo", "Version",MB_OK | MB_ICONINFORMATION);
            break;*/
            case ID_HELP_ABOUT:
        {
            DialogBox(GetModuleHandle(NULL),
                MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
            }
            break;
            case ID_calc:
                DialogBox(GetModuleHandle(NULL),
                MAKEINTRESOURCE(IDD_CALC), hwnd, AboutDlgProc);
                break;
            case ID_Na:
                {

                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'1','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"1");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nb:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'2','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"2");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nc:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'3','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"3");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nd:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'4','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"4");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Ne:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'5','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"5");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nf:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'6','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"6");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Ng:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'7','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"7");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nh:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0; //op is pressed so equal button should work now
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'8','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"8");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Ni:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0;
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'9','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"9");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                     outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nj:
                {
                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0;
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[3]={'0','.','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,".");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                     outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nk:
                {

                    eqeq=1;  // declare that a number is entered
                    if (eqeqop==1) eqeq=0;
                    doNoth();
                    if (flag==0 || mismis==1) {
                        char out[2]={'0','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else {
                        strcat(outG,"0");
                        SetWindowText(hEdit,outG);

                    }
                    mismis=0; //to say last pressed was not X
                    outCame=0; //number is entered so screen no longer has output
                }
                break;
            case ID_Nmis:
                {
                    char tempmis[200];
                    int strlenh=GetWindowText(hEdit,tempmis,200);
                    string cut(tempmis);
                    //if (eqeqop==1) eqeqop=0;
                    int i=strlenh-1;
                    cut.erase(i,1);
                    if (outCame==1) {
                        //do what X button do when screen has output
                        goto miscaseEnd;
                    }
                    doNoth();
                    if (strlenh>1) {
                    strcpy(outG,cut.c_str());
                    SetWindowText(hEdit,outG);
                    }
                    else {
                        char out[2]={'0','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        mismis=1;

                    }
                    miscaseEnd:
                    outCame=0;

                }
                break;
            case ID_Nl:
                {
                    if (eqeq==1) goto eqend;
                    numep=GetWindowText(hEdit,inputBL,200);
                    oprandSearch(inputBL,numep,numil);
                    //SetWindowText(hEdit,"0");
                    //opArthmatic(opflag);
                    if (opArthmatic(opflag)) goto eqend;
                    //MessageBox(NULL,resultS.c_str(),"",MB_OK);
                    SetWindowText(hEdit,resultS.c_str());
                    outCame=1;
                    flag=0;
                    eqeq=0;
                    eqeqop=0;
                    opflag=0;
                    eqend:;
                }
                break;
            case ID_Nplus:
                {


                    eqeqop=1;
                    eqeq=1;  //declare op is entered
                    numil=GetWindowText(hEdit,inputA,50);
                    //MessageBox(NULL,inputA,"",MB_OK);
                    checkMultiOp=checkMultiop(inputA,0,numil);
                    if (checkMultiOp==1) {
                        MessageBox(hwnd,"too many continuous operators","Alert",MB_ICONERROR|MB_OK);
                        goto youp;
                    }
                    inputAi=stod(inputA);  //converts char array to int
                    if (numil>10) {
                        MessageBox(NULL,"Sorry I can't handle that much data", "Alert", MB_OK | MB_ICONEXCLAMATION);
                        SetWindowText(hEdit,"0");
                    }
                    else if (outCame==1) {
                        //char out[3]={'0','+','\0'};
                        strcpy(outG,resultS.c_str());
                        strcat(outG,"+");
                        SetWindowText(hEdit,outG);
                        flag=1;
                        outCame=0;
                    }
                    else if (flag==0 || mismis==1) {
                        char out[3]={'0','+','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else if (flag!=0){
                        strcat(outG,"+");
                        SetWindowText(hEdit,outG);

                    }
                    opflag=1;    //tells op is + ie 1
                    youp:
                    checkMultiOp=0; //reinitialize
                    mismis=0;
                }
                break;
            case ID_Nminus:
                {


                    eqeqop=1;
                    eqeq=1;  //declare op is entered
                    numil=GetWindowText(hEdit,inputA,50);
                    checkMultiOp=checkMultiop(inputA,1,numil);
                    if (checkMultiOp==1) {
                        MessageBox(hwnd,"too many continuous operators","Alert",MB_ICONERROR|MB_OK);
                        goto youpmi;
                    }
                    inputAi=stod(inputA);  //converts char array to int
                    if (numil>10) {
                        MessageBox(NULL,"Sorry I can't handle that much data", "Alert", MB_OK | MB_ICONEXCLAMATION);
                        SetWindowText(hEdit,"0");
                    }
                    else if (outCame==1) {
                        //char out[3]={'0','+','\0'};
                        strcpy(outG,resultS.c_str());
                        strcat(outG,"-");
                        SetWindowText(hEdit,outG);
                        flag=1;
                        outCame=0;
                    }
                    else if (flag==0 || mismis==1) {
                        char out[3]={'0','-','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else if (flag!=0){
                        strcat(outG,"-");
                        SetWindowText(hEdit,outG);

                    }
                    opflag=2;    //tells op is plus ie 1
                    youpmi:
                    checkMultiOp=0; //reinitialize
                    mismis=0;
                }
                break;
            case ID_Nmulti:
                {


                    eqeqop=1;
                    eqeq=1;  //declare op is entered
                    numil=GetWindowText(hEdit,inputA,50);
                    checkMultiOp=checkMultiop(inputA,2,numil);
                    if (checkMultiOp==1) {
                        MessageBox(hwnd,"too many continuous operators","Alert",MB_ICONERROR|MB_OK);
                        goto youpmul; //go to end of this command
                    }
                    inputAi=stod(inputA);  //converts char array to int
                    if (numil>10) {
                        MessageBox(NULL,"Sorry I can't handle that much data", "Alert", MB_OK | MB_ICONEXCLAMATION);
                        SetWindowText(hEdit,"0");
                    }
                    else if (outCame==1) {
                        //char out[3]={'0','+','\0'};
                        strcpy(outG,resultS.c_str());
                        strcat(outG,"*");
                        SetWindowText(hEdit,outG);
                        flag=1;
                        outCame=0;
                    }
                    else if (flag==0 || mismis==1) {
                        char out[3]={'0','*','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else if (flag!=0){
                        strcat(outG,"*");
                        SetWindowText(hEdit,outG);

                    }
                    opflag=3;    //tells op is * ie 3
                    youpmul:
                    checkMultiOp=0; //reinitialize
                    mismis=0;
                }
                break;
            case ID_Ndivide:
                {


                    eqeqop=1;
                    eqeq=1;  //declare op is entered
                    numil=GetWindowText(hEdit,inputA,50);
                    checkMultiOp=checkMultiop(inputA,4,numil);
                    if (checkMultiOp==1) {
                        MessageBox(hwnd,"too many continuous operators","Alert",MB_ICONERROR|MB_OK);
                        goto youpmdiv;
                    }
                    inputAi=stod(inputA);  //converts char array to int
                    if (numil>10) {
                        MessageBox(NULL,"Sorry I can't handle that much data", "Alert", MB_OK | MB_ICONEXCLAMATION);
                        SetWindowText(hEdit,"0");
                    }
                    else if (outCame==1) {
                        //char out[3]={'0','+','\0'};
                        strcpy(outG,resultS.c_str());
                        strcat(outG,"/");
                        SetWindowText(hEdit,outG);
                        flag=1;
                        outCame=0;
                    }
                    else if (flag==0 || mismis==1) {
                        char out[3]={'0','/','\0'};
                        strcpy(outG,out);
                        SetWindowText(hEdit,outG);
                        flag=1;
                    }
                    else if (flag!=0){
                        strcat(outG,"/");
                        SetWindowText(hEdit,outG);

                    }
                    opflag=4;    //tells op is / ie 4
                    youpmdiv:
                    checkMultiOp=0; //reinitialize
                    mismis=0;
                }
                break;
            }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        case WM_CREATE:
    {

        addControls(hwnd);

    }
    break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
    wc.hCursor       = LoadCursor(NULL, IDC_HAND);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MYMENU);
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "my windows",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 240,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

void addControls(HWND hwnd) {
    buttOn(L"1",ID_Na,5,35,55,30);
    buttOn(L"2",ID_Nb,62,35,55,30);
    buttOn(L"3",ID_Nc,119,35,55,30);
    buttOn(L"4",ID_Nd,5,67,55,30);
    buttOn(L"5",ID_Ne,62,67,55,30);
    buttOn(L"6",ID_Nf,119,67,55,30);
    buttOn(L"7",ID_Ng,5,99,55,30);
    buttOn(L"8",ID_Nh,62,99,55,30);
    buttOn(L"9",ID_Ni,119,99,55,30);
    buttOn(L".",ID_Nj,5,131,55,30);
    buttOn(L"0",ID_Nk,62,131,55,30);
    buttOn(L"=",ID_Nl,119,131,55,30);
    buttOn(L"+",ID_Nplus,177,35,40,30);
    buttOn(L"-",ID_Nminus,177,67,40,30);
    buttOn(L"/",ID_Ndivide,177,99,40,30);
    buttOn(L"*",ID_Nmulti,177,131,40,30);
    buttOn(L"X",ID_Nmis,177,5,40,24);

    //edit box
    hEdit= CreateWindowW(L"Edit", L"0",
	WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_RIGHT | ES_NUMBER,
	5, 5, 170, 24,	// x, y, w, h
	hwnd, NULL,
	GetModuleHandle(NULL),NULL);
	//exceptioin handling
	if(hEdit == NULL) MessageBox(hwnd, "Could not create edit box.", "Error", MB_OK | MB_ICONERROR);


}

void oprandSearch(char arr[],int nu,int n) {
    //nu is size of arr[]
    //n is size of inputA excluding null chracter
    int i;
    int temp=0;
    n=n+1;   //in 'n' we have operator but we want next char so we did it
    for (i=n;i<nu;i++) {
        inputB[temp]=arr[i];
        temp++;
    }
    inputBi=stod(inputB);
    /*inputB=arr.substr((n+1),(nu-n)); //c++ code
    inputBi=stod(inputB);*/
}

void cStrDel(char *str,int m,int n) {
    // m is size of  string
    //n is index of value which u want to delete
    //for lasr element idex is m-1
    int i;
    for (i=n;i<m;i++) {
        str[i]=str[i+1];
    }
}

int arrSize(char arr[]) {
    int i,l=0;
    for (i=0;i<30000;i++) {
        if (arr[i]=='\0') break;
        l++;
    }
    return l;
}



int reverseNum(int num) {
	int i,result=0,l=0;
    int temp;
    double temp1;
    int arr[12];
	int arrR[11];
    for (i=0;num>0;i++) {
        temp=num%10;
        num=num/10;
        arr[i]=temp;
        l++;
        arr[i]=temp;
    }

	// storing reverse of array in other array
	temp=l-1;
	for (i=0;i<l;i++) {
		arrR[temp]=arr[i];
		temp--;
	}

	//generating single number by array
	for (i=0;i<l;i++) {
		temp=arrR[i];
		temp1=pow(10,i);
		result = result + (temp*temp1);

	}
	temp=0;
	return result;
}


int checkMultiop(char arr[],int n,int nu) {
    //nu is size of array excluding null charater
    // n is int for op i.e. (+:0,-:1,*:2,/:3....)
    int i,j=0;
    char op[]={'+','-','*','/'};
    i=nu-1;
    if (arr[i]==op[0]) j=1;
    else if (arr[i]==op[1]) j=1;
    else if (arr[i]==op[2]) j=1;
    else if (arr[i]==op[3]) j=1;
    return j;
}

int opArthmatic(int n) {
    //int i,j;
    if (n==0) {

    }
    else if (n==1) {
        result = inputAi + inputBi;
        resultTemp = result - (int)result;
        resultRound=to_string(resultTemp);
        //MessageBox(NULL,resultRound.c_str(),"",MB_OK);
        if (resultTemp>0) {
          resultS=to_string(result);
          removeTailingZero(resultS);
        }
        else {
        resultS=to_string((int)result);
        }
        //
    }
    else if (n==2) {
        /*if (inputAi>inputBi)
        result = inputAi - inputBi;
        else
            result = inputBi-inputAi;
        resultS=to_string(result);*/
        result = inputAi - inputBi;
        resultTemp = result - (int)result;
        resultRound=to_string(resultTemp);
        //MessageBox(NULL,resultRound.c_str(),"",MB_OK);
        if (resultTemp>0) {
          resultS=to_string(result);
          removeTailingZero(resultS);
        }
        else {
        resultS=to_string((int)result);
        }
    }
    else if (n==3) {
        result = inputAi * inputBi;
        resultTemp = result - (int)result;
        resultRound=to_string(resultTemp);
        //MessageBox(NULL,resultRound.c_str(),"",MB_OK);
        if (resultTemp>0) {
          resultS=to_string(result);
          removeTailingZero(resultS);
        }
        else {
        resultS=to_string((int)result);
        }
    }
    else if (n==4) {
        if (inputBi==0) {
            SetWindowText(hEdit,"Can't divide by zero");
            cStrDel(outG,strlen(outG),(strlen(outG)-1));
            return 1;
        }
        result = inputAi / inputBi;
        resultTemp = result - (int)result;
        resultRound=to_string(resultTemp);
        //MessageBox(NULL,resultRound.c_str(),"",MB_OK);
        if (resultTemp>0) {
          resultS=to_string(result);
          removeTailingZero(resultS);
        }
        else {
        resultS=to_string((int)result);
        }
    }
    return 0;

}

void removeTailingZero(string str) {
    int j=1,k=1;

    for (;k==1;) {
    j=(str.size())-1;
    if (str[j]=='.') {
            str.erase(j,1);
        k=0;
    }
    doNoth();
    if (str[j]=='0')
        str.erase(j,1);
    else k=0;
    }
    resultS=str;
    //MessageBox(NULL,str.c_str(),"",MB_OK);

}

string removeSpaces(string str,int n)
{
    if (n>0) n=n-1;
    str.erase(n, 1);
    return str;
}

void doNoth()
{
    //dont do anything here
}
