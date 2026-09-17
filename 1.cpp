#include <iostream>
#include <cstring>
using namespace std;
#include <stdlib.h>
struct biao
{
    int *data;
    int capacity;
    int len;
};
void chushihua(biao *list, int num);
void releace(biao *list);
void charu(biao *list, int val);
int kourong(biao *list);
void bianli(biao *list);
void renyicharu(biao *list, int bos, int val);
void shanchu(biao *list, int val);

// 初始化；
void chushihua(biao *list, int num)
{
    list->data = (int *)malloc(sizeof(int) * num);
    if (list->data == nullptr)
    {
        cout << "申请空间失败" << endl;
        return;
    }
    list->capacity = num;
    list->len = 0;
}
// 释放；
void releace(biao *list)
{

    if (list->data != nullptr)
    {
        free(list->data);
        list->capacity = 0;
        list->len = 0;
    }
    else
    {
        cout << "释放失败" << endl;
    }
}
// 插入（尾插）；
void charu(biao *list, int val)
{
    if (list->len >= list->capacity && kourong(list))
    {
        // 扩容;
        cout << "扩容失败" << endl;
        return;
    }
    list->data[list->len] = val;
    list->len++;
}

// 扩容
int kourong(biao *list)
{
    int *p = (int *)malloc(sizeof(int) * (list->capacity * 2));
    if (p == nullptr)
    {
        return 1;
    }
    for (int i = 0; i <= list->capacity; i++)
    {
        p[i] = list->data[i];
    }
    free(list->data);
    list->data = p;
    list->capacity *= 2;
    return 0;
}
// 遍历；
void bianli(biao *list)
{
    for (int i = 0; i < list->len; i++)
    {
        cout << list->data[i] << "  ";
    }
}

// 任意位置插入；
void renyicharu(biao *list, int bos, int val)
{
    if (bos < 0 || bos > list->len)
    {
        cout << "这个位置不可插入" << endl;
        return;
    }
    if (list->len >= list->capacity && kourong(list))
    {
        return;
    }
    for (int i = list->len; bos <= i; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[bos] = val;
    list->len++;
}
// 查找元素，返回索引;
int chazhao(const biao *list, int val)
{
    for (int i = 0; i < list->len; i++)
    {
        if (list->data[i] == val)
        {
            return i;
        }
    }
    return -1;
}
// 删除元素；
void shanchu(biao *list, int val)
{
    int bos = chazhao(list, val);
    if (bos == -1)
    {
        cout << "这个元素不存在" << endl;
        return;
    }
    for (int i = bos; i < list->len - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->len--;
}

int main()
{
    biao list;
    chushihua(&list, 5);
    for (int i = 1; i <= 5; i++)
    {
        charu(&list, i + 100);
    }
    renyicharu(&list, 5, 1);
    // shanchu(&list, 102);
    bianli(&list);

    return 0;
}