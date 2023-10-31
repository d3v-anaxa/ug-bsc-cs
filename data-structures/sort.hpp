#include <iostream>
#include <bits/stdc++.h>

#ifndef _SORT_
#define _SORT_

typedef int T;

void bubble_sort(T* arr, int size);
void selection_sort(T* arr, int size);
void insertion_sort(T* arr, int size);
void shell_sort(T* arr, int size);
void merge_sort(T* arr, int size);
void quick_sort(T* arr, int size);
void radix_sort(T* arr, int size);
void bucket_sort(T* arr, int size);

#include "sort.cpp"

#endif
