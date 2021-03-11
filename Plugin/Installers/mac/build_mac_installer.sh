#!/bin/bash

script_file=ChowTapeModel.pkgproj

app_version=$(cut -f 2 -d '=' <<< "$(grep 'CMAKE_PROJECT_VERSION:STATIC' ../../build/CMakeCache.txt)")
echo "Setting app version: $app_version..."
sed -i '' "s/##APPVERSION##/${app_version}/g" $script_file
sed -i '' "s/##APPVERSION##/${app_version}/g" Intro.txt

echo "Copying License..."
cp ../../../LICENSE LICENSE.txt

# build installer
echo Building...
/usr/local/bin/packagesbuild $script_file

# reset version number
sed -i '' "s/${app_version}/##APPVERSION##/g" $script_file
sed -i '' "s/${app_version}/##APPVERSION##/g" Intro.txt

# clean up license file
rm LICENSE.txt

# sign the installer package
echo "Signing installer package..."
TEAM_ID=$(more ~/Developer/mac_id)
pkg_dir=CHOWTapeModel_Installer_Packaged
rm -Rf $pkg_dir
mkdir $pkg_dir
productsign -s "$TEAM_ID" ../../build/CHOWTapeModel.pkg $pkg_dir/CHOWTapeModel-signed.pkg

echo "Notarizing installer package..."
INSTALLER_PASS=$(more ~/Developer/mac_installer_pass)
npx notarize-cli --file $pkg_dir/CHOWTapeModel-signed.pkg --bundle-id com.chowdsp.CHOWTapeModel --username chowdsp@gmail.com --password "$INSTALLER_PASS" --asc-provider "$TEAM_ID"

echo "Building disk image..."
vol_name=ChowTapeModel-Mac-$app_version
hdiutil create "$vol_name.dmg" -fs HFS+ -srcfolder $pkg_dir -format UDZO -volname "$vol_name"
