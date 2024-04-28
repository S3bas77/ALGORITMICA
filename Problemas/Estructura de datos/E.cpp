#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> track1(n); // First track status
    std::vector<int> track2(n); // Second track status

    // Read track statuses
    for (int i = 0; i < n; i++) {
        std::cin >> track1[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> track2[i];
    }

    // Check if the direct route is open (from 1 to s on the first track)
    bool canReachDirect = true;
    for (int i = 0; i < s; i++) {
        if (track1[i] == 0) {
            canReachDirect = false;
            break;
        }
    }

    if (canReachDirect) {
        std::cout << "YES" << std::endl;
        return 0;
    }

    // If not, check if Bob can go to station n and then return to station s
    bool canReachLast = true;
    for (int i = 0; i < n; i++) {
        if (track1[i] == 0) {
            canReachLast = false;
            break;
        }
    }

    bool canReturn = true;
    for (int i = s - 1; i < n; i++) {
        if (track2[i] == 0) {
            canReturn = false;
            break;
        }
    }

    if (canReachLast && canReturn) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
