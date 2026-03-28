# Makefile
CC = /opt/homebrew/opt/llvm/bin/clang
WASM_LD = /opt/homebrew/Cellar/lld/22.1.1/bin/wasm-ld

CFLAGS = \
    --target=wasm32-unknown-unknown \
    -nostdlib \
    -ffreestanding \
    -Oz \
    -flto

LDFLAGS = \
    -fuse-ld=$(WASM_LD) \
    -Wl,--no-entry \
    -Wl,--import-memory \
    -Wl,--stack-first \
    -Wl,-z,stack-size=2048 \
    -Wl,--initial-memory=65536 \
    -Wl,--global-base=6560 \
    -Wl,--export=start \
    -Wl,--export=update \
    -Wl,-z,stack-size=4096 \
    -Wl,--strip-all \
    -Wl,--gc-sections

all: build/cart.wasm

build/cart.wasm: src/main.c src/math.c
	$(CC) $(CFLAGS) $(LDFLAGS) src/main.c src/math.c -o $@
	@echo "✅ Built: $@"
	@ls -lh $@

run: build/cart.wasm
	w4 run build/cart.wasm

clean:
	rm -f build/cart.wasm

.PHONY: all run clean
