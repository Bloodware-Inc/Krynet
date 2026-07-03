<div align="center">

# 🛠️ Krynet Source Repository - Source Branch

**Official Source Code for All Platforms** *Build any platform from source • Full transparency • AGPL-3.0 Licensed*

<p>
<img src="https://img.shields.io/badge/License-AGPL%203.0-red" alt="AGPL-3.0">
<img src="https://img.shields.io/badge/All%20Platforms-Buildable-brightgreen" alt="All Buildable">
<img src="https://img.shields.io/badge/Sciter.JS-Powered-orange" alt="Sciter">
<img src="https://img.shields.io/badge/Status-Active-brightgreen" alt="Active">
</p>

</div>

---

## 📋 Platform Status

| Platform | Build Status | Precompiled | Packaging / Format |
|----------|--------------|-------------|--------------------|
| **Windows** | 🔨 **Source Available** (MinGW64) | ❌ **Unavailable** | Native Executable (`.exe`) |
| **macOS** | 🔨 **Source Available** (Xcode/CMake) | ❌ **Unavailable** | Disk Image (`.dmg`) |
| **iOS** | 🔨 **Source Available** (Xcode) | ❌ **Unavailable** | App Bundle (`.ipa`) |
| **Linux** | 🔨 **Source Available** (+ Precompiled) | ✅ **Available** | **Universal Flatpak Sandbox** (`.flatpak`) |
| **Android** | 🔨 **Source Available** (+ Precompiled) | ✅ **Available** | Application Package (`.apk`) |

**Linux & Android: Precompiled binaries ready. Others: Build from source only.**

---

## 🚨 **Required External SDKs** *(Not Included)*

**⚠️ Sciter SDK NOT bundled** (always latest version):

| SDK | Download | Usage |
|-----|----------|-------|
| **Sciter.JS** | [sciter.com](https://sciter.com/) | **All platforms** |
| **Ultralight** | [ultralig.ht](https://ultralig.ht/) | **Alternative renderer** |

**Setup:**
```bash
cd Source/Windows    # or Linux, Android, etc.
mkdir -p thirdparty/sciter
# Download Sciter SDK → extract here

```

---

## 🚀 Quick Start - Build From Source Branch

```bash
# Clone Source branch
git clone -b Source [https://github.com/JamesHickers/Krynet.git](https://github.com/JamesHickers/Krynet.git)
cd Krynet

# Platform builds
cd Source/Windows && make release                 # Windows (source only)
cd Source/Linux   && ./build.sh                   # Linux Universal Flatpak (precompiled available)
cd Source/Android && ./gradlew assembleRelease    # Android (precompiled available)

```

---

## 🏗️ Platform-Specific Builds

### 🪟 **Windows**

```bash
cd Source/Windows
mkdir -p /sciter && # Add Sciter SDK
make clean && make release
# → Krynet.exe

```

### 🐧 **Linux (Universal Flatpak)**

The Linux client builds inside an isolated, cross-distro environment mapping GTK3 runtimes and forcing total sandbox constraints.

#### Prerequisites

```bash
# Ubuntu/Debian/Tails/Whonix/Kodachi
sudo apt update && sudo apt install flatpak flatpak-builder -y

# Arch Linux
sudo pacman -S flatpak flatpak-builder --noconfirm

# Configure Flathub Remote & Environment Dependencies
flatpak remote-add --if-not-exists flathub [https://dl.flathub.org/repo/flathub.flatpakrepo](https://dl.flathub.org/repo/flathub.flatpakrepo)
flatpak install flathub org.gnome.Platform//47 org.gnome.Sdk//47 -y

```

#### Compile and Bundle

Ensure the Sciter headers exist at `Source/Linux/sciter/include/` and the native runtime engine exists at `Source/Linux/sciter/bin.linux/x64/libsciter.so`.

```bash
cd Source/Linux

# Option A: Compile and install straight to local system
flatpak-builder --user --install --force-clean build-dir ai.krynet.Client.yml

# Option B: Compile and extract standalone distribution package (.flatpak)
flatpak-builder --force-clean --repo=repo build-dir ai.krynet.Client.yml
flatpak build-bundle repo krynet-client.flatpak ai.krynet.Client

```

*Run locally with:* `flatpak run ai.krynet.Client`

*Install standalone bundle on another machine with:* `flatpak install --user krynet-client.flatpak`

### 🤖 **Android**

```bash
cd Source/Android
./gradlew assembleRelease
# → krynet.apk (precompiled also available)

```

### 📱 **iOS**

```bash
cd Source/iOS
# 1. Add Sciter.Lite SDK to /sciter/
# 2. Drag libSciterLit.a → Xcode project
open Krynet.xcodeproj

# In Xcode:
# → Select "Krynet" target
# → Signing & Capabilities → Add your Apple ID
# → Product → Archive
# → Distribute App → Ad Hoc / Development → Export IPA
# → krynet.ipa ✅

```

---

### 🍎 **macOS**

```bash
cd Source/macOS
mkdir build && cd build
# 1. Add Sciter.JS SDK to /sciter/

# CMake build
cmake .. -DSCITER_PATH=/sciter -DCMAKE_BUILD_TYPE=Release
make -j8
open ../Krynet.dmg
# → Krynet.app inside DMG ✅

```
---

## 📜 AGPL-3.0 License

✅ Modify - Distribute - Commercial OK

✅ Network use → Share source

❌ No proprietary forks

---

**🔒 Krynet Source Branch © 2030** *Linux/Android precompiled. Windows/macOS/iOS: Build from source.*

AGPL-3.0 • [sciter.com](https://sciter.com/) SDK required • [Krynet](https://github.com/Krynet-LLC/Krynet/tree/Source)
