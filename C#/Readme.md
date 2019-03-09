## C#学习

~~~20190105
C# 拷贝数组的几种方法
复制数组的时候，一定要用new在堆中开辟一个新的空间专门用于存放数组
（1）
int[] pins = {9,3,7,2};
int[] copy = new int[pins.length];
for(int i = 0;i<copy.length;i++)
{
    copy[i] = pins[i];
}
(2)
int[] copy = new int[pins.length];
pins.CopyTo(copy,0);


~~~

