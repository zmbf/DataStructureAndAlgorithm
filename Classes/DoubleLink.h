//
//  DoubleLink.hpp
//  DataStructureAndAlgorithm
//
//  Created by xdlc on 2018/5/7.
//  Copyright © 2018年 zmbf. All rights reserved.
//
//双向链表
#ifndef DoubleLink_hpp
#define DoubleLink_hpp
//node 节点
template<class T>
class DoubleLink;

template<class T>
struct DNode
{
    friend class DoubleLink;
private:
    DNode() { };
    DNode(T t, DNode *prev, DNode *next) {
        this->value = t;
        this->prev  = prev;
        this->next  = next;
    };
private:
    T value;
    DNode *prev;
    DNode *next;
};
//链表
template<class T>
class DoubleLink
{
public:
    DoubleLink();
    virtual ~DoubleLink();
    const int & size();
    const bool is_empty();
    T get(const int & index);
    T get_first();
    T get_last();
    
    int insert(const int & index, const T & t);
    int insert_first(const T & t);
    int append_last(const T & t);
    
    int del(const int & index);
    int delete_first();
    int delete_last();
private:
    DNode<T> *get_node(const int & index);
private:
    unsigned int m_count; //节点数量
    DNode<T> *m_phead; //头结点
};
template<class T>
DoubleLink<T>::DoubleLink() : m_count(0){
    //创建表头
    m_phead = new DNode<T>();
    //头尾 都指向自己
    m_phead->prev = m_phead->next = m_phead;
}
template<class T>
DoubleLink<T>::~DoubleLink(){
    DNode<T>* ptmp;
    DNode<T>* pnode = m_phead->next;
    //删除所有节点
    while (pnode != m_phead){
        ptmp = pnode;
        pnode=pnode->next;
        delete ptmp;
    }
    delete m_phead;
    m_phead = nullptr;
}
template<class T>
const int & DoubleLink<T>::size(){
    return m_count;
}

template<class T>
const bool DoubleLink<T>::is_empty(){
    return m_count == 0;
}
template<class T>
DNode<T>* DoubleLink<T>::get_node(const int & index){
    // 判断参数有效性
    if (index<0 || index>=count)
    {
        return NULL;
    }
    // 正向查找
    if (index <= count/2)
    {
        int i=0;
        DNode<T>* pNode = phead->next;
        while (i++ < index) {
            pindex = pindex->next;
        }
        return pNode;
    }
    // 反向查找
    int j=0;
    int rindex = count - index -1;
    DNode<T>* pNode = phead->prev;
    while (j++ < rindex) {
        pNode = pNode->prev;
    }
    return pNode;
}
template<class T>
T DoubleLink<T>::get(const int & index){
    return get_node(index)->value;
}
template<class T>
T DoubleLink<T>::get_first(){
    return get_node(0)->value;
}
template<class T>
T DoubleLink<T>::get_last(){
    return get_node(count-1)->value;
}
template<class T>
int DoubleLink<T>::insert(int index, T t){
    if (index == 0)
        return insert_first(t);
    DNode<T>* pindex = get_node(index);
    DNode<T>* pnode  = new DNode<T>(t, pindex->prev, pindex);
    pindex->prev->next = pnode;
    pindex->prev = pnode;
    count++;
    return 0;
}

#endif /* DoubleLink_hpp */











