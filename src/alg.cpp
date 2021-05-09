// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
int count = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++)
{if (arr[i] + arr[j] == value) {
++count;
}
}
}
return count;
}
int countPairs2(int* arr, int len, int value) {
int count = 0, limit = -1;
for (int i = len; i > 0; --i)
{if (arr[i] > value && arr[i - 1] <= value) {
            limit = i;
            break;
}
}
if (limit != -1) {
for (int i = limit; i > 0; --i) {
for (int j = 0; j < i; ++j) {
if (arr[i] + arr[j] == value) {
++count;
}
}
}
}
return count;
}
int countPairs3(int* arr, int len, int value) {
int count = 0, left = 0, right = len - 1;
while ((right - 1) > left) {
int limit = (right + left) / 2;
if (value >= arr[limit])
left = limit;
else
right = limit;
}
len = right - 1;
for (int i = 0; i < len; i++) {
left = i + 1;
right = len - 1;
int res2 = 0;
while (right > left) {
int limit = (right + left) / 2;
if ((value - arr[i]) > arr[limit])
left = limit + 1;
else
right = limit;
}
while ((value - arr[i]) == arr[left]) {
res2++;
left++;
}
count = count + res2;
}
return  count;
}
