
#include <iostream>
/*
    *SqStack Simple Demo

        *Zhanmin Su  
  
            *2023.07.06 05:47


*/
using namespace std;
#define OK  1
#define ERROR  -1
typedef int SqItem;

//c++可以定义函数 c不可以
typedef struct SqStack
{
    SqItem *base;//栈底，指向上一个而不是本身
    SqItem *top;//栈顶
    //大小 -1即为实际个数 最大可用元素
    int stacksize;

    //进化 结构体函数
    void init() {
    base = new SqItem; //空栈
    if(!base) exit(-1);//判空
    top = base; //空栈栈顶即为栈底
    stacksize = 100; //自由定义大小
    }

    //判空函数
    int isEmpty(){
        if(top == base) return OK;
        else return 0;
    }

    //数量函数
    int length() {return top - base;}

    //清表
    int clear() {if (base) top = base;return OK;}
    //销毁 是否存在后 将最大个数设为0 栈底栈顶设无
    int destroy(){if (base) delete base; stacksize = 0; base = top = NULL; return OK;}

    //push函数 overflow -先赋值后++指向下一个空间
    int push(SqItem i){ if(top-base==stacksize) exit(ERROR); else *top++ = i ;return OK;}
    //push函数 underflow先--指向上一个空间后赋值
    int pop(SqItem &i){ if(top == base) exit(ERROR); else i =*--top;  ;return OK;}
}SqStack;


int main(){
    SqStack *sq = new SqStack;
    SqItem item = 0;
    //初始化
    sq->init();
    item++; //数据加1
    sq->push(item); //入栈
    cout << sq -> length(); //数据size
    item++; //数据加1
    sq->push(item); //入栈
    cout << sq -> length(); //数据size
    sq -> pop (item); //出栈
    cout << item; //测试删除元素是否赋值
    sq -> destroy(); //释放
    

}