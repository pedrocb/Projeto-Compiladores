@c = common global i32 0

define i32 @coiso(i32 %a) {
  %1 = alloca i32
  %b = alloca i32
  store i32 %a, i32* %1
  store i32 2, i32* %b
  %2 = load i32* %b
  %3 = sub nsw i32 0, %2
  store i32 %3, i32* %1
  %4 = load i32* %1
  %5 = call i32 @coiso(i32 %4)
  ret i32 1
}

define i32 @main() {
  %1 = alloca i32
  store i32 0, i32* %1
  %2 = load i32* @c
  %3 = call i32 @coiso(i32 %2)
  ret i32 0
}
