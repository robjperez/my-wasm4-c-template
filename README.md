# Basic WASM-4 template using C and clang

This is a very basic skeleton of c and Makefile used to compile a basic game to [wasm-4 fantasy console](https://wasm4.org)

It using only llvm clang instead of requiring wasi-sdk as the default template is using.

Please note that, due to the wasm-4 carts limitations (64Kb) we are stripping out all of the c libraries, so this is baremetal-like wasm code.

## Requirements

You will need to install wasm-4 itself
```
npm install -g wasm4
```

In macOS you will need to install llvm, since the system clang does not have support for wasm binaries

```
brew install llvm wabt lld
```

Change the path of llvm in the top of the `Makefile` if needed

## Running

```
make run
```

-or-

```
make
w4 watch build/cart.wasm
```
