#!/bin/sh

app_version=$(cut -f 2 -d '=' <<< "$(grep 'CMAKE_PROJECT_VERSION:STATIC' ../../build32/CMakeCache.txt)")
echo "Setting app version: $app_version..."

echo "Creating 64-bit installer..."
script_file=ChowTapeModel_Install_Script.iss
sed -i "s/##APPVERSION##/${app_version}/g" $script_file
$"C:\Program Files (x86)\Inno Setup 6\ISCC.exe" $script_file
sed -i "s/${app_version}/##APPVERSION##/g" $script_file # reset version number

echo "Creating 32-bit installer..."
script_file=ChowTapeModel_Install_Script_32bit.iss
sed -i "s/##APPVERSION##/${app_version}/g" $script_file
$"C:\Program Files (x86)\Inno Setup 6\ISCC.exe" $script_file
sed -i "s/${app_version}/##APPVERSION##/g" $script_file # reset version number

exec="ChowTapeModel-Win-$app_version.exe"
direc=$PWD

# sign
# echo "Signing installer..."
# $"cd" "C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\x64"
# $"./signtool.exe" sign -tr http://timestamp.digicert.com -td sha256 -fd sha256 -a -debug $direc/$exec
# $"./signtool.exe" verify -pa $direc/$exec

echo SUCCESS
