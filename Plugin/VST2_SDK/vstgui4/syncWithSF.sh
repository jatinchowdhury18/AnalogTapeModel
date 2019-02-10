#!/bin/sh
# this script syncs the vstgui folder with the trunk version of sourceforge

CHECKOUTDIR=tmp

mkdir -p $CHECKOUTDIR
cd $CHECKOUTDIR

SVNDIR=trunk/vstgui/
svn export http://svn.code.sf.net/p/vstgui/code/$SVNDIR vstgui

cd ..

src="tmp"

if [ ! "$src" ]
then
	echo need source path
	exit -1
fi

rsync -C -W -r --exclude=.DS_Store -v "$src/vstgui" .

rm -rf $CHECKOUTDIR