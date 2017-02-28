# BazelRenderScript

Build RenderScript with Bazel and ndk-build

### Notice:
You must update the NDK to r14-beta2 or higher to enable build RenderScript with ndk-build. The main issue with bazel is that it's toolchain is still build with NDK r12 while the RenderScript API recently has been added back to NDK since r14-beta2.

### Usage:
   - `make arch=$(target_arch)` 
      * target_arch=[x86, armeabi-v7a, etc.]
   - `make clean`
   - All the built binaries are located at the bin folder. Copy the architecture folder to your `Android project/app/libs`. 
   - Add this line in gradle to link the library: `sourceSets.main.jniLibs.srcDirs = ['./libs']` 
   - Then you should be able to use `System.loadLibrary("hellocomputendk_jni");` in Java to call native APIs.
