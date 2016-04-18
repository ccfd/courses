#!/bin/bash

if test -z "$TRAVIS_BRANCH" 
then
	TRAVIS_BRANCH=master
	echo I\'m not on travis-ci
fi

set -e
if test "$TRAVIS_BRANCH" == "master"
then
	if test -z "$GH_TOKEN"
	then
		echo I don\'t have the GH token!
		exit -1
	fi
	echo Deploying to GitHub Pages ...
	name=$(git --no-pager show -s --format="%aN")
	email=$(git --no-pager show -s --format="%ae")
	git --no-pager show -s --format="%s" >.msg
	echo Today\'s commit belongs to "$name" \("$email"\)
	echo Commit message:
	if ! test -f .msg
	then
		echo No commit message file
		exit -1
	fi
	cat .msg
	echo Cloning pages
	git clone --depth 1 --branch pages-base https://$GH_TOKEN@github.com/ccfd/courses.git deploy
	mv _site/* deploy/
	pushd deploy
        git config user.email "$email"
	git config user.name "$name"
#	git branch -f gh-pages pages-base
#	git checkout gh-pages
	git add -A
	git commit -F ../.msg
	git branch -f gh-pages pages-base
	git checkout gh-pages
#       Add pdf's here.
	git push --force --set-upstream origin gh-pages
	popd
	rm -fr deploy
else
	echo Not in master branch. I won\'t upload to GitHub Pages
fi

