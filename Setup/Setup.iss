; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define ApplicationName "POPTools"
#define ApplicationVersion GetFileVersion("..\bin\POPTools.exe")

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{943E92A3-A70E-415D-B55D-44C8C15FE3F6}
AppName={#ApplicationName}
AppVerName={#ApplicationName} {#ApplicationVersion}
AppVersion={#ApplicationVersion}
AppPublisher=Tecnequip Tecnologia em Equipamentos Ltda
AppPublisherURL=http://www.tecnequip.com.br/
AppSupportURL=http://www.tecnequip.com.br/
AppUpdatesURL=http://www.tecnequip.com.br/
DefaultDirName={pf}\POPTools
DefaultGroupName=POPTools
OutputDir=..\Setup
OutputBaseFilename=POPTools_Setup_v2.1
Compression=lzma
SolidCompression=yes
ChangesAssociations=yes
MinVersion="6.1"

[Languages]
Name: "ptbr"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"; LicenseFile: "..\Setup\EULA_PTBR.txt"
Name: "en"; MessagesFile: "compiler:Default.isl"; LicenseFile: "..\Setup\EULA_PTBR.txt"
Name: "es"; MessagesFile: "compiler:Languages\Spanish.isl"; LicenseFile: "..\Setup\EULA_ES.txt"

[CustomMessages]
en.InstallingLabel=Please wait...
es.InstallingLabel=Favor aguardar...
ptbr.InstallingLabel=Favor aguardar...

; [Types]
; Name: "full"; Description: "Instala��o Completa"
; Name: "compact"; Description: "Instala��o Compacta"
; Name: "custom"; Description: "Instala��o Personalizada"; Flags: iscustom

; [Components]
; Name:"Principal"; Description:"POPTools vers�o 1.2"; Types: full compact custom; Flags: fixed
; Name:"DriverUSB"; Description:"Driver USB para grava��o da POP-7"; Types: full custom

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "installusbdriver"; Description: "Instalar Driver USB"; GroupDescription: "Drivers:"; Languages: ptbr
Name: "installusbdriver"; Description: "Install USB Driver"; GroupDescription: "Drivers:"; Languages: en
Name: "installusbdriver"; Description: "Instalar Driver USB"; GroupDescription: "Drivers:"; Languages: es
; Name: "restart"; Description: "Reiniciar o computador. A reinicializa��o do computador � necess�ria para o correto funcionamento do compilador que acompanha o programa POP7Tools. (mais informa��es em http://www.yagarto.de)"; Flags: restart

[Files]
Source: "..\bin\POPTools.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "settings_ptbr.dat"; DestDir: "{app}"; Languages: ptbr; Flags: ignoreversion
Source: "settings_en.dat"; DestDir: "{app}"; DestName: "settings.dat"; Languages: en; Flags: ignoreversion
Source: "settings_es.dat"; DestDir: "{app}"; DestName: "settings.dat"; Languages: es; Flags: ignoreversion
Source: "..\Help\Ajuda.chm"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\Setup\EULA_PTBR.TXT"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\Setup\EULA_EN.TXT"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\Setup\EULA_ES.TXT"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\flashmagicarmcortex.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\bin\src\POP7\*.h"; DestDir: "{app}\src\POP7"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP7\*.a"; DestDir: "{app}\src\POP7"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP7\*.ld"; DestDir: "{app}\src\POP7"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP7\*.o"; DestDir: "{app}\src\POP7"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP7\compile"; DestDir: "{app}\src\POP7"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP8\*.h"; DestDir: "{app}\src\POP8"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP8\*.a"; DestDir: "{app}\src\POP8"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP8\*.ld"; DestDir: "{app}\src\POP8"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP8\*.o"; DestDir: "{app}\src\POP8"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\src\POP8\compile"; DestDir: "{app}\src\POP8"; Permissions: users-modify; Flags: ignoreversion
Source: "..\bin\gcc\POP7\*.h"; DestDir: "{app}\gcc\POP7"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP7\*.a"; DestDir: "{app}\gcc\POP7"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP7\*.o"; DestDir: "{app}\gcc\POP7"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP7\*.dll"; DestDir: "{app}\gcc\POP7"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP7\*.exe"; DestDir: "{app}\gcc\POP7"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP8\*.h"; DestDir: "{app}\gcc\POP8"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP8\*.a"; DestDir: "{app}\gcc\POP8"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP8\*.o"; DestDir: "{app}\gcc\POP8"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP8\*.dll"; DestDir: "{app}\gcc\POP8"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\bin\gcc\POP8\*.exe"; DestDir: "{app}\gcc\POP8"; Permissions: users-modify; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\examples\*"; DestDir: "{app}\examples"; Permissions: users-readexec; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "..\Setup\CP210x_VCP_Win_XP_S2K3_Vista_7.exe"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\POPTools"; Filename: "{app}\POPTools.exe"
Name: "{group}\Manual do Usuario"; Filename: "{app}\Ajuda.chm"
Name: "{group}\Licen�a de Uso"; Filename: "{app}\EULA_PTBR.TXT"; Languages: ptbr
Name: "{group}\End User License Agreement"; Filename: "{app}\EULA_EN.TXT"; Languages: en
Name: "{group}\Licen�a de Uso"; Filename: "{app}\EULA_ES.TXT"; Languages: es
Name: "{commondesktop}\POPTools"; Filename: "{app}\POPTools.exe"; Tasks: desktopicon

[Registry]
Root: HKCR; Subkey: ".ld"; ValueType: string; ValueName: ""; ValueData: "POPToolsFiles"; Flags: uninsdeletevalue
Root: HKCR; Subkey: ".bld"; ValueType: string; ValueName: ""; ValueData: "POPToolsFiles"; Flags: uninsdeletevalue
Root: HKCR; Subkey: "POPToolsFiles"; ValueType: string; ValueName: ""; ValueData: "POPTools Files"; Flags: uninsdeletekey
Root: HKCR; Subkey: "POPToolsFiles\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\POPTools.exe,0"
Root: HKCR; Subkey: "POPToolsFiles\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\POPTools.exe"" ""%1"""

[Run]
Filename: "{app}\CP210x_VCP_Win_XP_S2K3_Vista_7.exe"; StatusMsg: "Aguardando finalizar instala��o do Driver USB"; Tasks: installusbdriver
Filename: "{app}\POPTools.exe"; Description: "{cm:LaunchProgram,POPTools}"; Flags: nowait postinstall skipifsilent

[Code]
procedure InitializeWizard;
begin
  with TNewStaticText.Create(WizardForm) do
  begin
    Parent := WizardForm.FilenameLabel.Parent;
    Left := WizardForm.FilenameLabel.Left;
    Top := WizardForm.FilenameLabel.Top;
    Width := WizardForm.FilenameLabel.Width;
    Height := WizardForm.FilenameLabel.Height;
    Caption := ExpandConstant('{cm:InstallingLabel}');
  end;
  WizardForm.FilenameLabel.Visible := False;
end;
