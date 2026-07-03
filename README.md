<div align="center">

# 🇮🇸 Krynet Source Repository - Source Branch

**Official Source Code for Client Platforms • Based in Iceland**  
*Build client targets from source • Full transparency • GPL-3.0 Licensed Frontends*

<p>
<img src="https://img.shields.io/badge/License-GPL%203.0-green" alt="GPL-3.0">
<img src="https://img.shields.io/badge/Platforms-Supported-brightgreen" alt="Platforms">
<img src="https://img.shields.io/badge/Sciter.JS-Powered-orange" alt="Sciter">
<img src="https://img.shields.io/badge/Status-Active-brightgreen" alt="Active">
</p>

</div>

---

## 📋 Platform Status

| Platform | Build Status | Precompiled / Support | Packaging / Format |
|----------|--------------|-----------------------|--------------------|
| **Linux** | 🔨 **Official Source** | ✅ **Available** (Official) | **Universal Flatpak Sandbox** (`.flatpak`) |
| **Android** | 🔨 **Official Source** | ✅ **Available** (Official) | Application Package (`.apk`) |
| **Windows** | 👥 Community Maintained | ❌ Unofficial Base | Native Executable (`.exe`) |
| **macOS** | 👥 Community Maintained | ❌ Unofficial Base | Disk Image (`.dmg`) |
| **iOS** | 👥 Community Maintained | ❌ Unofficial Base | App Bundle (`.ipa`) |

> ⚠️ **Notice:** Windows, macOS, and iOS clients are unofficial, community-maintained ports. Their source branches and active tracking can be found at [github.com/Krynet-Community](https://github.com/Krynet-Community).

---

## 🚨 **Required External SDKs** *(Not Included)*

**⚠️ Sciter SDK NOT bundled** (always latest version):

| SDK | Download | Usage |
|-----|----------|-------|
| **Sciter.JS** | [sciter.com](https://sciter.com/) | **All platforms** |

**Setup Native SDK Directories:**
```bash
# Official Android Build Target Setup
cd Source/Android
mkdir -p app/sciter/include
# Extract libsciter-android.a directly into app/sciter/
# Place headers in app/sciter/include/

# Linux Build Target Setup
cd Source/Linux
mkdir -p sciter/include

```

---

## 🚀 Quick Start - Official Targets

```bash
# Clone the official Source branch
git clone -b Source [https://github.com/Krynet-LLC/Krynet.git](https://github.com/Krynet-LLC/Krynet.git)
cd Krynet

# Official platform compilation steps
cd Source/Linux   && ./build.sh                    # Linux Universal Flatpak
cd Source/Android && ./gradlew assembleRelease    # Android (Optimized production build)

```

---

## 🏗️ Platform-Specific Builds

### 🤖 **Android (Official)**

Ensure your production environment is configured correctly. The CMake layer expects `libsciter-android.a` inside `app/sciter/` before you start building.

```bash
cd Source/Android
./gradlew assembleRelease
# → Target output location: app/build/outputs/apk/release/

```

### 🐧 **Linux (Official Universal Flatpak)**

The Linux client builds inside an isolated environment mapping target GTK3 runtimes and forcing total sandbox constraints.

#### Prerequisites

```bash
# Ubuntu/Debian/Tails/Whonix
sudo apt update && sudo apt install flatpak flatpak-builder -y

# Arch Linux
sudo pacman -S flatpak flatpak-builder --noconfirm

# Configure Flathub Environment Dependencies
flatpak remote-add --if-not-exists flathub [https://dl.flathub.org/repo/flathub.flatpakrepo](https://dl.flathub.org/repo/flathub.flatpakrepo)
flatpak install flathub org.gnome.Platform//47 org.gnome.Sdk//47 -y

```

#### Compile and Bundle

Ensure the Sciter headers exist at `Source/Linux/sciter/include/` and the native runtime engine engine exists at `Source/Linux/sciter/bin.linux/x64/libsciter.so`.

```bash
cd Source/Linux

# Option A: Compile and install straight to local system
flatpak-builder --user --install --force-clean build-dir ai.krynet.Client.yml

# Option B: Compile and extract standalone distribution package (.flatpak)
flatpak-builder --force-clean --repo=repo build-dir ai.krynet.Client.yml
flatpak build-bundle repo krynet-client.flatpak ai.krynet.Client

```

---

### 👥 **Community Subprojects (Windows / macOS / iOS)**

To compile, patch, or review development for desktop platforms or Apple mobile ecosystems, use the community trees:

```bash
# For Windows, macOS, and iOS development resources:
git clone [https://github.com/Krynet-Community/Krynet-Desktop-Mobile.git](https://github.com/Krynet-Community/Krynet-Desktop-Mobile.git)

```

---

## 📜 GPL-3.0 Licensing

✅ Modify - Distribute - Commercial OK for Frontend/UI modifications.

✅ Network use changes must be made publicly available under open-source standards.

❌ Core infrastructure and backend systems remain proprietary to Krynet, LLC.

---

**🇮🇸 Krynet Source Branch © 2026** *Icelandic-engineered privacy platform.*

GPL-3.0 • [sciter.com](https://sciter.com/) SDK required • [Official Repository](https://github.com/Krynet-LLC/Krynet/tree/Source)

```

```
