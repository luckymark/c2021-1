9.13

### 1、

空格派，

tab派，四个空格或六个空格

二者取其一，不要混着用
### 2、
字面量，字面定义的，（匿名常数）
不好，magic number，小程序可以，建议要单独设一个常量or变量
`# define MAX_CH 100`
`//可以知道一行最大的字符数，之后改程序的时候改这里即可`
	

### 3、文字
windous和github用的汉字编码不一样
UTF-8通用编码，哪里都可，在ide中改

### 4、git的用法
dvcs(version contrall system)分布式版本控制系统
1. .git用于存储很多个版本，每次提交成为commit，是 整个目录的快照   
2. 服务器上有副本，每个副本都可独立工作，repository(独立完整)
3. 提交commit，进入本地的.git
4. push传到服务器上，pull(只拉下更新的部分)就是拉下来，(clone是第一次pull)
