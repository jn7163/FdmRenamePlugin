@echo off
::batɾ����ǰĿ¼����������Ŀ¼�еĳ�EXE�ļ��������VC��ʱ�ļ�

echo ɾ��vc�����������ʱ�ļ�

echo ɾ����ʼ...

::for /r . %%c in (.) do @if exist "%%c\Debug" rd /s /q "%%c\Debug"

::for /r . %%c in (.) do @if exist "%%c\Release" rd /s /q "%%c\Release"

for /r . %%c in (*.obj *.pch *.htm *.dep *.idb *.pdb *.manifest *.ilk *.res *.sbr *tlh *tli *.bsc *.aps *.clw *.ncb *.plg *.positions *.ww *.user) do del "%%c"

::�ݹ�ɾ����ǰĿ¼�µ����п�Ŀ¼
for /f "delims=" %%a in ('dir . /b /ad /s ^|sort /r' ) do rd /q "%%a" 2>nul

for /r . %%c in ("*va_c__documents and settings_administrator_local settings_application data_visualassist_vc6_history_") do del "%%c"

echo ɾ�����...

pause

