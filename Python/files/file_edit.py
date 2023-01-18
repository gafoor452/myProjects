
import sys
def lines_that_equal(line_to_match, fp):
    return [line for line in fp if line == line_to_match]

bazelrc = sys.argv[1]+"/.bazelrc"
with open(bazelrc, "r+") as fp:
    for line in fp.readlines():
        line = line.rstrip()
        if line == "build --incompatible_enable_cc_toolchain_resolution":
            ref=line.replace("build --incompatible_enable_cc_toolchain_resolution","#build --incompatible_enable_cc_toolchain_resolution")
            print(ref)
fp.close()    
    # lines_that_equal("build --incompatible_enable_cc_toolchain_resolution", fp):
    #     print(line)