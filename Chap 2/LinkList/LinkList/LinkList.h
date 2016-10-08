#pragma once
#include "LinkListNode.h"
using namespace std;
template<class T> class LinkList
{
public:
	LinkList();
	LinkList(LinkList<T>& l);  //复制构造函数
	~LinkList();
	int Size() const { return this->size; }
	void Clear();
	bool InsertBefore(int pos, const T& e);  //在位置pos之前插入元素e
	bool Delete(int pos, T& e);  //删除位置pos上的元素，并由第二个参数返回删除的元素值
	void Traverse(void(*visit)(T&));  //遍历
	const LinkList<T>& operator=(const LinkList<T>& l);  //重载等号
private:
	LinkListNode<T> *head;
	int size;
};

template<class T>
inline LinkList<T>::LinkList()
{
	this->size = 0;
	this->head = new LinkListNode<T>;
	this->head->next = NULL;
}

template<class T>
inline LinkList<T>::LinkList(LinkList<T>& l)
{
	this->size = 0;
	this->head = new LinkListNode<T>;
	LinkListNode<T> *p = l.head->next;
	LinkListNode<T> *r = this->head;
	while (p != NULL)
	{
		LinkListNode<T> *q = new LinkListNode<T>;
		q->data = p->data;
		q->next = NULL;
		r->next = q;
		r = r->next;
		p = p->next;
	}
}

template<class T>
inline LinkList<T>::~LinkList()
{
	this->Clear();
	delete this->head;
}

template<class T>
inline void LinkList<T>::Clear()
{
	while (this->head->next != NULL)
	{
		LinkListNode<T> *p = this->head->next;
		this->head->next = this->head->next->next;
		delete p;
	}
	this->size = 0;
}

template<class T>
inline bool LinkList<T>::InsertBefore(int pos, const T & e)
{
	if (pos <= 0 || pos > size + 1)
		return false;
	LinkListNode<T> *p = this->head;
	int j = 0;
	while (p && j < pos - 1)
	{
		p = p->next;
		++j;
	}
	if (!p)
	{
		return false;
	}
	LinkListNode<T> *s = new LinkListNode<T>;
	s->data = e;
	s->next = p->next;
	p->next = s;
	++this->size;
	return true;
}

template<class T>
inline bool LinkList<T>::Delete(int pos, T & e)
{
	if (pos <= 0 || pos > this->size)
		return false;
	LinkListNode<T> *p = this->head;
	int j = 0;
	while (p->next && j < pos - 1)
	{
		p = p->next;
		++j;
	}
	if (!p->next)
		return false;
	LinkListNode<T> *q = p->next;
	p->next = q->next;
	e = q->data;
	--this->size;
	delete q;
	return true;
}

template<class T>
inline void LinkList<T>::Traverse(void(*visit)(T&))
{
	LinkListNode<T> *p = this->head->next;
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}
}

template<class T>
inline const LinkList<T>& LinkList<T>::operator=(const LinkList<T>& l)
{
	this->Clear();
	LinkListNode<T> *p = l.head->next;
	LinkListNode<T> *r = this->head;
	while (p != NULL)
	{
		LinkListNode<T> *q = new LinkListNode<T>;
		q->data = p->data;
		q->next = NULL;
		r->next = q;
		r = r->next;
		p = p->next;
	}
	return l;
}
