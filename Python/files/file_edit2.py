
import fileinput
import sys

bazelrc = sys.argv[1]+"/.bazelrccopy"

for line in fileinput.input(bazelrc, inplace=True):
    newline = line.rstrip()
    # print(newline)
    if(newline.find("build --incompatible_enable_cc_toolchain_resolution")):
        sys.stdout.write("found")
        # newline1 = newline.replace("build --incompatible_enable_cc_toolchain_resolution","#build --incompatible_enable_cc_toolchain_resolution")
        # newline1 = newline1.rstrip()
        # print(newline1)
        # newline2 = line.replace("build --action_env=BAZEL_DO_NOT_DETECT_CPP_TOOLCHAIN=1","#build --action_env=BAZEL_DO_NOT_DETECT_CPP_TOOLCHAIN=1")
        # newline2 = newline2.rstrip()
        # print(newline2)
        # newline3 = line.replace("run --action_env=BAZEL_DO_NOT_DETECT_CPP_TOOLCHAIN=0","#run --action_env=BAZEL_DO_NOT_DETECT_CPP_TOOLCHAIN=0")
        # newline3 = newline3.rstrip(
        # print(newline3)
    
    