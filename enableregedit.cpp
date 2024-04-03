#include <windows.h>
#include <iostream>

int main() {
    HKEY hKey;
    LPCSTR subKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"; // 定位到对应注册表项

    // 打开或创建注册表键
    LONG openResult = RegCreateKeyExA(HKEY_CURRENT_USER, subKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
    if (openResult != ERROR_SUCCESS) {
        std::cerr << "Failed to open or create registry key." << std::endl;
        system("pause");
        return 1;
    }

    // 设置一个值到注册表中
    LPCSTR valueName = "DisableRegistryTools"; // 创建名为禁用注册表编辑器的DWORD
    DWORD valueData = 0; // 0为启用，1为禁用
    DWORD dataSize = sizeof(valueData);
    LONG setResult = RegSetValueExA(hKey, valueName, 0, REG_DWORD, reinterpret_cast<BYTE*>(&valueData), dataSize);
    if (setResult != ERROR_SUCCESS) {
        std::cerr << "Failed to set registry value." << std::endl;
        RegCloseKey(hKey);
        system("pause");
        return 1;
    }

    // 关闭注册表键，然后启动regedit
    RegCloseKey(hKey);
    std::cout << "Registry Editor will launch, program will exit." << std::endl;
    system("start regedit.exe");
    system("pause");

    return 0;
}
