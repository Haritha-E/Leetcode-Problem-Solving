class Solution {
public:
    bool check(vector<int>& ranks, long long mid, int cars) {
        long long count = 0;
        for (int r : ranks) {
            count += sqrt((long long)mid / r);
        }
        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1, end = 1e14;

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (check(ranks, mid, cars)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            };
        }
        return start;
    }
};