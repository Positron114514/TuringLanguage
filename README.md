# TuringLanguage

> by Positron114514

**图灵语言** 

一个用图灵机实现的编程语言

*WIP*

项目使用 C++17 构建



## 语法

### 语句

语句由以下部分组成:

- `CurrentStatment` : 当前状态
- `CurrentNumber`: 当前数字 (0/1)
- `Operation`: 对应操作 (0/1/l/r)
- `NextStatement`: 下一个状态 

如下: 

```turing
CurrentStatement CurrentNumber Operation Nextstatement
```

> 建议每条语句占据一行

程序从 `start` 开始运行, 在状态转移为 `halt` 时停止运行. 



### 文件

图灵语言文件以 `.tl` 结尾

每个文件包含以下两个部分: 

- 文件头: 包含初始时图灵机的内存状态, 为一串 0/1
- 语句: 符合上述语句规则的语句, 其中必须包含停机状态 (start) 和起始状态 (halt). 



文件示例如下: 

```tl
1
# calculate f(x) = x + 1. result will be saved in reversed way.
start 0 1 halt # end with 0. simply +1
start 1 0 movr
movr 0 r movFinished
movFinished 1 0 movr
movFinished 0 1 halt
```

