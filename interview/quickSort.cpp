/*
 * 快排的一种实现方式
 */

int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[high]);
    return i + 1;
}

void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int middle = partition(vec, low, high);
        //Watch out! The mid position is on the place, so we don't need to consider it again.
        //That's why below is mid-1, not mid! Otherwise it will occur overflow error!!!
        quickSort(vec, low, middle - 1);
        quickSort(vec, middle + 1, high);
    }
}
