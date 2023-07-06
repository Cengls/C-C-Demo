

/*
    *BFString Simple Demo

        *Zhanmin Su

            *2023.07.06 21:54 

                Exit- 2023.07.07 01:22  


*/

#include <iostream>
#include <string>
using namespace std;

/*
    BF
      串是有序集合
      此算法通过暴力遍历方法求子串为主串的子集
      通过减去行走步数+1来行走步数；
      


*/
int searchOfBF(char *str, char *strmodel)
{
    // 定义下标量
    int i = 0, j = 0;
    // 遍历整个主串
    while (i < strlen(str) && j < strlen(strmodel))
    {
        // 相同前进下标匹配下个字符
        if (strmodel[j] == str[i])
        {
            ++i;
            ++j;
        }

        // 重置主串位置 i为现在所处步数 j为所走步数 +1 前往下一个主串字符
        else
            i = i - j + 1;
        j = 0;
    }
    // 范围内
    if (j >= strlen(strmodel))
        return i - strlen(strmodel);
    else
        return -1;
}

/*
    KMP

      此算法需要通过分析子串元素寻找相同规律与关系才可得到
      建立一个子串自映射公用缀长度表，然后每次回溯特定公用缀到公用缀到位置，省去一个个暴力遍历；
      


*/

//next数组的建立
void buildNext(char *strmodel, int next[])
{
    /*
        回头望月 下标0的数组为头 0


    */
    next[0] = 0;

    //prelen为公用后缀长度 
    int i = 1, prelen = 0;
    
    while (i < strlen(strmodel))
    {
        //相同则写入字典 将i位位置写入公用缀长度 前进步数
        if (strmodel[prelen] == strmodel[i])
        {
            next[i] = ++prelen;
            
            i++;
        }
        //没有相同长度则为0 前进步数
        else if (!prelen)
        {
            next[i] = 0;
           
            i++;
        }
        
        //没有相同长度查询next 的-1公用缀
        else
            prelen = next[prelen - 1];
    }
}


//kmp主题
int searchOfKMP(char *str, char *strmodel)
{
    // 定义下标量
    int i = 0, j = 0;

    // 定义next数组用于记录 引用返回next
    int next[strlen(str)];
    buildNext(str, next);
    // 遍历整个主串
    while (i < strlen(str) && j < strlen(strmodel))
    {
        // 相同前进下标匹配下个字符
        if (strmodel[j] == str[i])
        {
            ++i;
            ++j;
        }
        //移动指定nexti-1下距离 -1是因为不匹配
        else if (j > 0)
        {
            j = next[j - 1];
        }
        //如果实在没有前进一位
        else
            i++;
    }
    // 范围内返回有效值
    if (j >= strlen(strmodel))
        return i - j;
    else
        return -1;
}
void bf()
{
    char str[] = "abcdefghigklmnopqrstuvwxyz";
    char strm[] = "";

    cout << "输入二十六个字母中的一个或者按顺序输入n个: " << endl;
    cin >> strm;
    char *m = strm;
    cout << strm;

    int a = searchOfBF(str, m);
    // 条件表达式判定是否寻找到字符或者溢出
    cout << ((a == -1) ? "没找到或出错" : "下标位置是") << a << endl;
}
void kmp()
{
    char strm[] = "";
    char str[] = "abcabaabc";

    cout << "输入你想要匹配的的字符串: " << endl;
    cin >> strm;
    char *m = strm;
    cout << strm;

    int a = searchOfKMP(str, m);
    // 条件表达式判定是否寻找到字符或者溢出
    cout << ((a == -1) ? "没找到或出错" : "下标位置是") << a << endl;
}

int main()
{
    bf();
    kmp();
    return 0;
}