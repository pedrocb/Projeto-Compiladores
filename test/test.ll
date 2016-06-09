; ModuleID = 'test.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @cenas(i32 %a, i32 %c) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %c, i32* %2, align 4
  store i32 2, i32* %1, align 4
  %3 = load i32* %b, align 4
  ret i32 %3
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1
  ret i32 0
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.2 (tags/RELEASE_352/final)"}
