#!/bin/sh
if [ -f $1 ]
    then
    echo "Projucer already built!"
else
    echo "Building Projucer..."
    cd $2
    if [ "$3" == "osx" ]
        then
        xcodebuild -project Projucer.xcodeproj > /dev/null
    elif [ "$3" == "windows" ]
        then
        msbuild.exe -v:quiet Projucer.sln
    elif [ "$3" == "linux" ]
        then
        make
    fi
fi


# if [ -f .git/.commit.txt ]