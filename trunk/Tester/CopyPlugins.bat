@echo off
set BUILDCONFIG=debug
copy ..\Plugins\ExamplePlugin\%BUILDCONFIG%\ExamplePlugin.dll .\%BUILDCONFIG%\plugins\

