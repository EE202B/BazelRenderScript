filegroup(
    name = "jni_srcs",
    srcs = glob(["*.cpp", "*.h"]),
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "libhellocomputendk_jni.so",
    srcs = [
        "//hellocomputendk/hellocomputendk_jni:jni_srcs",
    ],
    deps = [
        "//hellocomputendk:rs_prebuilt"
    ],
    copts = [
            "-std=c++11",
            "-O2",
    ],
    linkopts = [
        "-landroid",
        "-ljnigraphics",
        "-llog",
        "-lm",
        "-z defs",
        "-s",
    ],
    linkshared = 1,
    linkstatic = 1,
)
