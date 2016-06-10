; ModuleID = 'test.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@global = common global i32 0, align 4

; Function Attrs: nounwind uwtable
define void @ole(i8* %a) #0 {
  %1 = alloca i8*, align 8
  store i8* %a, i8** %1, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @main(i32 %a, i8** %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8**, align 8
  %d = alloca i32, align 4
  store i32 0, i32* %1
  store i32 %a, i32* %2, align 4
  store i8** %b, i8*** %3, align 8
  %4 = load i32* @global, align 4
  store i32 %4, i32* %2, align 4
  %5 = load i32* %2, align 4
  store i32 %5, i32* %d, align 4
  ret i32 1
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.2 (tags/RELEASE_352/final)"}
