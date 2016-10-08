#pragma once
#include "LinkListNode.h"
using namespace std;
template<class T> class LinkList
{
public:
	LinkList();
	LinkList(LinkList<T>& l);  //���ƹ��캯��
	~LinkList();
	int Size() const { return this->size; }
	void Clear();
	bool InsertBefore(int pos, const T& e);  //��λ��pos֮ǰ����Ԫ��e
	bool Delete(int pos, T& e);  //ɾ��λ��pos�ϵ�Ԫ�أ����ɵڶ�����������ɾ����Ԫ��ֵ
	void Traverse(void(*visit)(T&));  //����
	const LinkList<T>& operator=(const LinkList<T>& l);  //���صȺ�
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
