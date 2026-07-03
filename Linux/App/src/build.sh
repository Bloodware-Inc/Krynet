#!/usr/bin/env bash
set -e

# Install Flathub runtimes if not initialized
flatpak install flathub org.gnome.Platform//47 org.gnome.Sdk//47 -y

# Fallback basic asset initialization
if [ ! -f krynet.png ]; then
    touch krynet.png
fi

# Multi-threaded isolated sandbox compilation
flatpak-builder --force-clean build-dir ai.krynet.Client.yml
flatpak-builder --user --install --force-clean build-dir ai.krynet.Client.yml

echo "=========================================================="
echo "Universal Client Loaded Successfully."
echo "Launch with: flatpak run ai.krynet.Client"
echo "=========================================================="
