; ModuleID = 'test.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @coiso(i32 %a) #0 {
  %1 = alloca i32, align 4
  %b = alloca i32*, align 8
  %c = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 1, i32* %c, align 4
  %2 = load i32* %1, align 4
  %3 = sext i32 %2 to i64
  %4 = load i32** %b, align 8
  %5 = getelementptr inbounds i32* %4, i64 %3
  store i32 1, i32* %5, align 4
  %6 = load i32* %c, align 4
  %7 = load i32** %b, align 8
  %8 = getelementptr inbounds i32* %7, i64 0
  store i32 %6, i32* %8, align 4
  %9 = load i32** %b, align 8
  %10 = load i32* %9, align 4
  store i32 %10, i32* %c, align 4
  ret i32 1
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
