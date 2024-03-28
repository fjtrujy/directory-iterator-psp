# std::filesystem::directory_iterator test for Playstation Portable

This is a simple test which works on both PC and PSP for testing the std::filesystem::directory_iterator class.

## Building

### PSP

This one requires upstream SDL2.

```
mkdir psp && cd psp
psp-cmake ..
make
```

### PC

```
mkdir build && cd build
cmake ..
make