#include <iostream>
using namespace std;
struct jiedian
{
    int data;
    jiedian *next;
};

struct biao
{
    jiedian header;
    int num;
    jiedian *rear;
};

void chushihua(biao *list);                   // 初始化
void charu(biao *list, jiedian *prev, int v); // 插入逻辑
void toucha(biao *list, int v);               // 头插
void weicha(biao *list, int v);               // 尾插
void shanchu(biao *list, jiedian *prev);      // 删除逻辑
int shanyi(biao *list, int v);                // 删除指定节点
void souyoushan(biao *list);                  // 删除所以节点
void bianli(const biao *list);                // 遍历

int main()
{
    biao list;
    chushihua(&list);
    for (int i = 0; i < 10; i++)
    {
        weicha(&list, i + 100);
    }
    bianli(&list);
    shanyi(&list, 109);
    bianli(&list);
    cout << list.num;
}

void chushihua(biao *list)
{
    list->header.next = &list->header;
    list->num = 0;
    list->rear = &list->header;
}

void charu(biao *list, jiedian *prev, int v)
{
    jiedian *node = new (jiedian);
    node->data = v;
    node->next = prev->next;
    prev->next = node;
    if (list->rear == prev)
    {
        list->rear = node;
    }
}

void toucha(biao *list, int v)
{
    jiedian *prev = &list->header;
    charu(list, prev, v);
    list->num++;
}

void weicha(biao *list, int v)
{
    jiedian *prev = list->rear;
    charu(list, prev, v);
    list->num++;
}

void shanchu(biao *list, jiedian *prev)
{
    if (prev == nullptr || prev->next == &list->header)
    {
        return;
    }
    jiedian *tmp = prev->next;
    prev->next = tmp->next;
    if (tmp == list->rear)
    {
        list->rear = prev;
    }
    delete (tmp);
    list->num--;
}
int shanyi(biao *list, int v)
{
    jiedian *prev = &list->header;
    while (prev->next != &list->header)
    {
        if (prev->next->data == v)
        {
            shanchu(list, prev);
            return 1;
        }
        prev = prev->next;
    }
    return 0;
}
void souyoushan(biao *list)
{
    jiedian *prev = &list->header;
    while (prev->next != &list->header)
    {
        shanchu(list, prev);
    }
    list->rear = &list->header;
}

void bianli(const biao *list)
{
    jiedian *prev = list->header.next;
    while (prev != &list->header)
    {
        cout << prev->data << " ";
        prev = prev->next;
    }
    cout << endl;
}