#!/usr/bin/env python3
import os
import sys
argv = sys.argv

CC = "gcc"
CFLAGS = "-Wall -Wextra -pedantic -std=gnu17 -ggdb -Iinclude"
LDFLAGS = "-lm -lgmp"

SRC_DIR = "src"
SRC_0_100 = f"{SRC_DIR}/0-100"
SRC_0_20 = f"{SRC_0_100}/0-20"

BUILD_DIR = "build"
BUILD_DIR_0_100 = f"{BUILD_DIR}/0-100"
BUILD_DIR_0_20 = f"{BUILD_DIR_0_100}/0-20"

if len(sys.argv) < 1:
    print("[ERROR]: missing argument: problem #")
    exit(1)

problemNo = int(argv[1])
if problemNo <= 0:
    print("[ERROR]: invalid argument: problem # below or equal to 0")
    exit(1)

SRC = ""
OUTPUT_PATH = ""
EXEC = ""

if problemNo <= 20:
    SRC = f"{SRC_0_20}/{problemNo}.c"
    if not os.path.exists(SRC):
        CC = "g++"
        SRC = f"{SRC_0_20}/{problemNo}.cpp"
        CFLAGS = CFLAGS.replace("-std=gnu17", "-std=c++11")
    OUTPUT_PATH = BUILD_DIR_0_20
    EXEC = f"{OUTPUT_PATH}/{problemNo}"


def run(cmd: str) -> int:
    print(cmd)
    return os.system(cmd)


cmds = [
    f"mkdir -p {OUTPUT_PATH}",
    f"{CC} {CFLAGS} {SRC} -o {EXEC} {LDFLAGS}",
    f"./{EXEC} {str.join(' ', argv[2:])}"
]

for cmd in cmds:
    if run(cmd) != 0:
        break
