#include <iostream>
#include <stdlib.h>
using namespace std;
// 我这里就不用typedef进行取别名了，变量用拼音来代替
// 定义节点
struct jiedian
{
    jiedian *next;
    int shuju;
};
// 定义表头
struct biaotou
{
    jiedian toujiedian;
    int geshu;
};
// 申明函数；
/*1.插入 头插，尾插，指定位置插*/
int charu(jiedian *prev, int v);              // 插入
void toucha(biaotou *list, int v);            // 头插
void weicha(biaotou *list, int v);            // 尾插
void renyicha(biaotou *list, int pos, int v); // 任意插入

/*2.删除*/
void shanchu(biaotou *list, int v);
void scluoji(jiedian *prev);
void shanbiao(biaotou *list);
/*3.遍历*/
void bianli(const biaotou *list);

int main()
{
    biaotou list;
    list.geshu = 0;
    list.toujiedian.next = nullptr;
    for (int i = 0; i < 5; i++)
    {
        weicha(&list, i + 101);
    }
    bianli(&list);
    renyicha(&list, 1, 10);
    bianli(&list);
    shanchu(&list, 10);
    bianli(&list);
    shanbiao(&list);
    return 0;
}

// 插入
int charu(jiedian *prev, int v)
{
    jiedian *xin = (jiedian *)malloc(sizeof(jiedian));
    if (xin == nullptr)
    {
        return 0;
    }
    xin->shuju = v;
    xin->next = prev->next;
    prev->next = xin;
    return 1;
}

// 头插
void toucha(biaotou *list, int v)
{
    jiedian *prev = &list->toujiedian;
    if (charu(prev, v))
    {
        list->geshu++;
    }
}

// 尾插
void weicha(biaotou *list, int v)
{
    jiedian *prev = &list->toujiedian;
    while (prev->next != nullptr)
    {
        prev = prev->next;
    }
    if (charu(prev, v))
    {
        list->geshu++;
    }
}

// 任意位置插入;
void renyicha(biaotou *list, int pos, int v)
{
    if (pos < 0 || pos > list->geshu)
    {
        return;
    }
    jiedian *prev = &list->toujiedian;
    int i = 0;
    while (i < pos)
    {
        prev = prev->next;
        i++;
    }
    if (charu(prev, v))
    {
        list->geshu++;
    }
}
// 删除
void shanchu(biaotou *list, int v)
{
    jiedian *prev = &list->toujiedian;
    while (prev->next != nullptr)
    {
        if (prev->next->shuju == v)
        {
            break;
        }
        prev = prev->next;
    }
    if (prev->next != nullptr)
    {
        scluoji(prev);
        list->geshu--;
    }
}
// 删除表
void shanbiao(biaotou *list)
{
    jiedian *prev = &list->toujiedian;
    while (prev->next != nullptr)
    {
        scluoji(prev);
        list->geshu--;
        cout << list->geshu;
        /* code */
    }
}

// 删除逻辑
void scluoji(jiedian *prev)
{
    jiedian *beifen = prev->next;
    prev->next = beifen->next;
    free(beifen);
}
//  遍历
void bianli(const biaotou *list)
{
    jiedian *prev = list->toujiedian.next;
    while (prev != nullptr)
    {
        cout << prev->shuju << " ";
        prev = prev->next;
    }
    cout << endl;
}
