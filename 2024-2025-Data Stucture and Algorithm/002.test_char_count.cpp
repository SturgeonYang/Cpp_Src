// 2 假设任意输入一个不限长度的字符串，比如“This is a problem which can be solved by data structure method.”如何统计其中每一个字符的出现次数？函数名自拟
//            空格: 12    T   : 1	 a   : 4 …
//关联：HDOJ 2071.cpp 单词数

//memset函数

void stat(char* s, int num[])
{
      memset(num,0,128*4) ;
      while  (*s!=‘\0’)	 
      {
             num[*s]++; 
             s++;
      }
}


