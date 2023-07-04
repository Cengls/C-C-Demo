#include <iostream>
/*
    *LinearList Simple Demo

        *Zhanmin Su  
  
            *2023.07.05 00:49


*/

using namespace std;

#define LIST_INIT_SIZE 100; 

typedef struct{
    char name[8];
    
}ListItem;

typedef struct 
{
    //定义指针以为动态分配地址
   ListItem* ListItem;
   int length;

}List;



//建表
int createList(List &L){

   L.ListItem = new ListItem; //分配空间
   if(!L.ListItem) cout<< "Error:"   ;
   L.length = 0; //空表
    return 1;
}


//插入元素
int insertList(ListItem Item, List &L , int index){
    //判断是否定义范围内
    if(L.length-1<index&&L.length>1) { return -1; cout << "错误" ;}
    else {
     

        //数组向后整体移位
       for (int i = index; i <= L.length; i++)
       {
            L.ListItem[i+1] = L.ListItem[i];

       }
       L.ListItem[index] = Item;
       L.length ++;

       return 0;

    }


}
//删除元素
int deleteList( List &L , int index){
    //判断是否定义范围内
    if(L.length-1<index&&L.length>0) { return -1; cout << "错误" ;}
    else {
        //建立一个新表存放
        List p  = L;
        //数组向前整体移位
       for (int i = index; i <= L.length; i++)
       {
           
            L.ListItem[i-1] = p.ListItem[i];

       }
       //进行替换
       p.length--;
       L = p;
      

       return 0;

    }


}

//获取表内指定索引元素
int getListItem(List &L, ListItem &item, int index){
    if(L.length-1<index&&L.length>0) { return -1; cout << "错误超出所指范围或此表为空" ;}
    else{
        item = L.ListItem[index];
        return 0;
    }




}






int main(){
    //动态存储分配
    List list ;
    ListItem listitem = { "abc"};
    //初始化
    createList(list );
    //插入元素
    cout<< insertList(listitem,list,0);
    //输出长度
    cout<< list.length;
    //输出名称
    cout<< list.ListItem[0].name;
    //删除元素
    deleteList(list,0);
    //输出名称
    cout<< list.ListItem[0].name;
    
    return 0;
}

