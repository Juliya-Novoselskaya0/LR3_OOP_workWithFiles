#pragma once

#include <new>
#include <cassert> // ��� assert
#include <iostream>
#include <typeinfo>
#include <exception>
#include<string>
#include "Employee.h"
#include "StackErr.h"

using namespace std;
#include <iomanip> // ��� setw


template <typename T>
class Stack
{
public:
    T* stackPtr;                      // ��������� �� ����
     int size=10;                   // ������������ ���������� ��������� � �����
    int top;                          // ����� �������� �������� �����

    Stack(int maxSize) : size(maxSize)
    {
        try {
            stackPtr = new T[size]; // �������� ������ ��� ����
        }
        catch (bad_alloc ex)
        {
            cout << "Exeption " << ex.what();
            cout << "size= " << size << endl;
        }
        top = 0; // �������������� ������� ������� �����;
    }

    Stack() {
        top = 0;
        //stackPtr = NULL;
        stackPtr = new T[size];
    }
    Stack(T i) {
        top = 0;
        //stackPtr = NULL;
        stackPtr = new T[size];
        push(i);
    }

     int getTop() const
    {
        return top;
    }

    ~Stack()
    {
        delete[] stackPtr; // ������� ����
    }

   friend ostream& operator<<(ostream& out, Stack<T>& obj)
    {
        out << std::right << std::setw(22) << "full name" << std::right << std::setw(25) << "department number" << std::right << ::setw(20) << "position" << std::right << ::setw(22) << "start date of work" << endl;
        for (int ix = obj.top - 1; ix >= 0; ix--)
        {
            out << "|" << obj.stackPtr[ix] << endl;
        }
        return out;
    }

    void checkEmpty(int s)
    {
        char str[] = "The stack is empty!";
        if (s == 0)
            throw StackErr(str);
    }

    void checkSize(int s)
    {
        char str[] = "The stack is already full!";
        if (s == size)
            throw StackErr(str);
    }

    bool checkEnter(T e, char* S)
    {
        const char* temp = "0123456789-+";
        char str[] = "Invalid input!";
        for (int i = 0; i < strlen(S); i++) {
            if (!strchr(temp, S[i])) throw StackErr(str); return false;
        }
        return true;
    }

     void push(T elem)
    {
      //  std::cin >> elem;
        try {
            checkSize(getTop());
        }
        catch (StackErr ss)
        {
            cout << "Warning -  ";
            ss.show();
            return;
        }
        stackPtr[top++] = elem;// �������� ������� � ����
    }

     T pop()
    {
        try {
            checkEmpty(top);
        }
        catch (StackErr st)
        {
            cout << "Warning -  ";
            st.show();
            T t;
            return t;
        }
        return stackPtr[--top];  // ������� ������� �� �����
    }

     const T& search(int nom) const
    {
        for (int ix = top - 1; ix >= 0; ix--)
        {
            if (stackPtr[ix].getDepNum(stackPtr[ix]) == nom)
            {
                cout << "found" << endl;
                return stackPtr[ix];
                break;
            }
        }
        cout << "not found" << endl;
        T t;
        return t;
    }


    // ����� ����� �� �����
   
    void printStack()
    {
        std::cout << std::right << std::setw(22) << "full name" << std::right << std::setw(25) << "department number" << std::right << ::setw(20) << "position" << std::right << ::setw(22) << "start date of work" << endl;
        for (int ix = top - 1; ix >= 0; ix--)
            cout << "|" << stackPtr[ix] << endl;
    }


    //������� ��������� �� ���� (��� ������������ �����������)
    
     T*getPtr() const
    {
        return stackPtr;
    }

   
     void sortStack()
    {
        for (int i = 1; i < top; i++)
            for (int j = i; j > 0 && stackPtr[j - 1].getDepNum(stackPtr[j - 1]) < stackPtr[j].getDepNum(stackPtr[j]); j--) // ���� j>0 � ������� j-1 > j, x-������ int
                swap(stackPtr[j - 1], stackPtr[j]);
    }

   
     void sortStackB()
    {
        for (int i = 1; i < top; i++)
            for (int j = i; j > 0 && stackPtr[j - 1].getDepNum(stackPtr[j - 1]) > stackPtr[j].getDepNum(stackPtr[j]); j--) // ���� j>0 � ������� j-1 > j, x-������ int
                swap(stackPtr[j - 1], stackPtr[j]);
    }
};