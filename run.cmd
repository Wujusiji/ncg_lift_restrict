@echo off
reg delete HKCU\software\policies /f
reg delete HKCU\software\microsoft\windows\currentversion\policies /f
reg delete HKLM\software\policies /f
reg delete HKLM\software\microsoft\policies /f
reg delete HKLM\software\microsoft\windows\currentversion\policies /f
taskkill.exe /f /im explorer.exe
taskkill.exe /f /im DesktopMgr64.exe
start /d %USERPROFILE% C:\Windows\explorer.exe
exit /b
