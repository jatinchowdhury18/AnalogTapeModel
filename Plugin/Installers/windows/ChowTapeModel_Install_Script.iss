#define MyAppPublisher "Chowdhury DSP"
#define MyAppURL "https://chowdsp.com"
#define MyAppName "ChowTapeModel"
#define MyAppVersion "##APPVERSION##"

[Setup]
AppName="{#MyAppName} {#MyAppVersion}"
AppVersion={#MyAppVersion}
AppVerName={#MyAppName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={commonpf64}\Chowdhury DSP\
DefaultGroupName={#MyAppName}
DisableProgramGroupPage=yes
DisableDirPage=yes
DisableWelcomePage=no
LicenseFile=../../../LICENSE
OutputBaseFilename="ChowTapeModel-Win-{#MyAppVersion}"
OutputDir=.
SetupIconFile=chowtape.ico
UninstallDisplayIcon=chowtape.ico
UninstallFilesDir={commonpf64}\Chowdhury DSP\{#MyAppName}
Compression=lzma
SolidCompression=yes

[Types]
Name: "full"; Description: "Full installation"
Name: "custom"; Description: "Custom installation"; Flags: iscustom

[Components]
Name: "VST3_64"; Description: "VST3 Plugin 64-bit"; Types: full
Name: "VST_64"; Description: "VST Plugin 64-bit"; Types: full
Name: "VST3_32"; Description: "VST3 Plugin 32-bit"; Types: full
Name: "VST_32"; Description: "VST Plugin 32-bit"; Types: full
Name: "Standalone"; Description: "Standalone Plugin"; Types: full
; Name: "AAX"; Description: "AAX Plugin"; Types: full

[Files]
Source: "../../Bin/Win64/CHOWTapeModel.vst3"; DestDir: "{code:GetDir|VST3_64}"; Components: VST3_64; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "../../Bin/Win64/CHOWTapeModel.dll"; Excludes: "*.vst3"; DestDir: "{code:GetDir|VST_64}"; Components: VST_64; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "../../Bin/Win32/CHOWTapeModel.vst3"; DestDir: "{code:GetDir|VST3_32}"; Components: VST3_32; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "../../Bin/Win32/CHOWTapeModel.dll"; Excludes: "*.vst3"; DestDir: "{code:GetDir|VST_32}"; Components: VST_32; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "../../Bin/Win64/CHOWTapeModel.exe"; Excludes: "*.vst3"; DestDir: "{code:GetDir|Standalone}"; Components: Standalone; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"

[Code]
var
  AAXDirPage: TInputDirWizardPage;
  Vst3_64DirPage: TinputDirWizardPage;
  Vst_64DirPage: TinputDirWizardPage;
  Vst3_32DirPage: TinputDirWizardPage;
  Vst_32DirPage: TinputDirWizardPage;
  StandaloneDirPage: TinputDirWizardPage;

procedure InitializeWizard;
begin
  Log('Initializing extra pages')
  //AAX Dir Page
  AAXDirPage := CreateInputDirPage(wpSelectComponents,
    'Select AAX Install Location', 'Where would you like to install the AAX plugin?',
    'AAX plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  AAXDirPage.add('');
  AAXDirPage.values[0] := ExpandConstant('{commoncf64}\Avid\Audio\Plug-Ins');

  //VST3 64-bit Dir Page
  Vst3_64DirPage := CreateInputDirPage(AAXDirPage.ID,
    'Select Install Location for VST3 64-bit', 'Where would you like to install the plugin?',
    'VST3 64-bit plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  Vst3_64DirPage.add('');
  Vst3_64DirPage.values[0] := ExpandConstant('{commoncf64}\VST3');

  //VST 64-bit Dir Page
  Vst_64DirPage := CreateInputDirPage(Vst3_64DirPage.ID,
    'Select Install Location for VST 64-bit', 'Where would you like to install the plugin?',
    'VST 64-bit plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  Vst_64DirPage.add('');
  Vst_64DirPage.values[0] := ExpandConstant('{commoncf64}\VST');

  //VST3 32-bit Dir Page
  Vst3_32DirPage := CreateInputDirPage(Vst_64DirPage.ID,
    'Select Install Location for VST3 32-bit', 'Where would you like to install the plugin?',
    'VST3 32-bit plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  Vst3_32DirPage.add('');
  Vst3_32DirPage.values[0] := ExpandConstant('{commoncf32}\VST3');

  //VST 32-bit Dir Page
  Vst_32DirPage := CreateInputDirPage(Vst3_32DirPage.ID,
    'Select Install Location for VST 32-bit', 'Where would you like to install the plugin?',
    'VST 32-bit plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  Vst_32DirPage.add('');
  Vst_32DirPage.values[0] := ExpandConstant('{commoncf32}\VST');

  //Standalone Dir Page
  StandaloneDirPage := CreateInputDirPage(Vst_32DirPage.ID,
    'Select Install Location for Standalone', 'Where would you like to install the plugin?',
    'Standalone plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');
  StandaloneDirPage.add('');
  StandaloneDirPage.values[0] := ExpandConstant('{pf64}\Chowdhury DSP');
end;

function IsSelected(Param: String) : Boolean;
begin
  if not (Pos(Param, WizardSelectedComponents(False)) = 0) then // WizardSelectedComponents(False)) then
    Result := True
end;

function ShouldSkipPage(PageID: Integer): Boolean;
begin
  { Skip pages that shouldn't be shown }
  Result := False;

  if (PageID = AAXDirPage.ID) then
  begin
    Result := True;
    Log('Selected 1: ' + WizardSelectedComponents(False)); 

    if IsSelected ('aax') then
    begin
      Log('Not Skipping page');
      Result := False;
    end
  end

  else if (PageID = Vst3_64DirPage.ID) then
  begin
      Result := True;
      Log('Selected 2: ' + WizardSelectedComponents(False));

      if IsSelected ('vst3_64') then
      begin
        Log('Not Skipping');
        Result := False;
      end
  end

  else if (PageID = Vst3_32DirPage.ID) then
  begin
      Result := True;
      Log('Selected 3: ' + WizardSelectedComponents(False));

      if IsSelected ('vst3_32') then
      begin
        Log('Not Skipping');
        Result := False;
      end
  end

  else if (PageID = Vst_64DirPage.ID) then
  begin
      Result := True;
      Log('Selected 4: ' + WizardSelectedComponents(False));

      if IsSelected ('vst_64') then
      begin
        Log('Not Skipping');
        Result := False;
      end
  end

  else if (PageID = Vst_32DirPage.ID) then
  begin
      Result := True;
      Log('Selected 5: ' + WizardSelectedComponents(False));

      if IsSelected ('vst_32') then
      begin
        Log('Not Skipping');
        Result := False;
      end
  end
  
  else if (PageID = StandaloneDirPage.ID) then
  begin
      Result := True;
      Log('Selected 6: ' + WizardSelectedComponents(False));
      if IsSelected ('standalone') then
      begin
        Log('Not Skipping');
        Result := False;
      end
  end
end;

function GetDir(Param: String) : String;
begin
  if (Param = 'AAX') then
    Result := AAXDirPage.values[0]
  else if (Param = 'VST3_64') then
    Result := Vst3_64DirPage.values[0]
  else if (Param = 'VST3_32') then
    Result := Vst3_32DirPage.values[0]
  else if (Param = 'VST_64') then
    Result := Vst_64DirPage.values[0]
  else if (Param = 'VST_32') then
    Result := Vst_32DirPage.values[0]
  else if (Param = 'Standalone') then
    Result := StandaloneDirPage.values[0]
end;

function UpdateReadyMemo(Space, NewLine, MemoUserInfoInfo, MemoDirInfo, MemoTypeInfo,
  MemoComponentsInfo, MemoGroupInfo, MemoTasksInfo: String): String;
var
  S: String;
begin
  { Fill the 'Ready Memo' with the normal settings and the custom settings }
  S := '';
  S := S + MemoTypeInfo + NewLine + NewLine;
  S := S + MemoComponentsInfo + NewLine + NewLine;
  S := S + 'Destination Location:' + NewLine;

  if IsSelected('aax') then
    S := S + Space +  GetDir('AAX') + ' (AAX)' + NewLine;

  if IsSelected('vst3_64') then
    S := S + Space +  GetDir('VST3_64') + ' (VST3 64-bit)' + NewLine;

  if IsSelected('vst_64') then
    S := S + Space +  GetDir('VST_64') + ' (VST 64-bit)' + NewLine;

  if IsSelected('vst3_32') then
    S := S + Space +  GetDir('VST3_32') + ' (VST3 32-bit)' + NewLine;

  if IsSelected('vst_32') then
    S := S + Space +  GetDir('VST_32') + ' (VST 32-bit)' + NewLine;

  if IsSelected('standalone') then
    S := S + Space +  GetDir('Standalone') + ' (Standalone)' + NewLine;

  Result := S;
end;
