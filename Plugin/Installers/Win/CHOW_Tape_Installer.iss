[Setup]
AppName=CHOWTapeModel
AppVersion=1.0.0
DisableWelcomePage=no
DisableDirPage=yes
LicenseFile=..\Chowdhury_DSP_License.rtf
DefaultDirName={cf}
DefaultGroupName=CHOWTapeModel
OutputBaseFilename=CHOWTapeModel-Win-1.0.0

[Types]
Name: "full"; Description: "Full installation"
Name: "custom"; Description: "Custom installation"; Flags: iscustom

[Components]
Name: "VST"; Description: "VST Plugin"; Types: full;
Name: "VST3"; Description: "VST3 Plugin"; Types: full
Name: "Standalone"; Description: "Standalone Plugin"; Types: full

[Files]
Source: "..\..\Bin\Win\CHOWTapeModel.dll"; DestDir: "{code:GetDir|VST}"; Components: VST
Source: "..\..\Bin\Win\CHOWTapeModel.vst3"; DestDir: "{code:GetDir|VST3}"; Components: VST3
Source: "..\..\Bin\Win\CHOWTapeModel.exe"; DestDir: "{code:GetDir|Stand}"; Components: Standalone
//Source: "CHOWTapeModel.dpm"; DestDir: "{app}\Digidesign\DAE\Plug-Ins"
//Source: "CHOWTapeModel.aaxplugin\*"; DestDir: "{app}\Avid\Audio\Plug-In\CHOWTapeModel.aaxplugin"; Flags: recursesubdirs

[Messages]
WelcomeLabel2=This will install CHOWTapeModel on your computer.%n%nTape sound has been known to cause extreme hysteresis. Proceed with caution, and consider yourself warned.

[Code]
var
  VstDirPage: TInputDirWizardPage;
  Vst3DirPage: TinputDirWizardPage;
  StandDirPage: TinputDirWizardPage;

procedure InitializeWizard;
begin
  //VST Dir Page
  VstDirPage := CreateInputDirPage(wpSelectComponents,
    'Select VST Install Location', 'Where would you like to install the VST plugin?',
    'VST plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  VstDirPage.add('');
  VstDirPage.values[0] := ExpandConstant('{pf64}\Steinberg\VST2');

  //VST3 Dir Page
  Vst3DirPage := CreateInputDirPage(VstDirPage.ID,
    'Select VST3 Install Location', 'Where would you like to install the VST3 plugin?',
    'VST3 plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  Vst3DirPage.add('');
  Vst3DirPage.values[0] := ExpandConstant('{pf64}\Steinberg\VST3');

  //Standalone Dir Page
  StandDirPage := CreateInputDirPage(Vst3DirPage.ID,
    'Select Standalone Install Location', 'Where would you like to install the standalone plugin?',
    'Standalone plugin will be installed in the following folder.'#13#10#13#10 +
    'To continue, click Next. If you would like to select a different folder, click Browse.',
    False, 'New Folder');

  StandDirPage.add('');
  StandDirPage.values[0] := ExpandConstant('{pf64}\ChowDSP');
end;

function IsSelected(Param: String) : Boolean;
begin
  if (Param = 'VST') and ((CompareText(WizardSelectedComponents(False), 'VST,VST3,Standalone') = 0)
                        or (CompareText(WizardSelectedComponents(False), 'VST,Standalone') = 0)
                        or (CompareText(WizardSelectedComponents(False), 'VST,VST3') = 0)
                        or (CompareText(WizardSelectedComponents(False), 'VST') = 0)) then
    Result := True
  else if (Param = 'VST3') and ((CompareText(WizardSelectedComponents(False), 'VST,VST3,Standalone') = 0)
                              or (CompareText(WizardSelectedComponents(False), 'VST3,Standalone') = 0)
                              or (CompareText(WizardSelectedComponents(False), 'VST,VST3') = 0)
                              or (CompareText(WizardSelectedComponents(False), 'VST3') = 0)) then
    Result := True
  else if (Param = 'Stand') and ((CompareText(WizardSelectedComponents(False), 'VST,VST3,Standalone') = 0)
                              or (CompareText(WizardSelectedComponents(False), 'VST3,Standalone') = 0)
                              or (CompareText(WizardSelectedComponents(False), 'VST,Standalone') = 0)
                              or (CompareText(WizardSelectedComponents(False), 'Standalone') = 0)) then
    Result := True                                                       
end;

function ShouldSkipPage(PageID: Integer): Boolean;
begin
  { Skip pages that shouldn't be shown }
  Result := False;

  if (PageID = VstDirPage.ID) then
  begin
    Result := True;
    Log('Selected 1: ' + WizardSelectedComponents(False)); 

    if IsSelected ('VST') then
    begin
      Log('Not Skipping page');
      Result := False;
    end
  end

  else if (PageID = Vst3DirPage.ID) then
  begin
      Result := True;
      Log('Selected 2: ' + WizardSelectedComponents(False));

      if IsSelected ('VST3') then
      begin
        Log('Not Skipping');
        Result := False;
      end
  end

  else if (PageID = StandDirPage.ID) then
  begin
      Result := True;
      Log('Selected 3: ' + WizardSelectedComponents(False));

      if IsSelected('Stand') then
      begin
        Log('Not Skipping page');
        Result := False;
      end
  end
end;

function GetDir(Param: String) : String;
begin
  if (Param = 'VST') then
    Result := VstDirPage.values[0]
  else if (Param = 'VST3') then
    Result := Vst3DirPage.values[0]
  else if (Param = 'Stand') then
    Result := StandDirPage.values[0]
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

  if IsSelected('VST') then
    S := S + Space +  GetDir('VST') + ' (VST)' + NewLine;

  if IsSelected('VST3') then
    S := S + Space +  GetDir('VST3') + ' (VST3)' + NewLine;

  if IsSelected('Stand') then
    S := S + Space +  GetDir('Stand') + ' (Standalone)' + NewLine;

  Result := S;
end;


