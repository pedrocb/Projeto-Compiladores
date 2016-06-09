; ModuleID = 'test.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [6 x i8] c"\7F \7F \FF\00", align 1
@.str1 = private unnamed_addr constant [12 x i8] c"mais_cenas\0A\00", align 1
@.str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@.str3 = private unnamed_addr constant [3 x i8] c"yo\00", align 1
@a = common global i32 0, align 4
@b = common global i32* null, align 8
@vv = common global i32** null, align 8
@c = common global [2 x i32] zeroinitializer, align 4
@kk = common global [2 x i32*] zeroinitializer, align 16
@d = common global i8 0, align 1
@e = common global i8* null, align 8
@f = common global [4 x i8] zeroinitializer, align 1
@g = common global i8* null, align 8

; Function Attrs: nounwind uwtable
define i8* @cenas(i32 %a, i8 signext %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8, align 1
  %s = alloca i8*, align 8
  %s2 = alloca i8*, align 8
  %s3 = alloca i8*, align 8
  store i32 %a, i32* %1, align 4
  store i8 %b, i8* %2, align 1
  store i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i8** %s, align 8
  store i8* getelementptr inbounds ([12 x i8]* @.str1, i32 0, i32 0), i8** %s2, align 8
  store i8* getelementptr inbounds ([1 x i8]* @.str2, i32 0, i32 0), i8** %s3, align 8
  ret i8* getelementptr inbounds ([3 x i8]* @.str3, i32 0, i32 0)
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 0, i32* %1
  store i32 3, i32* %a, align 4
  %2 = load i32* %a, align 4
  %3 = add nsw i32 %2, 1
  store i32 %3, i32* %a, align 4
  ret i32 0
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.5.2 (tags/RELEASE_352/final)"}
