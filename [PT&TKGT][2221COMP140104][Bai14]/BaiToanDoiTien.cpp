#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // Khởi tạo một mảng dp có kích thước (amount + 1) với giá trị ban đầu là INT_MAX - 1
    vector<int> dp(amount + 1, INT_MAX - 1);

    // Giá trị dp[0] = 0, không cần đồng xu để đổi số tiền 0
    dp[0] = 0;

    // Duyệt qua các mệnh giá đồng xu
    for (int coin : coins) {
        // Duyệt qua từng số tiền từ mệnh giá đồng xu đến amount
        for (int i = coin; i <= amount; i++) {
            // Cập nhật giá trị tối ưu
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    // Kiểm tra xem có tồn tại giá trị tối ưu cho amount hay không
    if (dp[amount] == INT_MAX - 1) {
        return -1; // Trả về -1 nếu không tồn tại giá trị tối ưu
    } else {
        return dp[amount]; // Trả về giá trị tối ưu
    }
}

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the denominations of coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int minCoins = coinChange(coins, amount);

    cout << "Minimum number of coins required: " << minCoins << endl;

    return 0;
}
