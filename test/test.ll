; ModuleID = 'test.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [23 x i8] c"yippiekayemotherfucker\00", align 1
@.str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@c = common global i32 0, align 4

; Function Attrs: nounwind uwtable
define i32 @coiso(i32 %a) #0 {
  %1 = alloca i32, align 4
  %s = alloca i8*, align 8
  %p = alloca i8*, align 8
  store i32 %a, i32* %1, align 4
  store i8* getelementptr inbounds ([23 x i8]* @.str, i32 0, i32 0), i8** %s, align 8
  store i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8** %p, align 8
  ret i32 1
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1
  %2 = load i32* @c, align 4
  %3 = call i32 @coiso(i32 %2)
  ret i32 0
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.2 (tags/RELEASE_352/final)"}
