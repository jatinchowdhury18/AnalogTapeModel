#!/bin/bash

# install functions
install_pluginval_linux()
{
    curl -L "https://github.com/Tracktion/pluginval/releases/download/latest_release/pluginval_Linux.zip" -o pluginval.zip
    unzip pluginval > /dev/null
    echo "./pluginval"
}

install_pluginval_mac()
{
    curl -L "https://github.com/Tracktion/pluginval/releases/download/latest_release/pluginval_macOS.zip" -o pluginval.zip
    unzip pluginval > /dev/null
    echo "pluginval.app/Contents/MacOS/pluginval"
}

install_pluginval_win()
{
    powershell -Command "[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest https://github.com/Tracktion/pluginval/releases/download/latest_release/pluginval_Windows.zip -OutFile pluginval.zip"
    powershell -Command "Expand-Archive pluginval.zip -DestinationPath ."
    echo "./pluginval.exe"
}

# install
if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    pluginval=$(install_pluginval_linux)
    plugin="Plugin/build/CHOWTapeModel_artefacts/Release/VST3/CHOWTapeModel.vst3"
elif [[ "$OSTYPE" == "darwin"* ]]; then
    pluginval=$(install_pluginval_mac)
    plugin="Plugin/build/CHOWTapeModel_artefacts/VST3/CHOWTapeModel.vst3"
else
    pluginval=$(install_pluginval_win)
    plugin="Plugin/build/CHOWTapeModel_artefacts/Release/VST3/CHOWTapeModel.vst3"
fi

echo "Pluginval installed at ${pluginval}"
echo "Validating ${plugin}"

n_tries=0
result=1
until [ "$n_tries" -ge 4 ] || [ "$result" -eq 0 ]
do
   $pluginval --strictness-level 8 --timeout-ms 90000 --validate-in-process --skip-gui-tests --validate $plugin
   result=$?
   n_tries=$((n_tries+1))
done

# clean up
rm -Rf pluginval*
exit $result
