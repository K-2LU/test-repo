#include <iostream>
#include <fstream>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int l[], int low, int high)
{
  int piv = l[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
    if (l[j] <= piv)
    {
      i++;
      swap(&l[i], &l[j]);
    }
  swap(&l[i + 1], &l[high]);

  return i + 1;
}

void qsort(int l[], int low, int high)
{
  if (low < high)
  {
    int p = partition(l, low, high);

    qsort(l, low, p - 1);
    qsort(l, p + 1, high);
  }
}
// binary search
int binarysearch(int arr[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return binarysearch(arr, l, mid - 1, x);
    
    return binarysearch(arr, mid + 1, r, x);
  }
  return -1;
}

int main(int argc, char const *argv[])  {
    freopen("argv[1]", "r", stdin);
    freopen("argv[2]", "w", stdout);
    int n;
    std::cin >> n;
    int a[n], l[n];

    for (size_t i = 0; i < n; i++)  {
      std::cin >> a[i];
      l[i] = a[i];
    }

    qsort(l, 0, n - 1);

    for (int i = 0; i < n; i++)
      std::cout << binarysearch(l, 0, n - 1, a[i]) + 1 << ' ';
    std::cout << std::endl;

  return 0;
}