;******************************************
;PE������Ⱦ�����ļ�
;�ļ�����host_pe.asm
;*****************************************
.386
.model flat,stdcall
option casemap:none

include C:\RadASM\masm32\include\windows.inc
include C:\RadASM\masm32\include\kernel32.inc
include C:\RadASM\masm32\include\user32.inc
includelib C:\RadASM\masm32\lib\kernel32.lib
includelib C:\RadASM\masm32\lib\user32.lib

.data
szText     db       "����һ��PE����",0
szCaption  db       "��Ⱦ����Ŀ��",0

.code
main:
    invoke MessageBox,NULL, addr szText, addr szCaption,MB_OK
    invoke ExitProcess,0
end main
