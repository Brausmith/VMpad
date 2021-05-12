﻿#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.


+^!A::  run, ms-settings:privacy-microphone
+^!V::  run, ms-settings:privacy-webcam
+^!D::  run, ms-settings:display
+^!M::  run, ms-settings:mousetouchpad

+^!W::  Winset, Alwaysontop, , A