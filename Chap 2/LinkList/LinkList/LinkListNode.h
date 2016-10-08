#pragma once
template<class T> struct LinkListNode
{
	T data;
	LinkListNode<T> *next;
};