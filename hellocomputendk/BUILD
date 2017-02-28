package(
    default_visibility = [
        "//visibility:public",
    ],
)

filegroup(
    name = "rs_prebuilt_so",
    srcs = glob(["obj/**/*.so"]),
)

filegroup(
    name = "rs_prebuilt_hdrs",
    srcs = glob(["jni/*.h"]),
)

cc_library(
    name = "rs_prebuilt",
    srcs = [
        ":rs_prebuilt_so",
    ],
    hdrs = [
        ":rs_prebuilt_hdrs"
    ],
)