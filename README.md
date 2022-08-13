# quark

Quark is a low-level programming language which aims to be fast, modern but still providing the flexibility of older low-level languages.

## Example

```quark
@include("stdio.qk")

fn main() -> i32 {
    let msg: u8& = "Hello world!";
    for _ in 0..10 {
        println(msg);
    }
    
    ret 0;
}
```

## Building

To build quark use the following commands:

```
mkdir build && cd build
../configure
make
```

if you also want to install quark on your machine you can use `make install` with root access (using sudo for example)

## Copying

See [COPYING](COPYING)
