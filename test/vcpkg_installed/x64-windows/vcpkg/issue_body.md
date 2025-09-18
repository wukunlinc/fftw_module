Package: meekrosoft-fff:x64-windows@1.1

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.44.35215.0
-    vcpkg-tool version: 2025-07-21-d4b65a2b83ae6c3526acd1c6f3b51aff2a884533
    vcpkg-scripts version: 7a4d6afa0e 2025-09-03 (21 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
Downloading https://github.com/meekrosoft/fff/archive/v1.1.tar.gz -> meekrosoft-fff-v1.1.tar.gz
meekrosoft-fff-v1.1.tar.gz.11404.part: error: download from https://github.com/meekrosoft/fff/archive/v1.1.tar.gz had an unexpected hash
note: Expected: 92890152f37e9e8b3961be2b8d2633f374ce1a16f4d78d8c6ea070a5ca35c08a75b71227465133b6ffd5bfb481246a73df4109f8b141fa83c7e22b0d31e6f903
note: Actual  : 46074860625d865927cb2d1c96675d17ac00321ceb6a45c9a4a6bcd1487a6e1f110c5d31483f6407b68245d0cca8e97ac81aded966001301e081b72355b368ac
CMake Error at scripts/cmake/vcpkg_download_distfile.cmake:136 (message):
  Download failed, halting portfile.
Call Stack (most recent call first):
  scripts/cmake/vcpkg_from_github.cmake:120 (vcpkg_download_distfile)
  C:/Users/Kun-Lin Wu/AppData/Local/vcpkg/registries/git-trees/88a408fad99dd895f057f15cca5557613274cd34/portfile.cmake:3 (vcpkg_from_github)
  scripts/ports.cmake:206 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "fftw3",
    "gtest",
    "meekrosoft-fff"
  ]
}

```
</details>
