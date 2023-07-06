

/*
    *BFString Simple Demo

        *Zhanmin Su  
  
            *2023.07.06 21:54


*/

#include <iostream>
#include <string>
using namespace std;



//bf算法
int searchOfBF(char *str,char *strmodel){
    //定义下标量
    int i = 0,j = 0;
    //遍历整个主串
    while (i <strlen(str)&&j<strlen(strmodel))
    {
        //相同前进下标匹配下个字符
       if ( strmodel[j]==str[i]) {++i; ++j;}

        //重置主串位置 i为现在所处步数 j为所走步数 +1 前往下一个主串字符
       else i= i - j + 1; j = 0;

       
    }
        //范围内
    if (j >= strlen(strmodel)) return i- strlen(strmodel);
    else return -1;
}

/*
    KMP
    此算法需要通过分析子串元素寻找相同规律与关系才可得到
    若第n位字符无法匹配但n前字符全部匹配，下一次匹配从n+1次开始
    子串j位与k位字符相同，可找寻规律下次从主串匹配从m+j成为m+k
    实际需要具体分析
    此处因为使用频度不大且拥有更好的算法略过编写

*/
int main(){
    char str[] = "abcdefghigklmnopqrstuvwxyz";
  
    char strm[] ="";
    

    cout << "输入二十六个字母中的一个或者按顺序输入n个: " << endl;
    cin >> strm;
    char *m = strm;
    cout << strm;
    
    int a = searchOfBF(str,m);
    //条件表达式判定是否寻找到字符或者溢出
    cout << ((a==-1) ? "没找到或出错" : "下标位置是" ) << a<< endl;

 

return 0;
}