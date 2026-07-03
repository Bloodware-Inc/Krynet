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
