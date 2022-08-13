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
