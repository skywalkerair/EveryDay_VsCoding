## VSCode+Programming+Daily

---
***在其他地方下载代码***
[参见网址](https://www.cnblogs.com/ashidamana/p/6122619.html)

~~~markdown
首先你电脑还是的有vscode 和  GIT，，然后用git把上面那些全局配置再执行一次，如下
git pull --allow-unrelated-histories

git config --global user.name "ASxx"
git config --global user.email "123456789@qq.com"  

git config --global credential.helper store    
　　然后打开Git Bash输入以下命令

cd d:/test   //指定存放的目录
git clone https://git.oschina.net/name/test.git   //你的仓库地址
~~~






***Date:20181205***

1. [安装和配置-1](https://blog.csdn.net/bat67/article/details/81268581)
2. [安装配置-2](https://blog.csdn.net/bat67/article/details/76095813#comments)
3. 安装配置成功
4. [leetcode网址](https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/34/)

***Day1:leetcode：有效数独***

​~~~(markdown)
题目说明：
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
~~~

**20181207总结：**

​~~~ markdown
1. 有效数独：
	思想上要分两块来选择：行列 和 3*3小块
2. 旋转图像：
	外循环第一圈第二圈和内循环
	for(int i=0;i<n/2;i++)
	for(int j = i;j<n-1-i;j++)
3. 整数反转：
	int res = 0;
	while(x!=0)
	{
        int t=res*10+x%10;
        if(t/10 != res) return 0;
        res = t;
        x/10;
	}
	return res;
	
4. 字符串中的第一个唯一字符
将字符串统计一遍，再统计只为1第一个只为一的
int n = s.size();
if(n == 0) return -1;
int a[26] = {0};
for(int i = 0;i<n;i++)
{
    a[s[i]-'a']++;
}
for(int i;i<n;i++)
{
    if(a[s[i]-'a']==1)
    	return i;
}
~~~



~~~markdown
Git的使用说明

Operation: 
1. git add . 
2. git commit -m "XXXXXXX" 
3. git push

当git pull 遇到问题时:

git stash

git pull

***Quick setup — if you’ve done this kind of thing before***
******************************************************
（1)…or create a new repository on the command line
 echo "# Project_xiamen" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/skywalkerair/Project_xiamen.git
git push -u origin master
（2）…or push an existing repository from the command line
 git remote add origin https://github.com/skywalkerair/Project_xiamen.git
git push -u origin master
（3）…or import code from another repository
You can initialize this repository with code from a Subversion, Mercurial, or TFS project.
~~~

<<<<<<< HEAD
***20181217:opencv遍历每个像素点的三种方法***
=======
***20181217:opencv遍历每个像素点的三种方法***

***C# 的相关知识：***

变量类型分为三种：

1. 值类型：int(32bits),bool,byte(8bits),char(16bits),

   double(64bits),float(32bits),

2. 引用类型：

   Object类型：可以被分配任何其他类型（值类型、引用类型等类型）的值，

   Object obj;

    obj = 100;//装箱；

   动态（Dynamic）类型：可以存储任何类型的值在动态数据类型变量中，

   dynamic d = 20;

   字符串类型：给变量分配任何字符串值，在字符串之前加@，则字符串可以任意换行

   String str = "hello world";

   string str2 = @"fasjklfjkla sdf 

   <

   -->

   sdfd

   ";

3. 指针类型：指针类型变量存储另一种类型的内存地址。

   type* identifier;

   char* cptr;

   int* iptr;



   **函数参数的传递：**

   值参数：复制实际值，而不改变实际参数的值(int a ,int b)

   引用参数：复制内存位置的引用给形式参数，实际参数会发生改变(ref int a ,ref int b)

   输出参数：返回多个值（out int a, out int b）

   http://www.runoob.com/csharp/csharp-windows-file-system.html
>>>>>>> 40f360994d94d2d74d2ba763a8a82c53ae5a1d94
