## 文件说明

C++大学教程（第九版）的学习记录

~~~Markdown
#20190218：
Day1心得：
1.**Set&&Get函数** 
在一个类中，使用set和get来访问类中的数据
class A
{
    private:
    	string a;
    public:
    	void setA(string aName)
    	{
            a = aName;
    	}
    	string getA() const
    	{
            return a;
    	}
};
2.**构造函数** 
每个类可以提供一个或者多个构造函数，用于类的初始化；
定义是必须和类名同名；
不能返回值，所以连void 都不能写，声明是public；
class GradeBook
{
private:
	string strName;
public:
	explicit GradeBook(string name):strName(name)
	{
        //null
	}  
};

3. **头文件**
using 不能放在头文件里面

#20190218：
*第四章*

1. 条件运算符（？：）
cout<<(grade >= 60 ?: "Passed":"Failed");
20190220：学到了第五章（P117）
~~~

