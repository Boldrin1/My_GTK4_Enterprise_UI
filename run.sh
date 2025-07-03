#!/bin/bash
echo "Compilando..."
meson compile -C build

echo "Executando..."
./build/My_GTK4_Enterprise_UI.exe

