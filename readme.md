# easykit

**目的：**使linux命令行操作更加方便

**用法：**

`trs`: 将数据行列转置

```shell
# 示例1：
trs test/student_record.txt
# 示例2：
cut -f1,2,3 test/student_record.txt | trs
```

`csum`: 将某列数字求和

```shell
# 示例1：将学生年龄求和
csum -c 2 test/student_record.txt
# 示例2：跳过前两名，求其余学生英语总分
csum -c 4 -k 3 test/student_record.txt
# 示例3：求后三名同学语文总分
tail -2 test/student_record.txt | csum -c 3
```





