/*  快速排序  */
void quick_sort(int q[], int l, int r)
{
    if (l >= r) {
        return;
    }
    int i = l - 1, j = r + 1, pivot = q[l + r >> 1];
    while (i < j) {
        while (q[++i] < pivot);
        while (q[--j] > pivot);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}


/*  查找数组第K大数  */
int findKth(int l, int r, int k)
{
    if (l >= r) {
        return q[l];
    }
    int i = l - 1, j = r + 1, pivot = q[l + r >> 1];
    while (i < j) {
        while (q[++i] > pivot);
        while (q[--j] < pivot);
        if (i < j) {
            swap(q[i], q[j]);
        }
    }
    int sl = j - l + 1;
    if (sl >= k) {
        return findKth(l, j, k);
    }
    return findKth(j + 1, r, k - sl);
}


/*  归并排序  */
void merge_sort(int q[], int l, int r)
{
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (j > r || i <= mid && q[i] <= q[j]) {
            tmp[k] = q[i++];
        } else {
            tmp[k] = q[j++];
        }
    }
    for (int k = l; k <= r; k++) {
        q[k] = tmp[k];
    }
}


/*  归并排序求逆序对  */
int inversion_pair(int q[], int l, int r)
{
    if (l == r) {
        return 0;
    }

    int mid = l + r >> 1;
    int ans = inversion_pair(q, l, mid) + inversion_pair(q, mid + 1, r);

    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (j > r || i <= mid && q[i] <= q[j]) {
            tmp[k] = q[i++];
        } else  {
            tmp[k] = q[j++];
            ans += mid - i + 1;
        }
    }
    for (int k = l; k <= r; ++k) {
        q[k] = tmp[k];
    }

    return ans;
}