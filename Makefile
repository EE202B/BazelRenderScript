build: ; ndk-build -B NDK_PROJECT_PATH=./hellocomputendk APP_ABI=$(arch); bazel build -c opt //hellocomputendk/hellocomputendk_jni:libhellocomputendk_jni.so --crosstool_top=//external:android/crosstool --cpu=$(arch) --host_crosstool_top=@bazel_tools//tools/cpp:toolchain ; mkdir ./bin ; mkdir ./bin/$(arch) ; cp ./bazel-bin/hellocomputendk/hellocomputendk_jni/*.so ./bin/$(arch) ; cp -r ./hellocomputendk/obj/local/$(arch)/*.so ./bin/$(arch)

clean: ; rm -rf ./hellocomputendk/obj ; rm -rf ./hellocomputendk/libs ; bazel clean ; rm -rf ./bin
